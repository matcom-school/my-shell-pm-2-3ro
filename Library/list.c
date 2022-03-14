#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

/*
struct list
    char *element[1];
    int last;
    int leng
*/

struct list new_list()
{
    struct list newlist;
    newlist.element = (char **) malloc(sizeof(char *));
    newlist.last = -1;
    newlist.leng = 1;

    return newlist;
}

void list_append(struct list *list,char *line)
{
   
    if(list -> last < list -> leng - 1)
    {
        list -> element[ ++ (list -> last) ] = line;
    }
    else 
    {
        char **temp = (char **)malloc( list -> leng * 2 * sizeof(char *));
        int i = 0;
        for(; i < list -> last ; i ++)
        {
            temp[i] = list -> element[i];
        }
        temp[i] = line;
        
        list -> element = temp;
        list -> leng = list -> leng * 2;

    }

    return;
}

void print_list(struct list l)
{
    printf("[ ");
    for (int i = 0; i < l.last; i++)
    {
        printf("%s ," ,l.element[i]);
    }
    printf(" ]\n");
}