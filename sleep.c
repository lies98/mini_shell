# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"


void sleep_(char*line[MaxDirs])
{ int i;
  for ( i = 1; line[i]!=0; ++i)
     {

    sleep(atoi(line[i]));
  }
}