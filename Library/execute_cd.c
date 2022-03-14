#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int cd_execute(char **code)
{
    if(strcmp(code[0],"cd") && code[1] != NULL && code[2] == NULL ) return chdir(code[1]);
    else write(STDERR_FILENO,"CDError", 7);

    return -1;
}