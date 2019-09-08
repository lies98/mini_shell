# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"

void str_replace(char *str,char* recherche,char *remplace)
{
int nbre=0;

    char *p=str;
    char *tmp=strstr(p,recherche);
    while (tmp!=NULL)
    {
        ++nbre;
        p=tmp+strlen(recherche);
        tmp=strstr(p,recherche);
    }
    if (nbre>0)
    {
        char *chaine_copie=malloc(strlen(str)-(strlen(recherche)*nbre)+(strlen(remplace)*nbre)+1);
        chaine_copie[0]='\0';
        char *p=str;
        char *tmp=strstr(p,recherche);
        while (tmp!=NULL)
        {
            strncat(chaine_copie,p,tmp-p);
            strcat(chaine_copie,remplace);
            p=tmp+strlen(recherche);
            tmp=strstr(p,recherche);
        }
        strcat(chaine_copie,p);
        strcpy(str,chaine_copie);
        free(chaine_copie);
    }
}