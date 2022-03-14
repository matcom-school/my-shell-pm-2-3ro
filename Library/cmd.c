#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

/*
struct cmd
    int index;
    char *name;
    struct list params; //google cmd con mas parametros
    struct stream_op *stream_op;
    struct cmd *cmd_for_pipe;
*/


struct cmd new_cmd()
{
    struct cmd cmd;
    cmd.stream_op_list = new_stream_op_list();
    cmd.params = new_list();
    cmd.index = 0;

    return cmd;
}

void cmd_add_param(char *param, struct cmd *cmd)
{
    if(param == NULL) return;
    list_append(&(cmd -> params),param);
    return;
}

void print_cmd(struct cmd a)
{
    printf("%s\n{\n",a.name);
    print_list(a.params);
    sol_print(a.stream_op_list);
    printf("}\n");
}
