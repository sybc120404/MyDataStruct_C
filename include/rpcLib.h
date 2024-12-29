/**
 * @file    rpcLib.h
 * @brief   RPC Library header File.
 *
 * 
 * @author  Cai
 * @date    29Dec24
 * @version 0.1
 * 
 * @note    
 */

#ifndef __RPCLIB_H__
#define __RPCLIB_H__

/*==========================
    include files
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "err.h"

/*==========================
    defines
*/

#define NAME_MAX_LEN 32

/*==========================
    type definition
*/

typedef struct _RPC_NODE
{
    int id;
    char name[NAME_MAX_LEN];
} RPC_NODE;

/**
 * @brief serialize a rpc node
 * 
 * @param node - rpc node
 * @return RET_VAL - error code
 */
RET_VAL serialize_rpc_node(IN RPC_NODE node, OUT unsigned char *data);

/**
 * @brief deserialize a rpc node
 * 
 * @param data - data
 * @param node - rpc nod
 * @return RET_VAL - error code
 */
RET_VAL deserialize_rpc_node(IN unsigned char *data, OUT RPC_NODE *node);

#endif