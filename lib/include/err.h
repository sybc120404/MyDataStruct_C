/*
    Author: Cai
    Data:   25Dec24
    Description:    C header of error
*/

#ifndef _ERR__
#define _ERR__

/*==========================
    typedef 
*/

/* error code */
typedef enum
{
    RET_VAL_NO_ERROR = 0,   /* no error */
    RET_VAL_NULL_POINTER,   /* null pointer */
    RET_VAL_BAD_PARAM,      /* bad param */
    RET_VAL_NO_MEMORY,      /* no memory */
    RET_VAL_SYS_ERR,        /* system error */

    RET_VAL_END
}RET_VAL;

#endif