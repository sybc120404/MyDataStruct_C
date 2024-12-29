/**
 * @file    rpcLib.c
 * @brief   RPC Library Source File.
 *
 * Detailed description of the file's purpose and functionality.
 * 
 * @author  Cai
 * @date    29Dec24
 * @version 0.1
 * 
 * @note    
 */

#include "rpcLib.h"

/*==========================
    data declaration
*/

/*==========================
    static function definition
*/

/*==========================
    function definition
*/

RET_VAL serialize_rpc_node(IN RPC_NODE node, OUT unsigned char *data)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != data, ret, RET_VAL_BAD_PARAM);

    memcpy(data, &(node.id), sizeof(int));
    memcpy(data+sizeof(int), node.name, NAME_MAX_LEN);

done:
    return ret;
}

RET_VAL deserialize_rpc_node(IN unsigned char *data, OUT RPC_NODE *node)
{
    RET_VAL ret = RET_VAL_NO_ERROR;

    PFM_ENSURE_DONE(NULL != data && NULL != node, ret, RET_VAL_BAD_PARAM);

    memcpy(&(node->id), data, sizeof(int));
    memcpy((*node).name, data+sizeof(int), NAME_MAX_LEN);

done:
    return ret;
}