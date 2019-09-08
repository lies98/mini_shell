# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"

char *redirection_sup(char * mot[],int MaxMot)
{ 
  char *dirsup=NULL;
  int  i=1;

    while (mot[i-1]!=NULL)
    {
        if (i == MaxMot){
         fprintf(stderr, "Erreur dans la fonction decouper: trop de mots\n");
         mot[i - 1] = 0;
        } 

        if (strcmp(mot[i-1],">")==0)
        {
            dirsup=malloc(strlen(mot[i])+1);
            dirsup[0]='w';
            dirsup[1]='\0';
            strcat(dirsup,mot[i]);  
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        else if (strcmp(mot[i-1],">>")==0)
        {
            dirsup=malloc(strlen(mot[i])+1);
            dirsup[0]='a';
            dirsup[1]='\0';
            strcat(dirsup,mot[i]);   
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        ++i;
    }
    return dirsup;
}