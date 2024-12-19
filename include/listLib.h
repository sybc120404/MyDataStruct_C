/*
    Author: Cai
    Data:   29Dec24
    Description:    C header of listLib
*/

/*==========================
    include files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*==========================
    macro definition
*/

#define IN
#define OUT

#define PFM_ENSURE_RET(cond, ret)    do{ \
    if(!(cond)){  \
        return (ret); \
    }   \
}while(0);

#define PFM_ENSURE_DONE(cond)    do{ \
    if(!(cond)){  \
        goto done;  \
    }   \
}while(0);

/*==========================
    typedef 
*/

/* error code */
typedef enum
{
    RET_VAL_NO_ERROR = 0,
    RET_VAL_NULL_POINTER,
    RET_VAL_BAD_PARAM,
    RET_VAL_NO_MEMORY,

    RET_VAL_END
}RET_VAL;

/* struct of list node */
typedef struct list_node
{
    void *pData;                /* data */
    struct list_node *next;     /* next filed */
}LIST_NODE;

/* struct of list manager */
typedef struct list
{
    LIST_NODE *headNode;        /*  */
    int len;                    /* length of list, exclude headNode */
}LIST;

/*==========================
    function declaration
*/

/*
    name:       listCreate
    brief:      create a list
    param_in:   None
    param_out:  None
    output:     error code
*/
RET_VAL listCreate();

/*
    name:       listDestory
    brief:      destroy a list
    param_in:   None
    param_out:  None
    output:     error code
*/
RET_VAL listDestory();