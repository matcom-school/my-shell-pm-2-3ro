#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

/*
struct stream_op
    char *symbol;
    char *path;
    struct stream_op *next;
*/

StreamOpNode new_stream_op_node(char *symbol,char *path)
{
    StreamOpNode stream_op;
    stream_op.symbol = symbol;
    stream_op.path = path;
    stream_op.next = NULL;
    
    return stream_op;
}
/*
StreamOpNode *set_next_stream_op(StreamOpNode *father,char *symbol,char *path)
{
    if(father == NULL)
    {   
        StreamOpNode temp = new_stream_op(symbol,path);
        return &temp;
    }
    else 
        father -> next = set_next_stream_op(father -> next, symbol, path);
    return father;
}
*/

void son_print(StreamOpNode node)
{
    printf("%s %s ,", node.symbol, node.path);
}