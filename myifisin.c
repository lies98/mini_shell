# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <assert.h>
# include <string.h>
#include <errno.h>
#include "cmd.h"

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