/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpioimpl.h"

/* P1: Directed Sync -- MPI_File_sync_to and MPI_File_sync_from
 *
 * These primitives implement the C1 (process-pair) consistency level from the
 * formal MPI-IO consistency model.  A matched pair establishes a directed
 * synchronizes-with (sw_pair) edge from the writer to the reader without
 * requiring a global barrier over all processes that opened the file.
 *
 * Semantics (from the formal model):
 *   MPI_File_sync_to(fh, q, comm)  by p, paired with
 *   MPI_File_sync_from(fh, p, comm) by q
 * establishes:  s_to^p  --sw_pair-->  s_from^q
 * so that every write by p before sync_to happens-before every read by q
 * after sync_from.
 *
 * Implementation:
 *   sync_to:   ADIO_Flush (fsync to storage)  then  MPI_Send(token to q)
 *   sync_from: MPI_Recv(token from p)          then  ADIO_Flush (no-op if no
 *              dirty writes, but invalidates any internal read buffers)
 *
 * Tag: ADIOI_SYNC_TO_TAG is a private constant used only for these messages.
 * In a production implementation this should be allocated from MPICH's
 * internal tag pool; for this prototype a fixed value is used.
 */

#ifdef HAVE_WEAK_SYMBOLS

#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync_to = PMPI_File_sync_to
#pragma weak MPI_File_sync_from = PMPI_File_sync_from
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync_to MPI_File_sync_to
#pragma _HP_SECONDARY_DEF PMPI_File_sync_from MPI_File_sync_from
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync_to as PMPI_File_sync_to
#pragma _CRI duplicate MPI_File_sync_from as PMPI_File_sync_from
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync_to(MPI_File fh, int target_rank, MPI_Comm comm)
    __attribute__ ((weak, alias("PMPI_File_sync_to")));
int MPI_File_sync_from(MPI_File fh, int source_rank, MPI_Comm comm)
    __attribute__ ((weak, alias("PMPI_File_sync_from")));
#endif

/* Include mapping from MPI->PMPI */
#define MPIO_BUILD_PROFILING
#include "mpioprof.h"
#endif

/*@
    MPI_File_sync_to - Flush writes to storage and signal a target process
                       (directed sync, writer/producer side)

Input Parameters:
. fh          - file handle (handle)
. target_rank - rank of the consumer process in comm (integer)
. comm        - communicator shared with the consumer (handle)

Notes:
  Must be called collectively with a matching MPI_File_sync_from by the
  process at target_rank.  After the matching sync_from returns, all writes
  issued by this process before MPI_File_sync_to are guaranteed visible to
  reads issued by the target after MPI_File_sync_from.

.N fortran
@*/
int MPI_File_sync_to(MPI_File fh, int target_rank, MPI_Comm comm)
{
    int error_code;
    ROMIO_THREAD_CS_ENTER();

    error_code = MPIR_File_sync_to_impl(fh, target_rank, comm);
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
    MPI_File_sync_from - Wait for a source process's flush and refresh local
                         buffers (directed sync, reader/consumer side)

Input Parameters:
. fh          - file handle (handle)
. source_rank - rank of the producer process in comm (integer)
. comm        - communicator shared with the producer (handle)

Notes:
  Must be called collectively with a matching MPI_File_sync_to by the
  process at source_rank.  After this call returns, reads issued by this
  process are guaranteed to see all writes issued by source_rank before
  its matching MPI_File_sync_to.

.N fortran
@*/
int MPI_File_sync_from(MPI_File fh, int source_rank, MPI_Comm comm)
{
    int error_code;
    ROMIO_THREAD_CS_ENTER();

    error_code = MPIR_File_sync_from_impl(fh, source_rank, comm);
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
