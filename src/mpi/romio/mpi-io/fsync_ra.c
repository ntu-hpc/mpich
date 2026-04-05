/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpioimpl.h"

/* P3: Release-Acquire Sync -- MPI_File_release and MPI_File_acquire
 *
 * Implements asymmetric C2 consistency between a writer group and a reader
 * group.  Unlike P2 (group sync), no synchronization is established among
 * writers or among readers -- only directed edges from each writer to each
 * reader are created.
 *
 * Semantics (from the formal model):
 *   For all p ∈ writers, for all p' ∈ readers:
 *     release^p  --sw_ra-->  acquire^{p'}
 * so that every write by any p ∈ writers before MPI_File_release is visible
 * to reads by any p' ∈ readers after MPI_File_acquire.
 *
 * Implementation:
 *   release (each writer p):
 *     1. ADIO_Flush  -- flush dirty writes to storage
 *     2. MPI_Isend(token) to every reader, then MPI_Waitall
 *        The sends carry the sw_ra edges to the readers.
 *
 *   acquire (each reader p'):
 *     1. MPI_Irecv(token) from every writer, then MPI_Waitall
 *        After Waitall, all writers' flushes have completed.
 *     2. ADIO_Flush  -- reset ROMIO's internal state before reads
 *
 * Rank translation: the writers and readers groups are subgroups of
 * adio_fh->comm.  Ranks are translated to adio_fh->comm rank space
 * via MPI_Group_translate_ranks so that all messages use the file
 * communicator.
 *
 * This mirrors the semantics of MPI RMA's passive-target
 * MPI_Win_post/start/complete/wait interface, adapted to MPI-IO.
 */

#ifdef HAVE_WEAK_SYMBOLS

#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_release = PMPI_File_release
#pragma weak MPI_File_acquire = PMPI_File_acquire
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_release MPI_File_release
#pragma _HP_SECONDARY_DEF PMPI_File_acquire MPI_File_acquire
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_release as PMPI_File_release
#pragma _CRI duplicate MPI_File_acquire as PMPI_File_acquire
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_release(MPI_File fh, MPI_Group writers, MPI_Group readers)
    __attribute__ ((weak, alias("PMPI_File_release")));
int MPI_File_acquire(MPI_File fh, MPI_Group writers, MPI_Group readers)
    __attribute__ ((weak, alias("PMPI_File_acquire")));
#endif

/* Include mapping from MPI->PMPI */
#define MPIO_BUILD_PROFILING
#include "mpioprof.h"
#endif

/*@
    MPI_File_release - Flush writes to storage and signal all readers
                       (release-acquire sync, writer side)

Input Parameters:
. fh      - file handle (handle)
. writers - group of writer processes; must include the calling process (handle)
. readers - group of reader processes to notify (handle)

Notes:
  Called by each process in writers after its write phase.  Must be paired
  with MPI_File_acquire called by each process in readers.  After all readers'
  MPI_File_acquire calls return, all writes issued by any writer before its
  MPI_File_release are visible to reads issued by any reader after its
  MPI_File_acquire.  No synchronization is established among writers or
  among readers.

.N fortran
@*/
int MPI_File_release(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    int error_code;
    ROMIO_THREAD_CS_ENTER();

    error_code = MPIR_File_release_impl(fh, writers, readers);
    if (error_code) {
        goto fn_fail;
    }

  fn_exit:
    ROMIO_THREAD_CS_EXIT();
    return error_code;
  fn_fail:
    error_code = MPIO_Err_return_file(fh, error_code);
    goto fn_exit;
}

/*@
    MPI_File_acquire - Wait for all writers' flushes and refresh local state
                       (release-acquire sync, reader side)

Input Parameters:
. fh      - file handle (handle)
. writers - group of writer processes to wait for (handle)
. readers - group of reader processes; must include the calling process (handle)

Notes:
  Called by each process in readers before its read phase.  Must be paired
  with MPI_File_release called by each process in writers.  After this call
  returns, all writes issued by any writer before its MPI_File_release are
  visible to reads issued by this process.

.N fortran
@*/
int MPI_File_acquire(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    int error_code;
    ROMIO_THREAD_CS_ENTER();

    error_code = MPIR_File_acquire_impl(fh, writers, readers);
    if (error_code) {
        goto fn_fail;
    }

  fn_exit:
    ROMIO_THREAD_CS_EXIT();
    return error_code;
  fn_fail:
    error_code = MPIO_Err_return_file(fh, error_code);
    goto fn_exit;
}
