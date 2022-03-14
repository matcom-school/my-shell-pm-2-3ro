#include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MY_PROMPT "$>"

void my_prompt()
{

    char *login = getenv("USER") ;
    char direction[1000];
    char aux_direction[1000];
    char host_name[1000];
    char finaly_prompt[4000];
    char *temp;

    if(login == NULL) write(STDERR_FILENO,"error1",6);
    if(gethostname(host_name,1000) == -1) write(STDERR_FILENO,"error2",6);
    if(getcwd(aux_direction,1000) == NULL) write(STDERR_FILENO,"error3",6); 

    int count_back_slach = 0,j = 0;
    for (int  i = strlen(aux_direction) - 1 ; i  >= 0 ; i--)
    {
        if(aux_direction[i] == '/') count_back_slach ++;
        direction[j++] = aux_direction[i];
        
        if(count_back_slach == 3) break;
    }
    direction[j] = '\0';

    char swap;
    for(int i = 0; i < j/2 ; i++)
    {
        swap = direction[i];
        direction[i] = direction[j - 1 - i];
        direction[j - 1 - i] = swap;
    } 

    temp = strcpy(finaly_prompt,login);
    temp = strcat(finaly_prompt,"@");
    temp = strcat(finaly_prompt,host_name);
    temp = strcat(finaly_prompt," :~");
    temp = strcat(finaly_prompt,direction);
    temp = strcat(finaly_prompt,MY_PROMPT);
    
    write(STDOUT_FILENO,finaly_prompt,strlen(finaly_prompt));
}