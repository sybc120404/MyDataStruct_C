/**
 * @file
 * @brief C header file of lock
 *
 * 
 * 
 * @author Cai
 * @date 29Dec24
 * @version 1.0.0
 *
 * @note
 */

#ifndef _LOCK__
#define _LOCK__

/*==========================
    include files
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include "err.h"

/*==========================
    type definition
*/
typedef pthread_rwlock_t LOCK;

/*==========================
    function declaration
*/

/**
 * @brief create a mutex lock
 * 
 * @param mutex - ptr to mutex lock
 * @return RET_VAL - error code
 */
RET_VAL rwLockInit(OUT LOCK *rwLock);

/**
 * @brief destroy a mutex lock
 * 
 * @param mutex - ptr to mutex lock
 * @return RET_VAL - error code
 */
RET_VAL rwLockDestroy(IN LOCK *rwLock);

/**
 * @brief take a write lock
 * 
 * @param rwLock - ptr to rwlock
 * @return RET_VAL - error code
 */
RET_VAL rwLockWriteTake(IN LOCK *rwLock);

/**
 * @brief release a write lock
 * 
 * @param rwLock - ptr to rwlock
 * @return RET_VAL - error code
 */
RET_VAL rwLockWriteRelease(IN LOCK *rwLock);

/**
 * @brief take a read lock
 * 
 * @param rwLock - ptr to rwlock
 * @return RET_VAL - error code
 */
RET_VAL rwLockReadTake(IN LOCK *rwLock);

/**
 * @brief release a read lock
 * 
 * @param rwLock - ptr to rwlock
 * @return RET_VAL - error code
 */
RET_VAL rwLockReadRelease(IN LOCK *rwLock);

/*==========================
    macro definition
*/

#define LOCK_INIT(lock)     rwLockInit(&lock)
#define LOCK_DESTROY(lock)  rwLockDestroy(&lock)
#define LOCK_WRITE_TAKE(lock)   rwLockWriteTake(&lock)
#define LOCK_WRITE_RELEASE(lock)    rwLockWriteRelease(&lock)
#define LOCK_READ_TAKE(lock)    rwLockReadTake(&lock)
#define LOCK_READ_RELEASE(lock) rwLockReadRelease(&lock)

#endif