#ifndef STDIO_H
#include <stdio.h>
#endif
#ifndef STDLIB_H
#include <stdlib.h>
#endif
#ifndef DIRENT_H
#include <dirent.h>
#endif
#ifndef STRING_H
#include <string.h>
#endif
#define CONS_C 1

char *CNS_ls(char *PATH);


char *CNS_ls(char *PATH)
{
    char *flid = malloc(5000);
    struct dirent *de;
    DIR *dr = opendir(PATH);
  
    if (!dr) {
        printf("Could not open current directory" );
        return (char) 1;
    }
  
    while ((de = readdir(dr)) != NULL) {
        printf("%s ; ", de->d_name);
        strcat(flid, de->d_name);
        strcat(flid, ';');
    }
  
    closedir(dr);  struct dirent *de; 

    return flid;
}