#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Library/parser.h"

char* q ()
{
    return "aaa";
}


int main()
{

    //prompt
    char *line = NULL;
    size_t leng_line = 0;
    int b = getline(&line,&leng_line,stdin);

    //analiza !histoy
    //guardar history(analizado e line)
    int i = 0;
    struct cmd *cmd = cmd_parser(line,&i);
    
   // print_cmd(*cmd);
    //printf("%d",cmd.index);
    //ejecutar
    //udgate bg


    //save history
    //save bg
    



    //int b = scanf("\n%s[^\n]" ,a );

    
    return 0;
}