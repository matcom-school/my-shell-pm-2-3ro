all: compiler execute delete

execute:
	./a.out

delete:
	rm list.o stream_op_list.o stream_op_node.o cmd.o parser.o MyShell.o background.o history.o execute_cd.o execute.o shell_Execute.o

compiler:  list.o stream_op_list.o stream_op_node.o  cmd.o parser.o MyShell.o background.o history.o execute_cd.o execute.o shell_Execute.o
	gcc  list.o stream_op_list.o stream_op_node.o cmd.o parser.o MyShell.o background.o history.o execute_cd.o execute.o shell_Execute.o

MyShell.o:
	gcc -c MyShell.c Library/parser.h 

parser.o : 
	gcc -c Library/parser.c Library/parser.h

cmd.o: 
	gcc -c Library/cmd.c Library/parser.h

stream_op_node.o: 
	gcc -c Library/stream_op_node.c Library/parser.h

stream_op_list.o: 
	gcc -c Library/stream_op_list.c Library/parser.h

list.o:
	gcc -c Library/list.c Library/parser.h
background.o:
	gcc -c Library/background_node.c Library/parser.h

execute.o:
	gcc -c Library/execute.c Library/parser.h

shell_Execute.o:
	gcc -c Library/shell_Execute.c Library/parser.h

history.o:
	gcc -c Library/history.c Library/parser.h

execute_cd.o:
	gcc -c Library/execute_cd.c Library/parser.h


