/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpioimpl.h"

/* P2: Group Sync -- MPI_File_sync_group
 *
 * Implements the C2 (group consistency) level for an arbitrary subgroup
 * G ⊆ C of the communicator that opened the file.  All processes in G call
 * this function collectively; no synchronization is required with processes
 * outside G.
 *
 * Semantics (from the formal model):
 *   For all p, p' ∈ G, p ≠ p':
 *     s_grp^p  --sw_G-->  s_grp^{p'}
 * so that every write by any p ∈ G before the call is visible to every read
 * by any p' ∈ G after the call returns.
 *
 * Implementation: the sync-barrier-sync idiom restricted to G.
 *   1. ADIO_Flush  -- flush this process's dirty writes to storage
 *   2. MPI_Barrier(subcomm)  -- all-pairs synchronization within G
 *   3. ADIO_Flush  -- now that all peers have flushed, pull their data into
 *                     visibility (resets dirty_write; no-op if nothing to do)
 *
 * The subcomm is created with MPI_Comm_create_group so that only processes
 * in G participate -- processes outside G are not disturbed.
 */

#ifdef HAVE_WEAK_SYMBOLS

#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync_group = PMPI_File_sync_group
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync_group MPI_File_sync_group
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync_group as PMPI_File_sync_group
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync_group(MPI_File fh, MPI_Group group)
    __attribute__ ((weak, alias("PMPI_File_sync_group")));
#endif

/* Include mapping from MPI->PMPI */
#define MPIO_BUILD_PROFILING
#include "mpioprof.h"
#endif

/*@
    MPI_File_sync_group - Flush writes to storage and synchronize with all
                          processes in a subgroup (group consistency, C2 level)

Input Parameters:
. fh    - file handle (handle)
. group - group of processes that participate in this sync (handle);
          must be a subgroup of the communicator used to open fh

Notes:
  All processes in group must call this function collectively.  After the
  call returns on all processes in group, every write issued by any process
  in group before the call is visible to reads issued by any process in group
  after the call.  Processes not in group are not involved and are not blocked.

.N fortran
@*/
int MPI_File_sync_group(MPI_File fh, MPI_Group group)
{
    int error_code;
    ROMIO_THREAD_CS_ENTER();

    error_code = MPIR_File_sync_group_impl(fh, group);
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
