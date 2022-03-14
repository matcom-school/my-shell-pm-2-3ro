#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

/*
struct stream_op_list
    struct stream_op_node *first
    struct stream_op_node *last
    struct stream_op_node *current
    int leng
*/

StreamOpList new_stream_op_list() 
{
    StreamOpList result;
    result.first = NULL;
    result.last = NULL;
    result.current = NULL;
    result.leng = 0; 

    return result;
}

void stream_op_list_add(StreamOpNode element,StreamOpList *this)
{
    if(this -> leng == 0)
    {
        this -> last = (StreamOpNode *)malloc(sizeof(StreamOpNode));
        this -> first = (StreamOpNode *)malloc(sizeof(StreamOpNode));
        *(this -> last) = *(this -> first) = element;
    }
    else
    {
        this -> last -> next = (StreamOpNode *)malloc(sizeof(StreamOpNode));
        *(this -> last -> next) = element;
        *(this -> last) = element;
    }

    this -> leng ++;
}
//probar que pasas *null
int stream_op_list_next(StreamOpList *this)
{
    StreamOpNode *result;
    if(this -> current == NULL)
    {
        this -> current = (StreamOpNode *)malloc(sizeof(StreamOpNode));
        result = this -> first;
    }
    else
        result = this -> current -> next;
    this -> current = result;
    
    return result != NULL;
}



void sol_print(StreamOpList list)
{
    printf("[ ");
    while(stream_op_lisst_next(&list))
    {   
        son_print(*(list.current));
    }
    printf(" ]\n");
}