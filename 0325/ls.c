///
/// @file     ls.c
/// @author   Tavis(honeytavis@aliyun.com)
/// @date     2016-03-25 18:42
///

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>

int main(int argc, char** argv)
{
  DIR* pDir = opendir(argv[1]);
  if (pDir == NULL) {
    perror("opendir()"); 
    exit(-1); 
  }

  struct dirent* pDirInfo = NULL; 
  while((pDirInfo = readdir(pDir)) != NULL) {
    if (strcmp(pDirInfo->d_name, ".") && strcmp(pDirInfo->d_name, "..")) {
      printf("%s\n", pDirInfo->d_name); 
    }
  }

  closedir(pDir); 

  return 0; 
}
