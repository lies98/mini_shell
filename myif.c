# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"

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