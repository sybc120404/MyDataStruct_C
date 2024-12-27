/*
    Author: Cai
    Data:   25Dec24
    Description:    C header of common define
*/

#ifndef _DEF__
#define _DEF__

/*==========================
    macro definition
*/

/* helper of param direction */
#define IN
#define OUT

/* check condition, if false == cond, return ret */
#define PFM_ENSURE_RET(cond, ret)    do{ \
    if(!(cond)){  \
        return (ret); \
    }   \
}while(0);

/* check condition, if false == cond, ret = err, and goto done */
#define PFM_ENSURE_DONE(cond, ret, err)    do{ \
    if(!(cond)){  \
        (ret) = (err);  \
        goto done;  \
    }   \
}while(0);

#endif