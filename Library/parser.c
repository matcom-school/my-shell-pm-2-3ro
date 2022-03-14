#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

char *work_parser(char *code,int *index);

void jump_spaces(int *index, char *code)
{
    while(code[*index] == ' ') { (*index) ++; }
}

struct cmd *cmd_parser(char *code,int *index)
{
    int len = strlen(code) - 1;
    if(*index > len)
        return NULL;
    
    struct cmd *result = malloc(sizeof(struct cmd)); 
    *result = new_cmd();
    
    
    stream_parser(code,index, &(result -> stream_op_list));
    result -> name = (char *) work_parser(code,index);
  
    
    int i = 0;
    while((*index) < len && code[*index] != '|')
    {
        stream_parser(code,index,&(result -> stream_op_list));
        char * param = (char *)work_parser(code,index);
        cmd_add_param(param,result);
       // printf("%s \n",result -> params.element[i++]); 
    }
/*
    if(code[*index] == '|') 
    {
        result.cmd_for_pipe = cmd_parser(code,index +1);
    }
*/

    return result;
}

void stream_parser(char *code, int *index , StreamOpList *list)
{
    if(code[*index] == '<' || code[*index] == '>')
    {
        char *symbol = (char *)malloc(2* sizeof(char));
        char *path;

        if(code[*index] == '>' && code[*index] == '>')
        {
            (*index) += 2;
            symbol = ">>";
        }
        else 
        {
            symbol[0] = code[*index];
            symbol[1] = '\0';
            (*index) ++;
        }
        jump_spaces(index,code);
        path = work_parser( code, index);

        StreamOpNode new_node = new_stream_op_node(symbol,path);
        stream_op_list_add( new_node, list);
       
        stream_parser(code,index,list);
    }

    return;
}

char *work_parser(char *code,int *index)
{
    int leng = strlen(code) - 1;
    if(*index >= leng) return NULL;
    
    int i = *index;
    while(i < leng && code[i] != '>' && code[i] != '<' && code[i] != '|' && code[i] != '&'&& code[i] != ' ' ) { i++; }
    char *work = (char *) malloc((i - *index + 1) * sizeof(char));

    int j = 0;
    for( ; *index < i;  (*index) ++)
    {
        work[j++] = code[*index];  

    }
    work[j] = code[leng];
    jump_spaces(index,code);

    return work;
}