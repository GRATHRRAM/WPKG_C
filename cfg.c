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
#ifndef TIME_H
#include <time.h>
#endif
#ifndef CONS_C
#include "cons.c"
#endif


void _start_msg(void);
void _loop(short *err);
int _rnd(long seed);
char **FLM_ls(char *PATH);

/*
    START OF CODE
*/

void _start_msg(void)
{
    printf("---------------------------------\n");
    printf("- WPKG Writen in c by GRATHRRAM -\n");
    printf("- Original creator of WPKG is   -\n");
    printf("-           rafi612             -\n");
    printf("- version TST_DEV build in NULL -\n");
    printf("---------------------------------\n");
}

void _loop(short *err)
{
    char *inp = malloc(255);

    while (1)
    {
        printf("WPKG-> ");
        scanf("%255s", inp);

        if(strcmp(inp, "tts") == 0) _rnd(0);
        if(strcmp(inp, "xx") == 0) break;
        if(strcmp(inp, "clear") == 0) system("cls");
        if(strcmp(inp, "ls") == 0) CNS_ls(".");
    }
    
}


int _rnd(time_t seed)
{
    srand((unsigned) time(&seed));
    int rnd = rand();
    printf("%i\n", rnd);
    return rnd;
}