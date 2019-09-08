/* decouper.c
 Un wrapper autour de strtok
*/
# include <stdio.h>
# include <string.h>
 #include <glob.h>
 # include <stdlib.h>
#include "cmd.h"

/* decouper  --  decouper une chaine en mots */
void decouper(char * ligne, char * separ, char * mot[], int maxmot){
  int i=1;

  mot[0] = strtok(ligne, separ);

  while(mot[i-1] != 0){
      if (i == maxmot){
         fprintf(stderr, "Erreur dans la fonction decouper: trop de mots\n");
         mot[i - 1] = 0;
      } 


      char *p=strstr(mot[i-1],"*");

      if(p==NULL)
         ++i;
      else{
          glob_t gl;
          int _glob=glob(mot[i-1],0,NULL,&gl);
          if (_glob==0)
          {
            size_t j;
            for (j=0;j<gl.gl_pathc;++j)
            {
              mot[i-1]=strdup(gl.gl_pathv[j]);
              ++i;
            }
          }
          globfree(&gl);
      }
      mot[i-1] = strtok(NULL, separ);   
  }
  mot[i-1]=NULL;
}




# ifdef TEST
int
main(int ac, char * av[]){
  char *elem[10];
  int i;

  if (ac < 3){
    fprintf(stderr, "usage: %s phrase separ\n", av[0]);
    return 1;
  }

  printf("On decoupe '%s' suivant les '%s' :\n", av[1], av[2]);
  decouper(av[1], av[2], elem, 10);

  for(i = 0; elem[i] != 0; i++)
    printf("%d : %s\n", i, elem[i]);

  return 0;
}
# endif