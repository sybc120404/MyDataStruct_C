/*
    Author: Cai
    Data:   25Dec24
    Description:    C header of common define
*/

#ifndef _DEF__
#define _DEF__

/*==========================
    include files
*/
#include "debug.h"

/*==========================
    macro definition
*/

/* helper of param direction */
#define IN
#define OUT

/* check condition, if false == cond, return ret */
#define PFM_ENSURE_RET(cond, ret)    do{ \
    if(!(cond)){  \
        DBG_ERR("ensure true == cond fail");    \
        return (ret); \
    }   \
}while(0);

/* check condition, if false == cond, ret = err, and goto done */
#define PFM_ENSURE_DONE(cond, ret, err)    do{ \
    if(!(cond)){  \
        DBG_ERR("ensure true == cond fail");    \
        (ret) = (err);  \
        goto done;  \
    }   \
}while(0);

#endif