/**
 * @file
 * @brief This file is used for testing rpc functionality.
 */

#include "rpcLib.h"

int main()
{
    RPC_NODE node = {1,"node1"};
    RPC_NODE nodeTmp = {0};
    unsigned char data[2*NAME_MAX_LEN] = {0};

    serialize_rpc_node(node, data);
    deserialize_rpc_node(data, &nodeTmp);

    printf("nodeTmp.id = %d, nodeTmp.name = %s\n", nodeTmp.id, nodeTmp.name);

    return 0;
}