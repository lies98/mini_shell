# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>

enum {
  MaxLigne = 1024,              // longueur max d'une ligne de commandes
  MaxMot = MaxLigne / 2,        // nbre max de mot dans la ligne
  MaxDirs = 100,		// nbre max de repertoire dans PATH
  MaxPathLength = 512,		// longueur max d'un nom de fichier
};

void decouper(char *, char *, char **, int);
void sleep_(char**);
int monif(char *,char**);
int monif_is_in(char *);
void str_replace(char *,char*,char *);
char *redirection_sup(char **,int );
char *redirection_inf(char **);
char *redirection_err(char **,int);
char *redirection_out_err(char **,int);
char *redirection_err_out(char **,int);
char *redirection_tt(char **,int);
