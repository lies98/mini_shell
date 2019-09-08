# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"

# define PROMPT "? "





/*
void sleep_(char*line[MaxDirs])
{ int i;
  for ( i = 1; line[i]!=0; ++i)
     {

    sleep(atoi(line[i]));
  }
}

int monif(char *line,char*dirs[])
{ 
    char*fragment[MaxDirs];
    char*maxdir[MaxDirs];
    int pid;
    int statu;
    char path[MaxLigne];
    decouper(line,"&&",fragment,MaxLigne);
    for (int i = 0; fragment[i]!=0; ++i)
    {   
        decouper(fragment[i]," \t\n",maxdir,MaxDirs);
        pid=fork();
        if(pid==0)
        { 
          for(i = 0; dirs[i] != 0; i++)
              { 
                snprintf(path, sizeof path, "%s/%s", dirs[i], maxdir[0]);
                  execv(path, maxdir);
              }
            perror(maxdir[0]);
          exit(-1);
        }
      waitpid(pid,&statu,0);
      if(statu!=0)
          break;  
      
    }
    return 0;
  }
int monif_is_in(char * s)
{
  int i;
  for (i = 0; s[i+1]!='\0'; ++i)
  {
    if(s[i]=='&'  && s[i+1]=='&')
    return 1;
  }
  return 0;
}

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

char *redirection_err(char * mot[],int MaxMot)
{ 
  char *direrr=NULL;
  int  i=1;

    while (mot[i-1]!=NULL)
    {
        if (i == MaxMot){
         fprintf(stderr, "Erreur dans la fonction decouper: trop de mots\n");
         mot[i - 1] = 0;
        } 

        if (strcmp(mot[i-1],"2>")==0)
        {
            direrr=malloc(strlen(mot[i])+1);
            direrr[0]='w';
            direrr[1]='\0';
            strcat(direrr,mot[i]);  
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        else if (strcmp(mot[i-1],"2>>")==0)
        {
            direrr=malloc(strlen(mot[i])+1);
            direrr[0]='a';
            direrr[1]='\0';
            strcat(direrr,mot[i]);   
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        ++i;
    }
    return direrr;
}
char *redirection_out_err(char * mot[],int MaxMot)
{ 
  char *redirection=NULL;
  int  i=1;

    while (mot[i-1]!=NULL)
    {
        if (i == MaxMot){
         fprintf(stderr, "Erreur dans la fonction decouper: trop de mots\n");
         mot[i - 1] = 0;
        } 

        if (strcmp(mot[i-1],"2&>1")==0)
        {
            redirection=malloc(strlen(mot[i])+1);
            redirection[0]='w';
            redirection[1]='\0';
            strcat(redirection,mot[i]);  
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        else if (strcmp(mot[i-1],"2&>>1")==0)
        {
            redirection=malloc(strlen(mot[i])+1);
            redirection[0]='a';
            redirection[1]='\0';
            strcat(redirection,mot[i]);   
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        ++i;
    }
    return redirection;
}
char *redirection_err_out(char * mot[],int MaxMot)
{ 
  char *redirection=NULL;
  int  i=1;

    while (mot[i-1]!=NULL)
    {
        if (i == MaxMot){
         fprintf(stderr, "Erreur dans la fonction decouper: trop de mots\n");
         mot[i - 1] = 0;
        } 

        if (strcmp(mot[i-1],"1&>2")==0)
        {
            redirection=malloc(strlen(mot[i])+1);
            redirection[0]='w';
            redirection[1]='\0';
            strcat(redirection,mot[i]);  
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        else if (strcmp(mot[i-1],"1&>>2")==0)
        {
            redirection=malloc(strlen(mot[i])+1);
            redirection[0]='a';
            redirection[1]='\0';
            strcat(redirection,mot[i]);   
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        ++i;
    }
    return redirection;
}
char *redirection_tt(char * mot[],int MaxMot)
{ 
  char *dirtt=NULL;
  int  i=1;

    while (mot[i-1]!=NULL)
    {
        if (i == MaxMot){
         fprintf(stderr, "Erreur dans la fonction decouper: trop de mots\n");
         mot[i - 1] = 0;
        } 

        if (strcmp(mot[i-1],"&>")==0)
        {
            dirtt=malloc(strlen(mot[i])+1);
            dirtt[0]='w';
            dirtt[1]='\0';
            strcat(dirtt,mot[i]);  
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        else if (strcmp(mot[i-1],"&>>")==0)
        {
            dirtt=malloc(strlen(mot[i])+1);
            dirtt[0]='a';
            dirtt[1]='\0';
            strcat(dirtt,mot[i]);   
            while (mot[i+1]!=NULL)
            {
                mot[i-1]=mot[i+1];
                ++i;
            }
            mot[i-1]=NULL;
        }
        ++i;
    }
    return dirtt;
}
*/
int
main(int argc, char * argv[]){

  
  char ligne[MaxLigne];

  char pathname[MaxPathLength];
  char * mot[MaxMot];
  char * mot2[MaxMot];
  char * dirs[MaxDirs];
  int i , tmp;

  /* Decouper PATH en repertoires */
  
  

   decouper(getenv("PATH"), ":", dirs, MaxDirs);
  /* Lire et traiter chaque ligne de commande */


  for(printf(PROMPT); fgets(ligne, sizeof ligne, stdin) != 0; printf(PROMPT)){
    decouper(ligne, ";", mot, MaxMot);
    for ( i = 0; mot[i]!=0; ++i){

      if(monif_is_in(mot[i])==1){
          monif(mot[i],dirs);
          continue;
      }
    decouper(mot[i]," \t\n",mot2,MaxMot);

    if (mot2[0] == 0)            // ligne vide
      continue;

    if (strcmp("exit",mot2[0])==0)
    {       printf("bye \n");
            exit(0);
    }

    if(strcmp(mot2[0],"cd")==0)
    {   
      tmp=chdir(mot2[1]);
      if(tmp<0)
        {
          perror("cd");
        }

      continue;           
    }
    if(strcmp(mot2[0],"sleep")==0)
    {                           
      sleep_(mot2);
      continue;     
    }
 

    char *redirection;
    char *redirection_entrante;
    char *redirectionerr;
    char *redirectiontt;
    char *redirection2;
    char *redirection1;

    str_replace(ligne,"\n","");
    str_replace(ligne," <","<");
    str_replace(ligne,"< ","<");
    str_replace(ligne,"<"," < ");

    str_replace(ligne," >",">");
    str_replace(ligne,"> ",">");
    str_replace(ligne,">"," > ");

    str_replace(ligne," 2>","2>");
    str_replace(ligne,"2> ","2>");
    str_replace(ligne,"2>"," 2> ");

    str_replace(ligne," >  > "," >> ");
    str_replace(ligne," 2>  > "," 2>> ");
    str_replace(ligne," 2 >  > "," 2>> ");

    str_replace(ligne," &>","&>");
    str_replace(ligne,"&> ","&>");
    str_replace(ligne,"&>"," &> ");

    str_replace(ligne," &>  > "," &>> ");
    str_replace(ligne," & >  > "," &>> ");

    str_replace(ligne," 2&>1","2&>1");
    str_replace(ligne,"2&>1 ","2&>1");
    str_replace(ligne,"2&>1"," 2&>1 ");
    str_replace(ligne," 2&>  > 1"," 2&>>1 ");
    str_replace(ligne," 2& >  > 1"," 2&>>1 ");

    str_replace(ligne," 1&>2","1&>2");
    str_replace(ligne,"1&>2 ","1&>2");
    str_replace(ligne,"1&>2"," 1&>2 ");
    str_replace(ligne," 1&>  > 2"," 1&>> 2");
    str_replace(ligne," 1& >  > 2"," 1&>>2 ");


    redirection=redirection_sup(mot2,MaxMot);
    redirectionerr=redirection_err(mot2,MaxMot);
    redirectiontt=redirection_tt(mot2,MaxMot);
    redirection2=redirection_out_err(mot2,MaxMot);
    redirection1=redirection_err_out(mot2,MaxMot);
    redirection_entrante=redirection_inf(mot2);


    
    tmp = fork();               // lancer le processus enfant
    if (tmp < 0){
      perror("fork");
      continue;
    }

    if (tmp != 0){             // parent : attendre la fin de l'enfant
      while(wait(0) != tmp)
        ;
      continue;
    }
    if(tmp == 0){
    if (redirection_entrante!=NULL)
    {
        FILE *handler=freopen(redirection_entrante,"r", stdin);
        if (handler==NULL) 
        {
          fprintf(stderr,"%s\n",strerror(errno));
          exit(0);
        }
    }

    if (redirection!=NULL)
      {
        char* type_redirection=strndup(redirection,1);
        FILE *handler=freopen(redirection+1, type_redirection, stdout);
        if (handler==NULL) 
        {
          fprintf(stderr,"%s\n",strerror(errno));
          exit(0);
        }
        free(type_redirection);
      }    
      if (redirectionerr!=NULL)
      {
        char* type_redirection=strndup(redirectionerr,1);
        FILE* handler=freopen(redirectionerr+1, type_redirection, stderr);
        if (handler==NULL) 
        {
          fprintf(stderr,"%s\n",strerror(errno));
          exit(0);
        }
        free(type_redirection);
      }
      if (redirectiontt!=NULL)
      {
        char* type_redirection=strndup(redirectiontt,1);
        FILE* handler=freopen(redirectiontt+1, type_redirection, stdout);
        handler=freopen(redirectiontt+1,type_redirection, stderr);
        if (handler==NULL) 
        {
          fprintf(stderr,"%s\n",strerror(errno));
          exit(0);
        }
        free(type_redirection);
      }
      if (redirection2!=NULL)
      {
        char* type_redirection=strndup(redirection2,1);
        FILE* handler=freopen(redirection2+1, type_redirection, stdout);
        handler=freopen(redirection2+1,"a", stderr);
        if (handler==NULL) 
        {
          fprintf(stderr,"%s\n",strerror(errno));
          exit(0);
        }
        free(type_redirection);
      }
      if (redirection1!=NULL)
      {
        char* type_redirection=strndup(redirection1,1);
        FILE* handler=freopen(redirection1+1, type_redirection, stderr);
        handler=freopen(redirection1+1,"a", stdout);
        if (handler==NULL) 
        {
          fprintf(stderr,"%s\n",strerror(errno));
          exit(0);
        }
        free(type_redirection);
      }
     for(i = 0; dirs[i] != 0; i++){
      snprintf(pathname, sizeof pathname, "%s/%s", dirs[i], mot2[0]);
      execv(pathname, mot2);
    }            
      fprintf(stderr, "%s: not found\n", mot[0]);
      exit(1);
                                // 
  }

    if (redirection_entrante!=NULL) free(redirection_entrante);
    if (redirection!=NULL) free(redirection);


  }
}
 
  
  printf("Bye\n");
  return 0;

}