# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"

char *redirection_inf(char * mot[])
{
char *disinf=NULL;
int  i=1;

    while (mot[i-1]!=NULL)
    {
        if (strcmp(mot[i-1],"<")==0)
        {
            disinf=mot[i];

            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        ++i;
    }
    return disinf;
}