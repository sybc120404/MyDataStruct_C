/**
 * @file
 * @brief C file of lock
 *
 * 
 * 
 * @author Cai
 * @date 29Dec24
 * @version 1.0.0
 *
 * @note
 */

/*==========================
    include files
*/
#include "lockLib.h"

/*==========================
    data declaration
*/

/*==========================
    static function definition
*/

/*==========================
    function definition
*/

RET_VAL rwLockInit(OUT LOCK *rwLock)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != rwLock, ret, RET_VAL_BAD_PARAM);

    if(pthread_rwlock_init(rwLock, NULL))
    {
        DBG_ERR("init rwlock failed");
        ret = RET_VAL_SYS_ERR;
        goto done;
    }

done:
    return ret;
}

RET_VAL rwLockDestroy(IN LOCK *rwLock)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != rwLock, ret, RET_VAL_BAD_PARAM);

    if(pthread_rwlock_destroy(rwLock))
    {
        DBG_ERR("destroy rwlock failed");
        ret = RET_VAL_SYS_ERR;
        goto done;
    }

done:
    return ret;
}

RET_VAL rwLockWriteTake(IN LOCK *rwLock)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != rwLock, ret, RET_VAL_BAD_PARAM);

    if(pthread_rwlock_wrlock(rwLock))
    {
        DBG_ERR("take rwlock failed");
        ret = RET_VAL_SYS_ERR;
        goto done;
    }

done:
    return ret;
}

RET_VAL rwLockWriteRelease(IN LOCK *rwLock)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != rwLock, ret, RET_VAL_BAD_PARAM);

    if(pthread_rwlock_unlock(rwLock))
    {
        DBG_ERR("release rwlock failed");
        ret = RET_VAL_SYS_ERR;
        goto done;
    }

done:
    return ret;
}

RET_VAL rwLockReadTake(IN LOCK *rwLock)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != rwLock, ret, RET_VAL_BAD_PARAM);

    if(pthread_rwlock_rdlock(rwLock))
    {
        DBG_ERR("take rwlock failed");
        ret = RET_VAL_SYS_ERR;
        goto done;
    }

done:
    return ret;
}

RET_VAL rwLockReadRelease(IN LOCK *rwLock)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != rwLock, ret, RET_VAL_BAD_PARAM);

    if(pthread_rwlock_unlock(rwLock))
    {
        DBG_ERR("release rwlock failed");
        ret = RET_VAL_SYS_ERR;
        goto done;
    }

done:
    return ret;
}