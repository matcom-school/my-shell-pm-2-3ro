
struct list
{
    char **element;
    int last;
    int leng;
};

//list method
struct list new_list();
void list_append(struct list *,char *);

typedef struct stream_op_node
{
    char *symbol;
    char *path;
    struct stream_op_node *next;
} StreamOpNode;

//stream_op_node methods
StreamOpNode new_stream_op_node(char *,char *);
//StreamOpNode *set_next_stream_op(StreamOpNode *,char *,char *);
void son_print(StreamOpNode);

typedef struct stream_op_list
{
    StreamOpNode *first;
    StreamOpNode *last;
    StreamOpNode *current;
    int leng;
} StreamOpList;

// stream_op_list methods
StreamOpList new_stream_op_list();
void stream_op_list_add(StreamOpNode ,StreamOpList *);
StreamOpNode stream_op_list_next(StreamOpList *);
void sol_print(StreamOpList);


struct cmd
{
    int index;
    char *name;
    struct list params; 
    StreamOpList stream_op_list;
    struct cmd *cmd_for_pipe;
};

//cmd method
struct cmd new_cmd();
void cmd_add_param(char *, struct cmd*);
void print_cmd(struct cmd);

//parser methods
struct cmd *cmd_parser(char *,int *);
void stream_parser(char *, int *,StreamOpList *);