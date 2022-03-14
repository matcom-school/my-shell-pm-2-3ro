#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

void pre_parser(char **code)
{
    int leng = strlen(*code);
    char *new_code = "";

    for(int i = 0; i < leng; i++)
    {
        if((*code)[i] == '!')
        {
            
            new_code = strcat(new_code,history);
        }
        if((*code)[i] == '"')
        {   
            int pivot = i;
            while((*code)[i] != '"') {i++;}
            char *work = (char *)malloc((i - pivot + 1) * sizeof(char);)

            for(int j = 0;pivot < i; pivot++)
                work[j ++] = code[pivot];

            new_code = strcat(new_code,"$");

        }
    }

    return 0;
}