#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct history
{
    char ** cmds;
    int pointer;
    int leng;
}

struct history *new_history()
{
    struct history *new;
    new = malloc(sizeof(struct history));
    new -> pointer = 0;
    new -> leng = 1;
    new -> cmds = (char **)malloc(1 * sizeof(char *));

    return new;
}

struct history *append(struct history h,char *line)
{
    if (line[0] == ' ') return h;
    if(h.pointer < h.leng)
    {
        h.cmds[h.pointer] = line;
    }
    else 
    {
        char **temp = (char **)malloc(h.leng * 2 * sizeof(char *));
        for(int i = 0; i < h.pointer ; i ++)
        {
            temp[i] = h.cmds[i];
        }
        temp[i] = line;
        h.cmds = temp;
    }

    return h;
}
