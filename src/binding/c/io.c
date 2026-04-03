/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* -- THIS FILE IS AUTO-GENERATED -- */

#include "mpiimpl.h"
#include "mpir_io_impl.h"

/* -- Begin Profiling Symbol Block for routine MPI_File_c2f */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_c2f = PMPI_File_c2f
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_c2f  MPI_File_c2f
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_c2f as PMPI_File_c2f
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_Fint MPI_File_c2f(MPI_File file)  __attribute__ ((weak, alias("PMPI_File_c2f")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_c2f
#define MPI_File_c2f PMPI_File_c2f
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_Fint internal_File_c2f(MPI_File file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return MPIR_File_c2f_impl(file);
#endif
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_Fint QMPI_File_c2f(QMPI_Context context, int tool_id, MPI_File file)
{
    return internal_File_c2f(file);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_Fint MPI_File_c2f(MPI_File file)
{
    QMPI_Context context;
    QMPI_File_c2f_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_c2f(context, 0, file);

    fn_ptr = (QMPI_File_c2f_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_C2F_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_C2F_T], file);
}
#else /* ENABLE_QMPI */
MPI_Fint MPI_File_c2f(MPI_File file)
{
    return internal_File_c2f(file);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_close */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_close = PMPI_File_close
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_close  MPI_File_close
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_close as PMPI_File_close
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_close(MPI_File *fh)  __attribute__ ((weak, alias("PMPI_File_close")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_close
#define MPI_File_close PMPI_File_close
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_close(MPI_File *fh)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_close_impl(fh);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_close", "**mpi_file_close %p", fh);
#endif
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_close(QMPI_Context context, int tool_id, MPI_File *fh)
{
    return internal_File_close(fh);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_close(MPI_File *fh)
{
    QMPI_Context context;
    QMPI_File_close_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_close(context, 0, fh);

    fn_ptr = (QMPI_File_close_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_CLOSE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_CLOSE_T], fh);
}
#else /* ENABLE_QMPI */
int MPI_File_close(MPI_File *fh)
{
    return internal_File_close(fh);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_delete */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_delete = PMPI_File_delete
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_delete  MPI_File_delete
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_delete as PMPI_File_delete
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_delete(const char *filename, MPI_Info info)
     __attribute__ ((weak, alias("PMPI_File_delete")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_delete
#define MPI_File_delete PMPI_File_delete
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_delete(const char *filename, MPI_Info info)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(filename, "filename", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_delete_impl(filename, info);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_delete", "**mpi_file_delete %s %I", filename, info);
#endif
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_delete(QMPI_Context context, int tool_id, const char *filename, MPI_Info info)
{
    return internal_File_delete(filename, info);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_delete(const char *filename, MPI_Info info)
{
    QMPI_Context context;
    QMPI_File_delete_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_delete(context, 0, filename, info);

    fn_ptr = (QMPI_File_delete_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_DELETE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_DELETE_T], filename, info);
}
#else /* ENABLE_QMPI */
int MPI_File_delete(const char *filename, MPI_Info info)
{
    return internal_File_delete(filename, info);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_f2c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_f2c = PMPI_File_f2c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_f2c  MPI_File_f2c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_f2c as PMPI_File_f2c
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_File MPI_File_f2c(MPI_Fint file)  __attribute__ ((weak, alias("PMPI_File_f2c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_f2c
#define MPI_File_f2c PMPI_File_f2c
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_File internal_File_f2c(MPI_Fint file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return MPIR_File_f2c_impl(file);
#endif
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_File QMPI_File_f2c(QMPI_Context context, int tool_id, MPI_Fint file)
{
    return internal_File_f2c(file);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_File MPI_File_f2c(MPI_Fint file)
{
    QMPI_Context context;
    QMPI_File_f2c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_f2c(context, 0, file);

    fn_ptr = (QMPI_File_f2c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_F2C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_F2C_T], file);
}
#else /* ENABLE_QMPI */
MPI_File MPI_File_f2c(MPI_Fint file)
{
    return internal_File_f2c(file);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_amode */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_amode = PMPI_File_get_amode
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_amode  MPI_File_get_amode
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_amode as PMPI_File_get_amode
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_amode(MPI_File fh, int *amode)
     __attribute__ ((weak, alias("PMPI_File_get_amode")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_amode
#define MPI_File_get_amode PMPI_File_get_amode
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_amode(MPI_File fh, int *amode)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(amode, "amode", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_amode_impl(fh, amode);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_amode", "**mpi_file_get_amode %F %p", fh, amode);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_amode(QMPI_Context context, int tool_id, MPI_File fh, int *amode)
{
    return internal_File_get_amode(fh, amode);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_amode(MPI_File fh, int *amode)
{
    QMPI_Context context;
    QMPI_File_get_amode_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_amode(context, 0, fh, amode);

    fn_ptr = (QMPI_File_get_amode_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_AMODE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_AMODE_T], fh, amode);
}
#else /* ENABLE_QMPI */
int MPI_File_get_amode(MPI_File fh, int *amode)
{
    return internal_File_get_amode(fh, amode);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_atomicity */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_atomicity = PMPI_File_get_atomicity
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_atomicity  MPI_File_get_atomicity
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_atomicity as PMPI_File_get_atomicity
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_atomicity(MPI_File fh, int *flag)
     __attribute__ ((weak, alias("PMPI_File_get_atomicity")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_atomicity
#define MPI_File_get_atomicity PMPI_File_get_atomicity
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_atomicity(MPI_File fh, int *flag)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(flag, "flag", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_atomicity_impl(fh, flag);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_atomicity", "**mpi_file_get_atomicity %F %p", fh,
                                     flag);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_atomicity(QMPI_Context context, int tool_id, MPI_File fh, int *flag)
{
    return internal_File_get_atomicity(fh, flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_atomicity(MPI_File fh, int *flag)
{
    QMPI_Context context;
    QMPI_File_get_atomicity_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_atomicity(context, 0, fh, flag);

    fn_ptr = (QMPI_File_get_atomicity_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_ATOMICITY_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_ATOMICITY_T], fh, flag);
}
#else /* ENABLE_QMPI */
int MPI_File_get_atomicity(MPI_File fh, int *flag)
{
    return internal_File_get_atomicity(fh, flag);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_byte_offset */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_byte_offset = PMPI_File_get_byte_offset
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_byte_offset  MPI_File_get_byte_offset
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_byte_offset as PMPI_File_get_byte_offset
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
     __attribute__ ((weak, alias("PMPI_File_get_byte_offset")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_byte_offset
#define MPI_File_get_byte_offset PMPI_File_get_byte_offset
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(disp, "disp", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_byte_offset_impl(fh, offset, disp);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_byte_offset",
                                     "**mpi_file_get_byte_offset %F %L %p", fh, (long long) offset,
                                     disp);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_byte_offset(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                              MPI_Offset *disp)
{
    return internal_File_get_byte_offset(fh, offset, disp);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
    QMPI_Context context;
    QMPI_File_get_byte_offset_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_byte_offset(context, 0, fh, offset, disp);

    fn_ptr = (QMPI_File_get_byte_offset_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_BYTE_OFFSET_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_BYTE_OFFSET_T], fh, offset,
            disp);
}
#else /* ENABLE_QMPI */
int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp)
{
    return internal_File_get_byte_offset(fh, offset, disp);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_group */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_group = PMPI_File_get_group
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_group  MPI_File_get_group
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_group as PMPI_File_get_group
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_group(MPI_File fh, MPI_Group *group)
     __attribute__ ((weak, alias("PMPI_File_get_group")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_group
#define MPI_File_get_group PMPI_File_get_group
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_group(MPI_File fh, MPI_Group *group)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(group, "group", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_group_impl(fh, group);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_group", "**mpi_file_get_group %F %p", fh, group);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_group(QMPI_Context context, int tool_id, MPI_File fh, MPI_Group *group)
{
    return internal_File_get_group(fh, group);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_group(MPI_File fh, MPI_Group *group)
{
    QMPI_Context context;
    QMPI_File_get_group_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_group(context, 0, fh, group);

    fn_ptr = (QMPI_File_get_group_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_GROUP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_GROUP_T], fh, group);
}
#else /* ENABLE_QMPI */
int MPI_File_get_group(MPI_File fh, MPI_Group *group)
{
    return internal_File_get_group(fh, group);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_info = PMPI_File_get_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_info  MPI_File_get_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_info as PMPI_File_get_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
     __attribute__ ((weak, alias("PMPI_File_get_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_info
#define MPI_File_get_info PMPI_File_get_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_info(MPI_File fh, MPI_Info *info_used)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(info_used, "info_used", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_info_impl(fh, info_used);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_info", "**mpi_file_get_info %F %p", fh,
                                     info_used);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_info(QMPI_Context context, int tool_id, MPI_File fh, MPI_Info *info_used)
{
    return internal_File_get_info(fh, info_used);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
{
    QMPI_Context context;
    QMPI_File_get_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_info(context, 0, fh, info_used);

    fn_ptr = (QMPI_File_get_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_INFO_T], fh, info_used);
}
#else /* ENABLE_QMPI */
int MPI_File_get_info(MPI_File fh, MPI_Info *info_used)
{
    return internal_File_get_info(fh, info_used);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_position */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_position = PMPI_File_get_position
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_position  MPI_File_get_position
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_position as PMPI_File_get_position
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
     __attribute__ ((weak, alias("PMPI_File_get_position")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_position
#define MPI_File_get_position PMPI_File_get_position
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_position(MPI_File fh, MPI_Offset *offset)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(offset, "offset", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_position_impl(fh, offset);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_position", "**mpi_file_get_position %F %p", fh,
                                     offset);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_position(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset *offset)
{
    return internal_File_get_position(fh, offset);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
{
    QMPI_Context context;
    QMPI_File_get_position_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_position(context, 0, fh, offset);

    fn_ptr = (QMPI_File_get_position_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_POSITION_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_POSITION_T], fh, offset);
}
#else /* ENABLE_QMPI */
int MPI_File_get_position(MPI_File fh, MPI_Offset *offset)
{
    return internal_File_get_position(fh, offset);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_position_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_position_shared = PMPI_File_get_position_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_position_shared  MPI_File_get_position_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_position_shared as PMPI_File_get_position_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
     __attribute__ ((weak, alias("PMPI_File_get_position_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_position_shared
#define MPI_File_get_position_shared PMPI_File_get_position_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(offset, "offset", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_position_shared_impl(fh, offset);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_position_shared",
                                     "**mpi_file_get_position_shared %F %p", fh, offset);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_position_shared(QMPI_Context context, int tool_id, MPI_File fh,
                                  MPI_Offset *offset)
{
    return internal_File_get_position_shared(fh, offset);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
    QMPI_Context context;
    QMPI_File_get_position_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_position_shared(context, 0, fh, offset);

    fn_ptr = (QMPI_File_get_position_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_POSITION_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_POSITION_SHARED_T], fh,
            offset);
}
#else /* ENABLE_QMPI */
int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset)
{
    return internal_File_get_position_shared(fh, offset);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_size */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_size = PMPI_File_get_size
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_size  MPI_File_get_size
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_size as PMPI_File_get_size
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_size(MPI_File fh, MPI_Offset *size)
     __attribute__ ((weak, alias("PMPI_File_get_size")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_size
#define MPI_File_get_size PMPI_File_get_size
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_size(MPI_File fh, MPI_Offset *size)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(size, "size", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_size_impl(fh, size);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_size", "**mpi_file_get_size %F %p", fh, size);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_size(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset *size)
{
    return internal_File_get_size(fh, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_size(MPI_File fh, MPI_Offset *size)
{
    QMPI_Context context;
    QMPI_File_get_size_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_size(context, 0, fh, size);

    fn_ptr = (QMPI_File_get_size_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_SIZE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_SIZE_T], fh, size);
}
#else /* ENABLE_QMPI */
int MPI_File_get_size(MPI_File fh, MPI_Offset *size)
{
    return internal_File_get_size(fh, size);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_type_extent */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_type_extent = PMPI_File_get_type_extent
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_type_extent  MPI_File_get_type_extent
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_type_extent as PMPI_File_get_type_extent
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
     __attribute__ ((weak, alias("PMPI_File_get_type_extent")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_type_extent
#define MPI_File_get_type_extent PMPI_File_get_type_extent
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(extent, "extent", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_type_extent_impl(fh, datatype, extent);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_type_extent",
                                     "**mpi_file_get_type_extent %F %D %p", fh, datatype, extent);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_type_extent(QMPI_Context context, int tool_id, MPI_File fh, MPI_Datatype datatype,
                              MPI_Aint *extent)
{
    return internal_File_get_type_extent(fh, datatype, extent);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
    QMPI_Context context;
    QMPI_File_get_type_extent_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_type_extent(context, 0, fh, datatype, extent);

    fn_ptr = (QMPI_File_get_type_extent_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_TYPE_EXTENT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_TYPE_EXTENT_T], fh, datatype,
            extent);
}
#else /* ENABLE_QMPI */
int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype, MPI_Aint *extent)
{
    return internal_File_get_type_extent(fh, datatype, extent);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_type_extent_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_type_extent_c = PMPI_File_get_type_extent_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_type_extent_c  MPI_File_get_type_extent_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_type_extent_c as PMPI_File_get_type_extent_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent)
     __attribute__ ((weak, alias("PMPI_File_get_type_extent_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_type_extent_c
#define MPI_File_get_type_extent_c PMPI_File_get_type_extent_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(datatype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(extent, "extent", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_get_type_extent_impl(fh, datatype, (MPI_Aint *) extent);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        MPI_Aint extent_c;
        mpi_errno = MPIR_File_get_type_extent_impl(fh, datatype, &extent_c);
        if (mpi_errno) {
            goto fn_fail;
        }
        *extent = extent_c;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_type_extent_c",
                                     "**mpi_file_get_type_extent_c %F %D %p", fh, datatype, extent);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_type_extent_c(QMPI_Context context, int tool_id, MPI_File fh,
                                MPI_Datatype datatype, MPI_Count *extent)
{
    return internal_File_get_type_extent_c(fh, datatype, extent);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent)
{
    QMPI_Context context;
    QMPI_File_get_type_extent_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_type_extent_c(context, 0, fh, datatype, extent);

    fn_ptr = (QMPI_File_get_type_extent_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_TYPE_EXTENT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_TYPE_EXTENT_C_T], fh, datatype,
            extent);
}
#else /* ENABLE_QMPI */
int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype, MPI_Count *extent)
{
    return internal_File_get_type_extent_c(fh, datatype, extent);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_get_view */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_get_view = PMPI_File_get_view
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_get_view  MPI_File_get_view
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_get_view as PMPI_File_get_view
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype,
                      char *datarep)  __attribute__ ((weak, alias("PMPI_File_get_view")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_get_view
#define MPI_File_get_view PMPI_File_get_view
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype,
                                  MPI_Datatype *filetype, char *datarep)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(disp, "disp", mpi_errno);
            MPIR_ERRTEST_ARGNULL(etype, "etype", mpi_errno);
            MPIR_ERRTEST_ARGNULL(filetype, "filetype", mpi_errno);
            MPIR_ERRTEST_ARGNULL(datarep, "datarep", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_get_view_impl(fh, disp, etype, filetype, datarep);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_get_view", "**mpi_file_get_view %F %p %p %p %p", fh,
                                     disp, etype, filetype, datarep);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_get_view(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset *disp,
                       MPI_Datatype *etype, MPI_Datatype *filetype, char *datarep)
{
    return internal_File_get_view(fh, disp, etype, filetype, datarep);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype,
                      char *datarep)
{
    QMPI_Context context;
    QMPI_File_get_view_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_get_view(context, 0, fh, disp, etype, filetype, datarep);

    fn_ptr = (QMPI_File_get_view_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_GET_VIEW_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_GET_VIEW_T], fh, disp, etype,
            filetype, datarep);
}
#else /* ENABLE_QMPI */
int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype, MPI_Datatype *filetype,
                      char *datarep)
{
    return internal_File_get_view(fh, disp, etype, filetype, datarep);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread = PMPI_File_iread
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread  MPI_File_iread
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread as PMPI_File_iread
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
     __attribute__ ((weak, alias("PMPI_File_iread")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread
#define MPI_File_iread PMPI_File_iread
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                               MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread", "**mpi_file_iread %F %p %d %D %p", fh, buf,
                                     count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                    MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_T], fh, buf, count, datatype,
            request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_c = PMPI_File_iread_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_c  MPI_File_iread_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_c as PMPI_File_iread_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iread_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_c
#define MPI_File_iread_c PMPI_File_iread_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                                 MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_c", "**mpi_file_iread_c %F %p %c %D %p", fh, buf,
                                     count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf, MPI_Count count,
                      MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_c(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_c(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_C_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Request *request)
{
    return internal_File_iread_c(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_all = PMPI_File_iread_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_all  MPI_File_iread_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_all as PMPI_File_iread_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iread_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_all
#define MPI_File_iread_all PMPI_File_iread_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                                   MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_all_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_all", "**mpi_file_iread_all %F %p %d %D %p", fh,
                                     buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_all(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                        MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_all(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_all(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_ALL_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Request *request)
{
    return internal_File_iread_all(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_all_c = PMPI_File_iread_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_all_c  MPI_File_iread_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_all_c as PMPI_File_iread_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Request *request)
                          __attribute__ ((weak, alias("PMPI_File_iread_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_all_c
#define MPI_File_iread_all_c PMPI_File_iread_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                                     MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_all_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_all_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_all_c", "**mpi_file_iread_all_c %F %p %c %D %p",
                                     fh, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_all_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                          MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_all_c(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_all_c(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_ALL_C_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Request *request)
{
    return internal_File_iread_all_c(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at = PMPI_File_iread_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at  MPI_File_iread_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at as PMPI_File_iread_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                      MPI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iread_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at
#define MPI_File_iread_at PMPI_File_iread_at
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_at_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_at", "**mpi_file_iread_at %F %L %p %d %D %p", fh,
                                     (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_at(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset, void *buf,
                       int count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_at(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                      MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_at_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_at(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_at_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_AT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_AT_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                      MPI_Request *request)
{
    return internal_File_iread_at(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at_c = PMPI_File_iread_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at_c  MPI_File_iread_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at_c as PMPI_File_iread_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Request *request)
                         __attribute__ ((weak, alias("PMPI_File_iread_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at_c
#define MPI_File_iread_at_c PMPI_File_iread_at_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                    MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_at_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_at_c", "**mpi_file_iread_at_c %F %L %p %c %D %p",
                                     fh, (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_at_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                         void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_at_c(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_at_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_at_c(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_at_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_AT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_AT_C_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_at_c(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at_all = PMPI_File_iread_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at_all  MPI_File_iread_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at_all as PMPI_File_iread_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request)
                           __attribute__ ((weak, alias("PMPI_File_iread_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at_all
#define MPI_File_iread_at_all PMPI_File_iread_at_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                                      MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_at_all_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_at_all",
                                     "**mpi_file_iread_at_all %F %L %p %d %D %p", fh,
                                     (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_at_all(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                           void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_at_all(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_at_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_at_all(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_at_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_AT_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_AT_ALL_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_at_all(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_at_all_c = PMPI_File_iread_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_at_all_c  MPI_File_iread_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_at_all_c as PMPI_File_iread_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Request *request)
                             __attribute__ ((weak, alias("PMPI_File_iread_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_at_all_c
#define MPI_File_iread_at_all_c PMPI_File_iread_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                        MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_at_all_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_at_all_c",
                                     "**mpi_file_iread_at_all_c %F %L %p %c %D %p", fh,
                                     (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_at_all_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                             void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Request *request)
{
    return internal_File_iread_at_all_c(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_at_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_at_all_c(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_at_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_AT_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_AT_ALL_C_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_at_all_c(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_shared = PMPI_File_iread_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_shared  MPI_File_iread_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_shared as PMPI_File_iread_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Request *request)
                           __attribute__ ((weak, alias("PMPI_File_iread_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_shared
#define MPI_File_iread_shared PMPI_File_iread_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                                      MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iread_shared_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_shared",
                                     "**mpi_file_iread_shared %F %p %d %D %p", fh, buf, count, datatype,
                                     request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_shared(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_shared(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_shared(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_SHARED_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    return internal_File_iread_shared(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iread_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iread_shared_c = PMPI_File_iread_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iread_shared_c  MPI_File_iread_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iread_shared_c as PMPI_File_iread_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Request *request)
                             __attribute__ ((weak, alias("PMPI_File_iread_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iread_shared_c
#define MPI_File_iread_shared_c PMPI_File_iread_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count,
                                        MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iread_shared_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iread_shared_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iread_shared_c",
                                     "**mpi_file_iread_shared_c %F %p %c %D %p", fh, buf, count,
                                     datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iread_shared_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iread_shared_c(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iread_shared_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iread_shared_c(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iread_shared_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IREAD_SHARED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IREAD_SHARED_C_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Request *request)
{
    return internal_File_iread_shared_c(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite = PMPI_File_iwrite
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite  MPI_File_iwrite
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite as PMPI_File_iwrite
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iwrite")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite
#define MPI_File_iwrite PMPI_File_iwrite
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                                MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite", "**mpi_file_iwrite %F %p %d %D %p", fh, buf,
                                     count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite(QMPI_Context context, int tool_id, MPI_File fh, const void *buf, int count,
                     MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request)
{
    return internal_File_iwrite(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_c = PMPI_File_iwrite_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_c  MPI_File_iwrite_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_c as PMPI_File_iwrite_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                      MPI_Request *request)  __attribute__ ((weak, alias("PMPI_File_iwrite_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_c
#define MPI_File_iwrite_c PMPI_File_iwrite_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count,
                                  MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_c", "**mpi_file_iwrite_c %F %p %c %D %p", fh,
                                     buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                       MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_c(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                      MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_c(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_C_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                      MPI_Request *request)
{
    return internal_File_iwrite_c(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_all = PMPI_File_iwrite_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_all  MPI_File_iwrite_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_all as PMPI_File_iwrite_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                        MPI_Request *request)
                         __attribute__ ((weak, alias("PMPI_File_iwrite_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_all
#define MPI_File_iwrite_all PMPI_File_iwrite_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                                    MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_all_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_all", "**mpi_file_iwrite_all %F %p %d %D %p",
                                     fh, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_all(QMPI_Context context, int tool_id, MPI_File fh, const void *buf, int count,
                         MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_all(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                        MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_all(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_ALL_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                        MPI_Request *request)
{
    return internal_File_iwrite_all(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_all_c = PMPI_File_iwrite_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_all_c  MPI_File_iwrite_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_all_c as PMPI_File_iwrite_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                          MPI_Request *request)
                           __attribute__ ((weak, alias("PMPI_File_iwrite_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_all_c
#define MPI_File_iwrite_all_c PMPI_File_iwrite_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count,
                                      MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_all_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_all_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_all_c",
                                     "**mpi_file_iwrite_all_c %F %p %c %D %p", fh, buf, count, datatype,
                                     request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_all_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                           MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_all_c(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_all_c(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_ALL_C_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    return internal_File_iwrite_all_c(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at = PMPI_File_iwrite_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at  MPI_File_iwrite_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at as PMPI_File_iwrite_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                       MPI_Datatype datatype, MPI_Request *request)
                        __attribute__ ((weak, alias("PMPI_File_iwrite_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at
#define MPI_File_iwrite_at PMPI_File_iwrite_at
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                   MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_at_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_at", "**mpi_file_iwrite_at %F %L %p %d %D %p",
                                     fh, (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_at(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                        const void *buf, int count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_at(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                       MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_at_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_at(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_at_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_AT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_AT_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                       MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_at(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at_c = PMPI_File_iwrite_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at_c  MPI_File_iwrite_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at_c as PMPI_File_iwrite_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Request *request)
                          __attribute__ ((weak, alias("PMPI_File_iwrite_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at_c
#define MPI_File_iwrite_at_c PMPI_File_iwrite_at_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                     MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_at_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_at_c",
                                     "**mpi_file_iwrite_at_c %F %L %p %c %D %p", fh, (long long) offset,
                                     buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_at_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                          const void *buf, MPI_Count count, MPI_Datatype datatype,
                          MPI_Request *request)
{
    return internal_File_iwrite_at_c(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_at_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_at_c(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_at_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_AT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_AT_C_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_at_c(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at_all = PMPI_File_iwrite_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at_all  MPI_File_iwrite_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at_all as PMPI_File_iwrite_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request)
                            __attribute__ ((weak, alias("PMPI_File_iwrite_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at_all
#define MPI_File_iwrite_at_all PMPI_File_iwrite_at_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                       MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_at_all_impl(fh, offset, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_at_all",
                                     "**mpi_file_iwrite_at_all %F %L %p %d %D %p", fh,
                                     (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_at_all(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                            const void *buf, int count, MPI_Datatype datatype,
                            MPI_Request *request)
{
    return internal_File_iwrite_at_all(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_at_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_at_all(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_at_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_AT_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_AT_ALL_T], fh, offset, buf,
            count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_at_all(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_at_all_c = PMPI_File_iwrite_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_at_all_c  MPI_File_iwrite_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_at_all_c as PMPI_File_iwrite_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Request *request)
                              __attribute__ ((weak, alias("PMPI_File_iwrite_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_at_all_c
#define MPI_File_iwrite_at_all_c PMPI_File_iwrite_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                         MPI_Count count, MPI_Datatype datatype,
                                         MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_at_all_impl(fh, offset, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_at_all_c",
                                     "**mpi_file_iwrite_at_all_c %F %L %p %c %D %p", fh,
                                     (long long) offset, buf, count, datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_at_all_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                              const void *buf, MPI_Count count, MPI_Datatype datatype,
                              MPI_Request *request)
{
    return internal_File_iwrite_at_all_c(fh, offset, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_at_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_at_all_c(context, 0, fh, offset, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_at_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_AT_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_AT_ALL_C_T], fh, offset,
            buf, count, datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_at_all_c(fh, offset, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_shared = PMPI_File_iwrite_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_shared  MPI_File_iwrite_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_shared as PMPI_File_iwrite_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Request *request)
                            __attribute__ ((weak, alias("PMPI_File_iwrite_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_shared
#define MPI_File_iwrite_shared PMPI_File_iwrite_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_shared(MPI_File fh, const void *buf, int count,
                                       MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_iwrite_shared_impl(fh, buf, count, datatype, request);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_shared",
                                     "**mpi_file_iwrite_shared %F %p %d %D %p", fh, buf, count,
                                     datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_shared(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                            int count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_shared(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_shared(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_SHARED_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Request *request)
{
    return internal_File_iwrite_shared(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_iwrite_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_iwrite_shared_c = PMPI_File_iwrite_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_iwrite_shared_c  MPI_File_iwrite_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_iwrite_shared_c as PMPI_File_iwrite_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Request *request)
                              __attribute__ ((weak, alias("PMPI_File_iwrite_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_iwrite_shared_c
#define MPI_File_iwrite_shared_c PMPI_File_iwrite_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count,
                                         MPI_Datatype datatype, MPI_Request *request)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            MPIR_ERRTEST_ARGNULL(request, "request", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_iwrite_shared_impl(fh, buf, (MPI_Aint) count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_iwrite_shared_impl(fh, buf, count, datatype, request);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_iwrite_shared_c",
                                     "**mpi_file_iwrite_shared_c %F %p %c %D %p", fh, buf, count,
                                     datatype, request);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_iwrite_shared_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                              MPI_Count count, MPI_Datatype datatype, MPI_Request *request)
{
    return internal_File_iwrite_shared_c(fh, buf, count, datatype, request);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Request *request)
{
    QMPI_Context context;
    QMPI_File_iwrite_shared_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_iwrite_shared_c(context, 0, fh, buf, count, datatype, request);

    fn_ptr = (QMPI_File_iwrite_shared_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_IWRITE_SHARED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_IWRITE_SHARED_C_T], fh, buf, count,
            datatype, request);
}
#else /* ENABLE_QMPI */
int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Request *request)
{
    return internal_File_iwrite_shared_c(fh, buf, count, datatype, request);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_open */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_open = PMPI_File_open
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_open  MPI_File_open
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_open as PMPI_File_open
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
     __attribute__ ((weak, alias("PMPI_File_open")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_open
#define MPI_File_open PMPI_File_open
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info,
                              MPI_File *fh)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(filename, "filename", mpi_errno);
            MPIR_ERRTEST_ARGNULL(fh, "fh", mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_open_impl(comm, filename, amode, info, fh);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_open", "**mpi_file_open %C %s %d %I %p", comm,
                                     filename, amode, info, fh);
#endif
    mpi_errno = MPIO_Err_return_file(MPI_FILE_NULL, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_open(QMPI_Context context, int tool_id, MPI_Comm comm, const char *filename,
                   int amode, MPI_Info info, MPI_File *fh)
{
    return internal_File_open(comm, filename, amode, info, fh);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
{
    QMPI_Context context;
    QMPI_File_open_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_open(context, 0, comm, filename, amode, info, fh);

    fn_ptr = (QMPI_File_open_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_OPEN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_OPEN_T], comm, filename, amode,
            info, fh);
}
#else /* ENABLE_QMPI */
int MPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh)
{
    return internal_File_open(comm, filename, amode, info, fh);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_preallocate */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_preallocate = PMPI_File_preallocate
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_preallocate  MPI_File_preallocate
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_preallocate as PMPI_File_preallocate
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
     __attribute__ ((weak, alias("PMPI_File_preallocate")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_preallocate
#define MPI_File_preallocate PMPI_File_preallocate
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_preallocate(MPI_File fh, MPI_Offset size)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_preallocate_impl(fh, size);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_preallocate", "**mpi_file_preallocate %F %L", fh,
                                     (long long) size);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_preallocate(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset size)
{
    return internal_File_preallocate(fh, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
    QMPI_Context context;
    QMPI_File_preallocate_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_preallocate(context, 0, fh, size);

    fn_ptr = (QMPI_File_preallocate_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_PREALLOCATE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_PREALLOCATE_T], fh, size);
}
#else /* ENABLE_QMPI */
int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
    return internal_File_preallocate(fh, size);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read = PMPI_File_read
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read  MPI_File_read
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read as PMPI_File_read
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read
#define MPI_File_read PMPI_File_read
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                              MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read", "**mpi_file_read %F %p %d %D %p", fh, buf,
                                     count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                   MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_T], fh, buf, count, datatype,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_c = PMPI_File_read_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_c  MPI_File_read_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_c as PMPI_File_read_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                    MPI_Status *status)  __attribute__ ((weak, alias("PMPI_File_read_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_c
#define MPI_File_read_c PMPI_File_read_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                                MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_c", "**mpi_file_read_c %F %p %c %D %p", fh, buf,
                                     count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf, MPI_Count count,
                     MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                    MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                    MPI_Status *status)
{
    return internal_File_read_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all = PMPI_File_read_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all  MPI_File_read_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all as PMPI_File_read_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all
#define MPI_File_read_all PMPI_File_read_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                                  MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_all_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_all", "**mpi_file_read_all %F %p %d %D %p", fh,
                                     buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_all(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                       MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_all(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_all(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ALL_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_all(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_c = PMPI_File_read_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_c  MPI_File_read_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_c as PMPI_File_read_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                        MPI_Status *status)  __attribute__ ((weak, alias("PMPI_File_read_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_c
#define MPI_File_read_all_c PMPI_File_read_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                                    MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_all_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_all_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_all_c", "**mpi_file_read_all_c %F %p %c %D %p",
                                     fh, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_all_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_all_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                        MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_all_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ALL_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                        MPI_Status *status)
{
    return internal_File_read_all_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_begin = PMPI_File_read_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_begin  MPI_File_read_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_begin as PMPI_File_read_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_begin
#define MPI_File_read_all_begin PMPI_File_read_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_all_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_all_begin",
                                     "**mpi_file_read_all_begin %F %p %d %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_all_begin(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype)
{
    return internal_File_read_all_begin(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_read_all_begin_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_all_begin(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_read_all_begin_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ALL_BEGIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ALL_BEGIN_T], fh, buf, count,
            datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    return internal_File_read_all_begin(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_begin_c = PMPI_File_read_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_begin_c  MPI_File_read_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_begin_c as PMPI_File_read_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_begin_c
#define MPI_File_read_all_begin_c PMPI_File_read_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count,
                                          MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_all_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_all_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_all_begin_c",
                                     "**mpi_file_read_all_begin_c %F %p %c %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_all_begin_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                               MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_read_all_begin_c(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_read_all_begin_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_all_begin_c(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_read_all_begin_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ALL_BEGIN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ALL_BEGIN_C_T], fh, buf,
            count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_read_all_begin_c(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_all_end = PMPI_File_read_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_all_end  MPI_File_read_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_all_end as PMPI_File_read_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_all_end
#define MPI_File_read_all_end PMPI_File_read_all_end
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_all_end", "**mpi_file_read_all_end %F %p %p", fh,
                                     buf, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_all_end(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                           MPI_Status *status)
{
    return internal_File_read_all_end(fh, buf, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_all_end_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_all_end(context, 0, fh, buf, status);

    fn_ptr = (QMPI_File_read_all_end_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ALL_END_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ALL_END_T], fh, buf, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    return internal_File_read_all_end(fh, buf, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at = PMPI_File_read_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at  MPI_File_read_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at as PMPI_File_read_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                     MPI_Status *status)  __attribute__ ((weak, alias("PMPI_File_read_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at
#define MPI_File_read_at PMPI_File_read_at
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at", "**mpi_file_read_at %F %L %p %d %D %p", fh,
                                     (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset, void *buf,
                      int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                     MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_at_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_at_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_T], fh, offset, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                     MPI_Status *status)
{
    return internal_File_read_at(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_c = PMPI_File_read_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_c  MPI_File_read_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_c as PMPI_File_read_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                       MPI_Datatype datatype, MPI_Status *status)
                        __attribute__ ((weak, alias("PMPI_File_read_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_c
#define MPI_File_read_at_c PMPI_File_read_at_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_at_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at_c", "**mpi_file_read_at_c %F %L %p %c %D %p",
                                     fh, (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                        void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at_c(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                       MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_at_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at_c(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_at_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_C_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                       MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at_c(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all = PMPI_File_read_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all  MPI_File_read_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all as PMPI_File_read_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status)
                          __attribute__ ((weak, alias("PMPI_File_read_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all
#define MPI_File_read_at_all PMPI_File_read_at_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                                     MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_all_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at_all",
                                     "**mpi_file_read_at_all %F %L %p %d %D %p", fh, (long long) offset,
                                     buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at_all(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                          void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at_all(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_at_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at_all(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_at_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_ALL_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at_all(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_c = PMPI_File_read_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_c  MPI_File_read_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_c as PMPI_File_read_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Status *status)
                            __attribute__ ((weak, alias("PMPI_File_read_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_c
#define MPI_File_read_at_all_c PMPI_File_read_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                       MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_at_all_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at_all_c",
                                     "**mpi_file_read_at_all_c %F %L %p %c %D %p", fh,
                                     (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at_all_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                            void *buf, MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at_all_c(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_at_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at_all_c(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_at_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_ALL_C_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_at_all_c(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_begin = PMPI_File_read_at_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_begin  MPI_File_read_at_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_begin as PMPI_File_read_at_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count,
                               MPI_Datatype datatype)
                                __attribute__ ((weak, alias("PMPI_File_read_at_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_begin
#define MPI_File_read_at_all_begin PMPI_File_read_at_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count,
                                           MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_all_begin_impl(fh, offset, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at_all_begin",
                                     "**mpi_file_read_at_all_begin %F %L %p %d %D", fh,
                                     (long long) offset, buf, count, datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at_all_begin(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                                void *buf, int count, MPI_Datatype datatype)
{
    return internal_File_read_at_all_begin(fh, offset, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count,
                               MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_read_at_all_begin_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at_all_begin(context, 0, fh, offset, buf, count, datatype);

    fn_ptr = (QMPI_File_read_at_all_begin_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_ALL_BEGIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_ALL_BEGIN_T], fh, offset,
            buf, count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count,
                               MPI_Datatype datatype)
{
    return internal_File_read_at_all_begin(fh, offset, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_begin_c = PMPI_File_read_at_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_begin_c  MPI_File_read_at_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_begin_c as PMPI_File_read_at_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                 MPI_Datatype datatype)
                                  __attribute__ ((weak, alias("PMPI_File_read_at_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_begin_c
#define MPI_File_read_at_all_begin_c PMPI_File_read_at_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf,
                                             MPI_Count count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_at_all_begin_impl(fh, offset, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_at_all_begin_impl(fh, offset, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at_all_begin_c",
                                     "**mpi_file_read_at_all_begin_c %F %L %p %c %D", fh,
                                     (long long) offset, buf, count, datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at_all_begin_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                                  void *buf, MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_read_at_all_begin_c(fh, offset, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                 MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_read_at_all_begin_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at_all_begin_c(context, 0, fh, offset, buf, count, datatype);

    fn_ptr = (QMPI_File_read_at_all_begin_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_ALL_BEGIN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_ALL_BEGIN_C_T], fh, offset,
            buf, count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset, void *buf, MPI_Count count,
                                 MPI_Datatype datatype)
{
    return internal_File_read_at_all_begin_c(fh, offset, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_at_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_at_all_end = PMPI_File_read_at_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_at_all_end  MPI_File_read_at_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_at_all_end as PMPI_File_read_at_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_at_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_at_all_end
#define MPI_File_read_at_all_end PMPI_File_read_at_all_end
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_at_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_at_all_end",
                                     "**mpi_file_read_at_all_end %F %p %p", fh, buf, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_at_all_end(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                              MPI_Status *status)
{
    return internal_File_read_at_all_end(fh, buf, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_at_all_end_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_at_all_end(context, 0, fh, buf, status);

    fn_ptr = (QMPI_File_read_at_all_end_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_AT_ALL_END_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_AT_ALL_END_T], fh, buf,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status)
{
    return internal_File_read_at_all_end(fh, buf, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered = PMPI_File_read_ordered
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered  MPI_File_read_ordered
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered as PMPI_File_read_ordered
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
                           __attribute__ ((weak, alias("PMPI_File_read_ordered")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered
#define MPI_File_read_ordered PMPI_File_read_ordered
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                                      MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_ordered_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_ordered",
                                     "**mpi_file_read_ordered %F %p %d %D %p", fh, buf, count, datatype,
                                     status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_ordered(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_ordered(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_ordered_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_ordered(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_ordered_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ORDERED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ORDERED_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
{
    return internal_File_read_ordered(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_c = PMPI_File_read_ordered_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_c  MPI_File_read_ordered_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_c as PMPI_File_read_ordered_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
                             __attribute__ ((weak, alias("PMPI_File_read_ordered_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_c
#define MPI_File_read_ordered_c PMPI_File_read_ordered_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count,
                                        MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_ordered_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_ordered_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_ordered_c",
                                     "**mpi_file_read_ordered_c %F %p %c %D %p", fh, buf, count,
                                     datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_ordered_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_ordered_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_ordered_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_ordered_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_ordered_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ORDERED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ORDERED_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
{
    return internal_File_read_ordered_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_begin = PMPI_File_read_ordered_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_begin  MPI_File_read_ordered_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_begin as PMPI_File_read_ordered_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_ordered_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_begin
#define MPI_File_read_ordered_begin PMPI_File_read_ordered_begin
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                            MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_ordered_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_ordered_begin",
                                     "**mpi_file_read_ordered_begin %F %p %d %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_ordered_begin(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                                 int count, MPI_Datatype datatype)
{
    return internal_File_read_ordered_begin(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_read_ordered_begin_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_ordered_begin(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_read_ordered_begin_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ORDERED_BEGIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ORDERED_BEGIN_T], fh, buf,
            count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype)
{
    return internal_File_read_ordered_begin(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_begin_c = PMPI_File_read_ordered_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_begin_c  MPI_File_read_ordered_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_begin_c as PMPI_File_read_ordered_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_read_ordered_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_begin_c
#define MPI_File_read_ordered_begin_c PMPI_File_read_ordered_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count,
                                              MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_ordered_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_ordered_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_ordered_begin_c",
                                     "**mpi_file_read_ordered_begin_c %F %p %c %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_ordered_begin_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                                   MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_read_ordered_begin_c(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_read_ordered_begin_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_ordered_begin_c(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_read_ordered_begin_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ORDERED_BEGIN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ORDERED_BEGIN_C_T], fh, buf,
            count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_read_ordered_begin_c(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_ordered_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_ordered_end = PMPI_File_read_ordered_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_ordered_end  MPI_File_read_ordered_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_ordered_end as PMPI_File_read_ordered_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_read_ordered_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_ordered_end
#define MPI_File_read_ordered_end PMPI_File_read_ordered_end
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_ordered_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_ordered_end",
                                     "**mpi_file_read_ordered_end %F %p %p", fh, buf, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_ordered_end(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                               MPI_Status *status)
{
    return internal_File_read_ordered_end(fh, buf, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_ordered_end_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_ordered_end(context, 0, fh, buf, status);

    fn_ptr = (QMPI_File_read_ordered_end_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_ORDERED_END_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_ORDERED_END_T], fh, buf,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status)
{
    return internal_File_read_ordered_end(fh, buf, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_shared = PMPI_File_read_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_shared  MPI_File_read_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_shared as PMPI_File_read_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                         MPI_Status *status)
                          __attribute__ ((weak, alias("PMPI_File_read_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_shared
#define MPI_File_read_shared PMPI_File_read_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                                     MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_read_shared_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_shared", "**mpi_file_read_shared %F %p %d %D %p",
                                     fh, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_shared(QMPI_Context context, int tool_id, MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_shared(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_shared(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_SHARED_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    return internal_File_read_shared(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_read_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_read_shared_c = PMPI_File_read_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_read_shared_c  MPI_File_read_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_read_shared_c as PMPI_File_read_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                           MPI_Status *status)
                            __attribute__ ((weak, alias("PMPI_File_read_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_read_shared_c
#define MPI_File_read_shared_c PMPI_File_read_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count,
                                       MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_read_shared_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_read_shared_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_read_shared_c",
                                     "**mpi_file_read_shared_c %F %p %c %D %p", fh, buf, count,
                                     datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_read_shared_c(QMPI_Context context, int tool_id, MPI_File fh, void *buf,
                            MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_read_shared_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                           MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_read_shared_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_read_shared_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_read_shared_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_READ_SHARED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_READ_SHARED_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count, MPI_Datatype datatype,
                           MPI_Status *status)
{
    return internal_File_read_shared_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_seek */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_seek = PMPI_File_seek
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_seek  MPI_File_seek
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_seek as PMPI_File_seek
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
     __attribute__ ((weak, alias("PMPI_File_seek")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_seek
#define MPI_File_seek PMPI_File_seek
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_seek_impl(fh, offset, whence);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_seek", "**mpi_file_seek %F %L %d", fh,
                                     (long long) offset, whence);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_seek(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset, int whence)
{
    return internal_File_seek(fh, offset, whence);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
    QMPI_Context context;
    QMPI_File_seek_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_seek(context, 0, fh, offset, whence);

    fn_ptr = (QMPI_File_seek_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SEEK_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SEEK_T], fh, offset, whence);
}
#else /* ENABLE_QMPI */
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
    return internal_File_seek(fh, offset, whence);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_seek_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_seek_shared = PMPI_File_seek_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_seek_shared  MPI_File_seek_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_seek_shared as PMPI_File_seek_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
     __attribute__ ((weak, alias("PMPI_File_seek_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_seek_shared
#define MPI_File_seek_shared PMPI_File_seek_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_seek_shared_impl(fh, offset, whence);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_seek_shared", "**mpi_file_seek_shared %F %L %d", fh,
                                     (long long) offset, whence);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_seek_shared(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                          int whence)
{
    return internal_File_seek_shared(fh, offset, whence);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
    QMPI_Context context;
    QMPI_File_seek_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_seek_shared(context, 0, fh, offset, whence);

    fn_ptr = (QMPI_File_seek_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SEEK_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SEEK_SHARED_T], fh, offset,
            whence);
}
#else /* ENABLE_QMPI */
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
    return internal_File_seek_shared(fh, offset, whence);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_set_atomicity */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_atomicity = PMPI_File_set_atomicity
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_atomicity  MPI_File_set_atomicity
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_atomicity as PMPI_File_set_atomicity
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_atomicity(MPI_File fh, int flag)
     __attribute__ ((weak, alias("PMPI_File_set_atomicity")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_atomicity
#define MPI_File_set_atomicity PMPI_File_set_atomicity
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_set_atomicity(MPI_File fh, int flag)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_atomicity_impl(fh, flag);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_set_atomicity", "**mpi_file_set_atomicity %F %d", fh,
                                     flag);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_set_atomicity(QMPI_Context context, int tool_id, MPI_File fh, int flag)
{
    return internal_File_set_atomicity(fh, flag);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_set_atomicity(MPI_File fh, int flag)
{
    QMPI_Context context;
    QMPI_File_set_atomicity_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_set_atomicity(context, 0, fh, flag);

    fn_ptr = (QMPI_File_set_atomicity_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SET_ATOMICITY_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SET_ATOMICITY_T], fh, flag);
}
#else /* ENABLE_QMPI */
int MPI_File_set_atomicity(MPI_File fh, int flag)
{
    return internal_File_set_atomicity(fh, flag);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_set_info */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_info = PMPI_File_set_info
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_info  MPI_File_set_info
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_info as PMPI_File_set_info
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_info(MPI_File fh, MPI_Info info)
     __attribute__ ((weak, alias("PMPI_File_set_info")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_info
#define MPI_File_set_info PMPI_File_set_info
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_set_info(MPI_File fh, MPI_Info info)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_info_impl(fh, info);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_set_info", "**mpi_file_set_info %F %I", fh, info);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_set_info(QMPI_Context context, int tool_id, MPI_File fh, MPI_Info info)
{
    return internal_File_set_info(fh, info);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_set_info(MPI_File fh, MPI_Info info)
{
    QMPI_Context context;
    QMPI_File_set_info_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_set_info(context, 0, fh, info);

    fn_ptr = (QMPI_File_set_info_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SET_INFO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SET_INFO_T], fh, info);
}
#else /* ENABLE_QMPI */
int MPI_File_set_info(MPI_File fh, MPI_Info info)
{
    return internal_File_set_info(fh, info);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_set_size */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_size = PMPI_File_set_size
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_size  MPI_File_set_size
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_size as PMPI_File_set_size
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_size(MPI_File fh, MPI_Offset size)
     __attribute__ ((weak, alias("PMPI_File_set_size")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_size
#define MPI_File_set_size PMPI_File_set_size
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_set_size(MPI_File fh, MPI_Offset size)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_size_impl(fh, size);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_set_size", "**mpi_file_set_size %F %L", fh,
                                     (long long) size);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_set_size(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset size)
{
    return internal_File_set_size(fh, size);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_set_size(MPI_File fh, MPI_Offset size)
{
    QMPI_Context context;
    QMPI_File_set_size_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_set_size(context, 0, fh, size);

    fn_ptr = (QMPI_File_set_size_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SET_SIZE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SET_SIZE_T], fh, size);
}
#else /* ENABLE_QMPI */
int MPI_File_set_size(MPI_File fh, MPI_Offset size)
{
    return internal_File_set_size(fh, size);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_set_view */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_set_view = PMPI_File_set_view
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_set_view  MPI_File_set_view
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_set_view as PMPI_File_set_view
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype,
                      const char *datarep, MPI_Info info)
                       __attribute__ ((weak, alias("PMPI_File_set_view")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_set_view
#define MPI_File_set_view PMPI_File_set_view
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                                  MPI_Datatype filetype, const char *datarep, MPI_Info info)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(etype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(etype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(etype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_DATATYPE(filetype, "datatype", mpi_errno);
            if (!HANDLE_IS_BUILTIN(filetype)) {
                MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                MPIR_Datatype_get_ptr(filetype, datatype_ptr);
                MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
                MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                if (mpi_errno) {
                    goto fn_fail;
                }
            }
            MPIR_ERRTEST_ARGNULL(datarep, "datarep", mpi_errno);
            if (disp != MPI_DISPLACEMENT_CURRENT) {
                MPIR_ERRTEST_ARGNEG(disp, "disp", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_set_view_impl(fh, disp, etype, filetype, datarep, info);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_set_view", "**mpi_file_set_view %F %L %D %D %s %I", fh,
                                     (long long) disp, etype, filetype, datarep, info);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_set_view(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset disp,
                       MPI_Datatype etype, MPI_Datatype filetype, const char *datarep,
                       MPI_Info info)
{
    return internal_File_set_view(fh, disp, etype, filetype, datarep, info);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype,
                      const char *datarep, MPI_Info info)
{
    QMPI_Context context;
    QMPI_File_set_view_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_set_view(context, 0, fh, disp, etype, filetype, datarep, info);

    fn_ptr = (QMPI_File_set_view_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SET_VIEW_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SET_VIEW_T], fh, disp, etype,
            filetype, datarep, info);
}
#else /* ENABLE_QMPI */
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype,
                      const char *datarep, MPI_Info info)
{
    return internal_File_set_view(fh, disp, etype, filetype, datarep, info);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_sync */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync = PMPI_File_sync
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync  MPI_File_sync
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync as PMPI_File_sync
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync(MPI_File fh)  __attribute__ ((weak, alias("PMPI_File_sync")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_sync
#define MPI_File_sync PMPI_File_sync
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_sync(MPI_File fh)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_sync_impl(fh);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_sync", "**mpi_file_sync %F", fh);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_sync(QMPI_Context context, int tool_id, MPI_File fh)
{
    return internal_File_sync(fh);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_sync(MPI_File fh)
{
    QMPI_Context context;
    QMPI_File_sync_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_sync(context, 0, fh);

    fn_ptr = (QMPI_File_sync_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SYNC_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SYNC_T], fh);
}
#else /* ENABLE_QMPI */
int MPI_File_sync(MPI_File fh)
{
    return internal_File_sync(fh);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write = PMPI_File_write
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write  MPI_File_write
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write as PMPI_File_write
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status)  __attribute__ ((weak, alias("PMPI_File_write")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write
#define MPI_File_write PMPI_File_write
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                               MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write", "**mpi_file_write %F %p %d %D %p", fh, buf,
                                     count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write(QMPI_Context context, int tool_id, MPI_File fh, const void *buf, int count,
                    MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_T], fh, buf, count, datatype,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status)
{
    return internal_File_write(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_c = PMPI_File_write_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_c  MPI_File_write_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_c as PMPI_File_write_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Status *status)  __attribute__ ((weak, alias("PMPI_File_write_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_c
#define MPI_File_write_c PMPI_File_write_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_c(MPI_File fh, const void *buf, MPI_Count count,
                                 MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_c", "**mpi_file_write_c %F %p %c %D %p", fh, buf,
                                     count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                      MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                     MPI_Status *status)
{
    return internal_File_write_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all = PMPI_File_write_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all  MPI_File_write_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all as PMPI_File_write_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status)  __attribute__ ((weak, alias("PMPI_File_write_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all
#define MPI_File_write_all PMPI_File_write_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                                   MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_all_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_all", "**mpi_file_write_all %F %p %d %D %p", fh,
                                     buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_all(QMPI_Context context, int tool_id, MPI_File fh, const void *buf, int count,
                        MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_all(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_all(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ALL_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status)
{
    return internal_File_write_all(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_c = PMPI_File_write_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_c  MPI_File_write_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_c as PMPI_File_write_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Status *status)
                          __attribute__ ((weak, alias("PMPI_File_write_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_c
#define MPI_File_write_all_c PMPI_File_write_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count,
                                     MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_all_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_all_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_all_c", "**mpi_file_write_all_c %F %p %c %D %p",
                                     fh, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_all_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                          MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_all_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_all_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ALL_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    return internal_File_write_all_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_begin = PMPI_File_write_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_begin  MPI_File_write_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_begin as PMPI_File_write_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_write_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_begin
#define MPI_File_write_all_begin PMPI_File_write_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_all_begin(MPI_File fh, const void *buf, int count,
                                         MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_all_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_all_begin",
                                     "**mpi_file_write_all_begin %F %p %d %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_all_begin(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                              int count, MPI_Datatype datatype)
{
    return internal_File_write_all_begin(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_write_all_begin_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_all_begin(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_write_all_begin_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ALL_BEGIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ALL_BEGIN_T], fh, buf, count,
            datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
    return internal_File_write_all_begin(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_begin_c = PMPI_File_write_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_begin_c  MPI_File_write_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_begin_c as PMPI_File_write_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                               MPI_Datatype datatype)
                                __attribute__ ((weak, alias("PMPI_File_write_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_begin_c
#define MPI_File_write_all_begin_c PMPI_File_write_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                                           MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_all_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_all_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_all_begin_c",
                                     "**mpi_file_write_all_begin_c %F %p %c %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_all_begin_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                                MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_write_all_begin_c(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                               MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_write_all_begin_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_all_begin_c(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_write_all_begin_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ALL_BEGIN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ALL_BEGIN_C_T], fh, buf,
            count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_write_all_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                               MPI_Datatype datatype)
{
    return internal_File_write_all_begin_c(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_all_end = PMPI_File_write_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_all_end  MPI_File_write_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_all_end as PMPI_File_write_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_write_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_all_end
#define MPI_File_write_all_end PMPI_File_write_all_end
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_all_end", "**mpi_file_write_all_end %F %p %p",
                                     fh, buf, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_all_end(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                            MPI_Status *status)
{
    return internal_File_write_all_end(fh, buf, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_all_end_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_all_end(context, 0, fh, buf, status);

    fn_ptr = (QMPI_File_write_all_end_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ALL_END_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ALL_END_T], fh, buf,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    return internal_File_write_all_end(fh, buf, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at = PMPI_File_write_at
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at  MPI_File_write_at
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at as PMPI_File_write_at
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status)
                       __attribute__ ((weak, alias("PMPI_File_write_at")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at
#define MPI_File_write_at PMPI_File_write_at
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at", "**mpi_file_write_at %F %L %p %d %D %p", fh,
                                     (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                       const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_at(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_at_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_at_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_at(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_c = PMPI_File_write_at_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_c  MPI_File_write_at_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_c as PMPI_File_write_at_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Status *status)
                         __attribute__ ((weak, alias("PMPI_File_write_at_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_c
#define MPI_File_write_at_c PMPI_File_write_at_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_at_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_at_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at_c", "**mpi_file_write_at_c %F %L %p %c %D %p",
                                     fh, (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                         const void *buf, MPI_Count count, MPI_Datatype datatype,
                         MPI_Status *status)
{
    return internal_File_write_at_c(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_at_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at_c(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_at_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_C_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_at_c(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all = PMPI_File_write_at_all
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all  MPI_File_write_at_all
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all as PMPI_File_write_at_all
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status)
                           __attribute__ ((weak, alias("PMPI_File_write_at_all")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all
#define MPI_File_write_at_all PMPI_File_write_at_all
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                      MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_all_impl(fh, offset, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at_all",
                                     "**mpi_file_write_at_all %F %L %p %d %D %p", fh,
                                     (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at_all(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                           const void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_at_all(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_at_all_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at_all(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_at_all_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_ALL_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_ALL_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_at_all(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_c = PMPI_File_write_at_all_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_c  MPI_File_write_at_all_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_c as PMPI_File_write_at_all_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Status *status)
                             __attribute__ ((weak, alias("PMPI_File_write_at_all_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_c
#define MPI_File_write_at_all_c PMPI_File_write_at_all_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                        MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_at_all_impl(fh, offset, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_at_all_impl(fh, offset, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at_all_c",
                                     "**mpi_file_write_at_all_c %F %L %p %c %D %p", fh,
                                     (long long) offset, buf, count, datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at_all_c(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                             const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Status *status)
{
    return internal_File_write_at_all_c(fh, offset, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_at_all_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at_all_c(context, 0, fh, offset, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_at_all_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_ALL_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_ALL_C_T], fh, offset, buf,
            count, datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_at_all_c(fh, offset, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_begin = PMPI_File_write_at_all_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_begin  MPI_File_write_at_all_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_begin as PMPI_File_write_at_all_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                MPI_Datatype datatype)
                                 __attribute__ ((weak, alias("PMPI_File_write_at_all_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_begin
#define MPI_File_write_at_all_begin PMPI_File_write_at_all_begin
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf,
                                            int count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_all_begin_impl(fh, offset, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at_all_begin",
                                     "**mpi_file_write_at_all_begin %F %L %p %d %D", fh,
                                     (long long) offset, buf, count, datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at_all_begin(QMPI_Context context, int tool_id, MPI_File fh, MPI_Offset offset,
                                 const void *buf, int count, MPI_Datatype datatype)
{
    return internal_File_write_at_all_begin(fh, offset, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_write_at_all_begin_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at_all_begin(context, 0, fh, offset, buf, count, datatype);

    fn_ptr = (QMPI_File_write_at_all_begin_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_ALL_BEGIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_ALL_BEGIN_T], fh, offset,
            buf, count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                MPI_Datatype datatype)
{
    return internal_File_write_at_all_begin(fh, offset, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_begin_c = PMPI_File_write_at_all_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_begin_c  MPI_File_write_at_all_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_begin_c as PMPI_File_write_at_all_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                                  MPI_Datatype datatype)
                                   __attribute__ ((weak, alias("PMPI_File_write_at_all_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_begin_c
#define MPI_File_write_at_all_begin_c PMPI_File_write_at_all_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                              MPI_Count count, MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_at_all_begin_impl(fh, offset, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_at_all_begin_impl(fh, offset, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at_all_begin_c",
                                     "**mpi_file_write_at_all_begin_c %F %L %p %c %D", fh,
                                     (long long) offset, buf, count, datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at_all_begin_c(QMPI_Context context, int tool_id, MPI_File fh,
                                   MPI_Offset offset, const void *buf, MPI_Count count,
                                   MPI_Datatype datatype)
{
    return internal_File_write_at_all_begin_c(fh, offset, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                                  MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_write_at_all_begin_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at_all_begin_c(context, 0, fh, offset, buf, count, datatype);

    fn_ptr = (QMPI_File_write_at_all_begin_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_ALL_BEGIN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_ALL_BEGIN_C_T], fh,
            offset, buf, count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset, const void *buf, MPI_Count count,
                                  MPI_Datatype datatype)
{
    return internal_File_write_at_all_begin_c(fh, offset, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_at_all_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_at_all_end = PMPI_File_write_at_all_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_at_all_end  MPI_File_write_at_all_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_at_all_end as PMPI_File_write_at_all_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_write_at_all_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_at_all_end
#define MPI_File_write_at_all_end PMPI_File_write_at_all_end
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_at_all_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_at_all_end",
                                     "**mpi_file_write_at_all_end %F %p %p", fh, buf, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_at_all_end(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                               MPI_Status *status)
{
    return internal_File_write_at_all_end(fh, buf, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_at_all_end_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_at_all_end(context, 0, fh, buf, status);

    fn_ptr = (QMPI_File_write_at_all_end_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_AT_ALL_END_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_AT_ALL_END_T], fh, buf,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_at_all_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    return internal_File_write_at_all_end(fh, buf, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered = PMPI_File_write_ordered
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered  MPI_File_write_ordered
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered as PMPI_File_write_ordered
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Status *status)
                            __attribute__ ((weak, alias("PMPI_File_write_ordered")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered
#define MPI_File_write_ordered PMPI_File_write_ordered
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_ordered(MPI_File fh, const void *buf, int count,
                                       MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_ordered_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_ordered",
                                     "**mpi_file_write_ordered %F %p %d %D %p", fh, buf, count,
                                     datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_ordered(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                            int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_ordered(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_ordered_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_ordered(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_ordered_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ORDERED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ORDERED_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Status *status)
{
    return internal_File_write_ordered(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_c = PMPI_File_write_ordered_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_c  MPI_File_write_ordered_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_c as PMPI_File_write_ordered_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Status *status)
                              __attribute__ ((weak, alias("PMPI_File_write_ordered_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_c
#define MPI_File_write_ordered_c PMPI_File_write_ordered_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count,
                                         MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_ordered_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_ordered_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_ordered_c",
                                     "**mpi_file_write_ordered_c %F %p %c %D %p", fh, buf, count,
                                     datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_ordered_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                              MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_ordered_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_ordered_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_ordered_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_ordered_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ORDERED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ORDERED_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_ordered_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                             MPI_Status *status)
{
    return internal_File_write_ordered_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_begin */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_begin = PMPI_File_write_ordered_begin
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_begin  MPI_File_write_ordered_begin
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_begin as PMPI_File_write_ordered_begin
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
     __attribute__ ((weak, alias("PMPI_File_write_ordered_begin")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_begin
#define MPI_File_write_ordered_begin PMPI_File_write_ordered_begin
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_ordered_begin(MPI_File fh, const void *buf, int count,
                                             MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_ordered_begin_impl(fh, buf, count, datatype);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_ordered_begin",
                                     "**mpi_file_write_ordered_begin %F %p %d %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_ordered_begin(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                                  int count, MPI_Datatype datatype)
{
    return internal_File_write_ordered_begin(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_write_ordered_begin_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_ordered_begin(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_write_ordered_begin_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ORDERED_BEGIN_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ORDERED_BEGIN_T], fh, buf,
            count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype)
{
    return internal_File_write_ordered_begin(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_begin_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_begin_c = PMPI_File_write_ordered_begin_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_begin_c  MPI_File_write_ordered_begin_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_begin_c as PMPI_File_write_ordered_begin_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                                   MPI_Datatype datatype)
                                    __attribute__ ((weak, alias("PMPI_File_write_ordered_begin_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_begin_c
#define MPI_File_write_ordered_begin_c PMPI_File_write_ordered_begin_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                                               MPI_Datatype datatype)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_ordered_begin_impl(fh, buf, (MPI_Aint) count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_ordered_begin_impl(fh, buf, count, datatype);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_ordered_begin_c",
                                     "**mpi_file_write_ordered_begin_c %F %p %c %D", fh, buf, count,
                                     datatype);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_ordered_begin_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype)
{
    return internal_File_write_ordered_begin_c(fh, buf, count, datatype);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                                   MPI_Datatype datatype)
{
    QMPI_Context context;
    QMPI_File_write_ordered_begin_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_ordered_begin_c(context, 0, fh, buf, count, datatype);

    fn_ptr = (QMPI_File_write_ordered_begin_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ORDERED_BEGIN_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ORDERED_BEGIN_C_T], fh, buf,
            count, datatype);
}
#else /* ENABLE_QMPI */
int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf, MPI_Count count,
                                   MPI_Datatype datatype)
{
    return internal_File_write_ordered_begin_c(fh, buf, count, datatype);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_ordered_end */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_ordered_end = PMPI_File_write_ordered_end
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_ordered_end  MPI_File_write_ordered_end
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_ordered_end as PMPI_File_write_ordered_end
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
     __attribute__ ((weak, alias("PMPI_File_write_ordered_end")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_ordered_end
#define MPI_File_write_ordered_end PMPI_File_write_ordered_end
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_ordered_end_impl(fh, buf, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_ordered_end",
                                     "**mpi_file_write_ordered_end %F %p %p", fh, buf, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_ordered_end(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                                MPI_Status *status)
{
    return internal_File_write_ordered_end(fh, buf, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_ordered_end_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_ordered_end(context, 0, fh, buf, status);

    fn_ptr = (QMPI_File_write_ordered_end_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_ORDERED_END_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_ORDERED_END_T], fh, buf,
            status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_ordered_end(MPI_File fh, const void *buf, MPI_Status *status)
{
    return internal_File_write_ordered_end(fh, buf, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_shared */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_shared = PMPI_File_write_shared
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_shared  MPI_File_write_shared
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_shared as PMPI_File_write_shared
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
                           __attribute__ ((weak, alias("PMPI_File_write_shared")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_shared
#define MPI_File_write_shared PMPI_File_write_shared
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_shared(MPI_File fh, const void *buf, int count,
                                      MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_write_shared_impl(fh, buf, count, datatype, status);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_shared",
                                     "**mpi_file_write_shared %F %p %d %D %p", fh, buf, count, datatype,
                                     status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_shared(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                           int count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_shared(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_shared_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_shared(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_shared_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_SHARED_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_SHARED_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                          MPI_Status *status)
{
    return internal_File_write_shared(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_write_shared_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_write_shared_c = PMPI_File_write_shared_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_write_shared_c  MPI_File_write_shared_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_write_shared_c as PMPI_File_write_shared_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
                             __attribute__ ((weak, alias("PMPI_File_write_shared_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_write_shared_c
#define MPI_File_write_shared_c PMPI_File_write_shared_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count,
                                        MPI_Datatype datatype, MPI_Status *status)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_COUNT(count, mpi_errno);
            if (count > 0) {
                MPIR_ERRTEST_DATATYPE(datatype, "datatype", mpi_errno);
                if (!HANDLE_IS_BUILTIN(datatype)) {
                    MPIR_Datatype *datatype_ptr ATTRIBUTE((unused)) = NULL;
                    MPIR_Datatype_get_ptr(datatype, datatype_ptr);
                    MPIR_Datatype_valid_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                    MPIR_Datatype_committed_ptr(datatype_ptr, mpi_errno);
                    if (mpi_errno) {
                        goto fn_fail;
                    }
                }
                MPIR_ERRTEST_USERBUFFER(buf, count, datatype, mpi_errno);
            }
            if (status != MPI_STATUS_IGNORE) {
                MPIR_ERRTEST_ARGNULL(status, "status", mpi_errno);
            }
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    MPIR_DATATYPE_REPLACE_BUILTIN(datatype);

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_File_write_shared_impl(fh, buf, (MPI_Aint) count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        if (count > MPIR_AINT_MAX) {
            mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE,
                                             __func__, __LINE__, MPI_ERR_OTHER,
                                             "**too_big_for_input",
                                             "**too_big_for_input %s", "count");
            goto fn_fail;
        }
        mpi_errno = MPIR_File_write_shared_impl(fh, buf, count, datatype, status);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_write_shared_c",
                                     "**mpi_file_write_shared_c %F %p %c %D %p", fh, buf, count,
                                     datatype, status);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_write_shared_c(QMPI_Context context, int tool_id, MPI_File fh, const void *buf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Status *status)
{
    return internal_File_write_shared_c(fh, buf, count, datatype, status);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
{
    QMPI_Context context;
    QMPI_File_write_shared_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_write_shared_c(context, 0, fh, buf, count, datatype, status);

    fn_ptr = (QMPI_File_write_shared_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_WRITE_SHARED_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_WRITE_SHARED_C_T], fh, buf, count,
            datatype, status);
}
#else /* ENABLE_QMPI */
int MPI_File_write_shared_c(MPI_File fh, const void *buf, MPI_Count count, MPI_Datatype datatype,
                            MPI_Status *status)
{
    return internal_File_write_shared_c(fh, buf, count, datatype, status);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Register_datarep */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Register_datarep = PMPI_Register_datarep
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Register_datarep  MPI_Register_datarep
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Register_datarep as PMPI_Register_datarep
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
                          __attribute__ ((weak, alias("PMPI_Register_datarep")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Register_datarep
#define MPI_Register_datarep PMPI_Register_datarep
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Register_datarep(const char *datarep,
                                     MPI_Datarep_conversion_function *read_conversion_fn,
                                     MPI_Datarep_conversion_function *write_conversion_fn,
                                     MPI_Datarep_extent_function *dtype_file_extent_fn,
                                     void *extra_state)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(datarep, "datarep", mpi_errno);
            MPIR_ERRTEST_ARGNULL(dtype_file_extent_fn, "dtype_file_extent_fn", mpi_errno);
            /* both read_conversion_fn and write_conversion_fn may be MPI_CONVERSION_FN_NULL, which could be NULL */
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_Register_datarep_impl(datarep, read_conversion_fn, write_conversion_fn,
                                           dtype_file_extent_fn, extra_state);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_register_datarep", "**mpi_register_datarep %s %p %p %p %p",
                                     datarep, read_conversion_fn, write_conversion_fn,
                                     dtype_file_extent_fn, extra_state);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Register_datarep(QMPI_Context context, int tool_id, const char *datarep,
                          MPI_Datarep_conversion_function *read_conversion_fn,
                          MPI_Datarep_conversion_function *write_conversion_fn,
                          MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    return internal_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    QMPI_Context context;
    QMPI_Register_datarep_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Register_datarep(context, 0, datarep, read_conversion_fn, write_conversion_fn,
                                     dtype_file_extent_fn, extra_state);

    fn_ptr = (QMPI_Register_datarep_t *) MPIR_QMPI_first_fn_ptrs[MPI_REGISTER_DATAREP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REGISTER_DATAREP_T], datarep,
            read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}
#else /* ENABLE_QMPI */
int MPI_Register_datarep(const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    return internal_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_Register_datarep_c */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Register_datarep_c = PMPI_Register_datarep_c
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Register_datarep_c  MPI_Register_datarep_c
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Register_datarep_c as PMPI_Register_datarep_c
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Register_datarep_c(const char *datarep,
                           MPI_Datarep_conversion_function_c *read_conversion_fn,
                           MPI_Datarep_conversion_function_c *write_conversion_fn,
                           MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
                            __attribute__ ((weak, alias("PMPI_Register_datarep_c")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Register_datarep_c
#define MPI_Register_datarep_c PMPI_Register_datarep_c
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_Register_datarep_c(const char *datarep,
                                       MPI_Datarep_conversion_function_c *read_conversion_fn,
                                       MPI_Datarep_conversion_function_c *write_conversion_fn,
                                       MPI_Datarep_extent_function *dtype_file_extent_fn,
                                       void *extra_state)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_ARGNULL(datarep, "datarep", mpi_errno);
            MPIR_ERRTEST_ARGNULL(dtype_file_extent_fn, "dtype_file_extent_fn", mpi_errno);
            /* both read_conversion_fn and write_conversion_fn may be MPI_CONVERSION_FN_NULL, which could be NULL */
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    if (sizeof(MPI_Count) == sizeof(MPI_Aint)) {
        mpi_errno = MPIR_Register_datarep_large_impl(datarep, read_conversion_fn, write_conversion_fn,
                                                     dtype_file_extent_fn, extra_state);
        if (mpi_errno) {
            goto fn_fail;
        }
    } else {
        /* MPI_Count is bigger than MPI_Aint */
        mpi_errno = MPIR_Register_datarep_large_impl(datarep, read_conversion_fn, write_conversion_fn,
                                                     dtype_file_extent_fn, extra_state);
        if (mpi_errno) {
            goto fn_fail;
        }
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_register_datarep_c",
                                     "**mpi_register_datarep_c %s %p %p %p %p", datarep,
                                     read_conversion_fn, write_conversion_fn, dtype_file_extent_fn,
                                     extra_state);
#endif
    mpi_errno = MPIR_Err_return_comm(0, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_Register_datarep_c(QMPI_Context context, int tool_id, const char *datarep,
                            MPI_Datarep_conversion_function_c *read_conversion_fn,
                            MPI_Datarep_conversion_function_c *write_conversion_fn,
                            MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    return internal_Register_datarep_c(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_Register_datarep_c(const char *datarep,
                           MPI_Datarep_conversion_function_c *read_conversion_fn,
                           MPI_Datarep_conversion_function_c *write_conversion_fn,
                           MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    QMPI_Context context;
    QMPI_Register_datarep_c_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_Register_datarep_c(context, 0, datarep, read_conversion_fn, write_conversion_fn,
                                       dtype_file_extent_fn, extra_state);

    fn_ptr = (QMPI_Register_datarep_c_t *) MPIR_QMPI_first_fn_ptrs[MPI_REGISTER_DATAREP_C_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_REGISTER_DATAREP_C_T], datarep,
            read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}
#else /* ENABLE_QMPI */
int MPI_Register_datarep_c(const char *datarep,
                           MPI_Datarep_conversion_function_c *read_conversion_fn,
                           MPI_Datarep_conversion_function_c *write_conversion_fn,
                           MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state)
{
    return internal_Register_datarep_c(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_sync_to */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync_to = PMPI_File_sync_to
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync_to  MPI_File_sync_to
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync_to as PMPI_File_sync_to
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync_to(MPI_File fh, int target_rank, MPI_Comm comm)
     __attribute__ ((weak, alias("PMPI_File_sync_to")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_sync_to
#define MPI_File_sync_to PMPI_File_sync_to
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_sync_to(MPI_File fh, int target_rank, MPI_Comm comm)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_SEND_RANK(comm_ptr, target_rank, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_sync_to_impl(fh, target_rank, comm);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_sync_to", "**mpi_file_sync_to %F %d %C", fh,
                                     target_rank, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_sync_to(QMPI_Context context, int tool_id, MPI_File fh, int target_rank,
                      MPI_Comm comm)
{
    return internal_File_sync_to(fh, target_rank, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_sync_to(MPI_File fh, int target_rank, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_File_sync_to_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_sync_to(context, 0, fh, target_rank, comm);

    fn_ptr = (QMPI_File_sync_to_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SYNC_TO_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SYNC_TO_T], fh, target_rank,
            comm);
}
#else /* ENABLE_QMPI */
int MPI_File_sync_to(MPI_File fh, int target_rank, MPI_Comm comm)
{
    return internal_File_sync_to(fh, target_rank, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_sync_from */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync_from = PMPI_File_sync_from
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync_from  MPI_File_sync_from
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync_from as PMPI_File_sync_from
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync_from(MPI_File fh, int source_rank, MPI_Comm comm)
     __attribute__ ((weak, alias("PMPI_File_sync_from")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_sync_from
#define MPI_File_sync_from PMPI_File_sync_from
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_sync_from(MPI_File fh, int source_rank, MPI_Comm comm)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_RANK(comm_ptr, source_rank, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_sync_from_impl(fh, source_rank, comm);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_sync_from", "**mpi_file_sync_from %F %d %C", fh,
                                     source_rank, comm);
#endif
    mpi_errno = MPIR_Err_return_comm(comm_ptr, __func__, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_sync_from(QMPI_Context context, int tool_id, MPI_File fh, int source_rank,
                        MPI_Comm comm)
{
    return internal_File_sync_from(fh, source_rank, comm);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_sync_from(MPI_File fh, int source_rank, MPI_Comm comm)
{
    QMPI_Context context;
    QMPI_File_sync_from_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_sync_from(context, 0, fh, source_rank, comm);

    fn_ptr = (QMPI_File_sync_from_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SYNC_FROM_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SYNC_FROM_T], fh, source_rank,
            comm);
}
#else /* ENABLE_QMPI */
int MPI_File_sync_from(MPI_File fh, int source_rank, MPI_Comm comm)
{
    return internal_File_sync_from(fh, source_rank, comm);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_sync_group */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_sync_group = PMPI_File_sync_group
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_sync_group  MPI_File_sync_group
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_sync_group as PMPI_File_sync_group
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_sync_group(MPI_File fh, MPI_Group group)
     __attribute__ ((weak, alias("PMPI_File_sync_group")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_sync_group
#define MPI_File_sync_group PMPI_File_sync_group
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_sync_group(MPI_File fh, MPI_Group group)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_sync_group_impl(fh, group);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_sync_group", "**mpi_file_sync_group %F %G", fh,
                                     group);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_sync_group(QMPI_Context context, int tool_id, MPI_File fh, MPI_Group group)
{
    return internal_File_sync_group(fh, group);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_sync_group(MPI_File fh, MPI_Group group)
{
    QMPI_Context context;
    QMPI_File_sync_group_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_sync_group(context, 0, fh, group);

    fn_ptr = (QMPI_File_sync_group_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_SYNC_GROUP_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_SYNC_GROUP_T], fh, group);
}
#else /* ENABLE_QMPI */
int MPI_File_sync_group(MPI_File fh, MPI_Group group)
{
    return internal_File_sync_group(fh, group);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_release */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_release = PMPI_File_release
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_release  MPI_File_release
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_release as PMPI_File_release
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_release(MPI_File fh, MPI_Group writers, MPI_Group readers)
     __attribute__ ((weak, alias("PMPI_File_release")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_release
#define MPI_File_release PMPI_File_release
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_release(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_release_impl(fh, writers, readers);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_release", "**mpi_file_release %F %G %G", fh, writers,
                                     readers);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_release(QMPI_Context context, int tool_id, MPI_File fh, MPI_Group writers,
                      MPI_Group readers)
{
    return internal_File_release(fh, writers, readers);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_release(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    QMPI_Context context;
    QMPI_File_release_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_release(context, 0, fh, writers, readers);

    fn_ptr = (QMPI_File_release_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_RELEASE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_RELEASE_T], fh, writers, readers);
}
#else /* ENABLE_QMPI */
int MPI_File_release(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    return internal_File_release(fh, writers, readers);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_acquire */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_acquire = PMPI_File_acquire
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_acquire  MPI_File_acquire
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_acquire as PMPI_File_acquire
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_acquire(MPI_File fh, MPI_Group writers, MPI_Group readers)
     __attribute__ ((weak, alias("PMPI_File_acquire")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_acquire
#define MPI_File_acquire PMPI_File_acquire
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_acquire(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_Ext_cs_enter();
    MPIR_FUNC_TERSE_ENTER;

    /* ... body of routine ... */
#ifndef HAVE_ROMIO
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER, "**notimpl", 0);
    goto fn_fail;
#else
    mpi_errno = MPIR_File_acquire_impl(fh, writers, readers);
    if (mpi_errno) {
        goto fn_fail;
    }
#endif
    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT;

    MPIR_Ext_cs_exit();
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLINE-- */
#ifdef HAVE_ERROR_CHECKING
    mpi_errno = MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                     "**mpi_file_acquire", "**mpi_file_acquire %F %G %G", fh, writers,
                                     readers);
#endif
    mpi_errno = MPIO_Err_return_file(fh, mpi_errno);
    /* --END ERROR HANDLING-- */
    goto fn_exit;
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_acquire(QMPI_Context context, int tool_id, MPI_File fh, MPI_Group writers,
                      MPI_Group readers)
{
    return internal_File_acquire(fh, writers, readers);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_acquire(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    QMPI_Context context;
    QMPI_File_acquire_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_acquire(context, 0, fh, writers, readers);

    fn_ptr = (QMPI_File_acquire_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_ACQUIRE_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_ACQUIRE_T], fh, writers, readers);
}
#else /* ENABLE_QMPI */
int MPI_File_acquire(MPI_File fh, MPI_Group writers, MPI_Group readers)
{
    return internal_File_acquire(fh, writers, readers);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_toint */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_toint = PMPI_File_toint
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_toint  MPI_File_toint
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_toint as PMPI_File_toint
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_File_toint(MPI_File file)  __attribute__ ((weak, alias("PMPI_File_toint")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_toint
#define MPI_File_toint PMPI_File_toint
#endif /* MPICH_MPI_FROM_PMPI */

static int internal_File_toint(MPI_File file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return (int) MPIR_File_c2f_impl(file);
#endif
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
int QMPI_File_toint(QMPI_Context context, int tool_id, MPI_File file)
{
    return internal_File_toint(file);
}
#endif /* MPICH_MPI_FROM_PMPI */
int MPI_File_toint(MPI_File file)
{
    QMPI_Context context;
    QMPI_File_toint_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_toint(context, 0, file);

    fn_ptr = (QMPI_File_toint_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_TOINT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_TOINT_T], file);
}
#else /* ENABLE_QMPI */
int MPI_File_toint(MPI_File file)
{
    return internal_File_toint(file);
}

#endif /* ENABLE_QMPI */

/* -- Begin Profiling Symbol Block for routine MPI_File_fromint */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_File_fromint = PMPI_File_fromint
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_File_fromint  MPI_File_fromint
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_File_fromint as PMPI_File_fromint
#elif defined(HAVE_WEAK_ATTRIBUTE)
MPI_File MPI_File_fromint(int file)  __attribute__ ((weak, alias("PMPI_File_fromint")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_File_fromint
#define MPI_File_fromint PMPI_File_fromint
#endif /* MPICH_MPI_FROM_PMPI */

static MPI_File internal_File_fromint(int file)
{
#ifndef HAVE_ROMIO
    return 0;
#else
    return MPIR_File_f2c_impl(file);
#endif
}

#ifdef ENABLE_QMPI
#ifndef MPICH_MPI_FROM_PMPI
MPI_File QMPI_File_fromint(QMPI_Context context, int tool_id, int file)
{
    return internal_File_fromint(file);
}
#endif /* MPICH_MPI_FROM_PMPI */
MPI_File MPI_File_fromint(int file)
{
    QMPI_Context context;
    QMPI_File_fromint_t *fn_ptr;

    context.storage_stack = NULL;

    if (MPIR_QMPI_num_tools == 0)
        return QMPI_File_fromint(context, 0, file);

    fn_ptr = (QMPI_File_fromint_t *) MPIR_QMPI_first_fn_ptrs[MPI_FILE_FROMINT_T];

    return (*fn_ptr) (context, MPIR_QMPI_first_tool_ids[MPI_FILE_FROMINT_T], file);
}
#else /* ENABLE_QMPI */
MPI_File MPI_File_fromint(int file)
{
    return internal_File_fromint(file);
}

#endif /* ENABLE_QMPI */
