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

#define PFM_ENSURE_DONE(cond, ret, err)    do{ \
    if(!(cond)){  \
        (ret) = (err);  \
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
    LIST_NODE *headNode;        /* head node of list */
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
RET_VAL listCreate(OUT LIST *list);

/*
    name:       listDestory
    brief:      destroy a list
    param_in:   list - ptr to list
    param_out:  None
    output:     error code
*/
RET_VAL listDestory(LIST *list);

/*
    name:       listLenGet
    brief:      get length of a list, exclude listHead
    param_in:   list - ptr to list
    param_out:  listLen - ptr to length of list
    output:     error code
*/
RET_VAL listLenGet(IN LIST *list, OUT int *listLen);

/*
    name:       listNodeAdd
    brief:      add a node in idx of list
    param_in:   list - ptr to list
                pData - ptr to data of node
                idx - index of node to add, idx start from 1
    param_out:  None
    output:     error code
*/
RET_VAL listNodeAdd(IN LIST *list, void *pData, IN int idx);