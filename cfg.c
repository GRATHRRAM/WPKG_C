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

#ifdef _WIN32
#define clear system("cls")
#endif

#ifdef linux
#define clear system("clear")
#endif



void _start_msg(void);
void _loop(short *err);
int _rnd(long seed);
void _help(int page);
void _get_input(char *val);
char *getstr();

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
    while (1)
    {
        printf("WPKG-> ");
        char *inp = getstr();

        if(strcmp(inp, "tts") == 0) _rnd(0);
        if(strcmp(inp, "xx") == 0) break;
        if(strcmp(inp, "clear") == 0) clear;
        if(strcmp(inp, "ls") == 0) CNS_ls(".");
        if(strcmp(inp, "help") == 0) _help(0);

        free(inp);
    } 
}


int _rnd(time_t seed)
{
    srand((unsigned) time(&seed));
    int rnd = rand() % 87807571;
    printf("%i\n", rnd);
    return rnd;
}

void _help(int page)
{
  printf("tts -> test message (random number)\n");
  printf("clear -> clears screen\n");
  printf("help -> this\n");
  printf("ls -> lists contents of curent folder\n");
  printf("xx -> exits from wpkg\n");
}

char *getstr() {
  size_t cr = 1, i = 0;
  char *buf = malloc(sizeof(char) * cr);
  if (!buf)
    return NULL;

  char ch = getchar(); 
  while (ch != EOF && ch != '\n') {
    buf[i] = ch;
    if (i == cr - 1) { 
      cr++; 
      char *new = realloc(buf, sizeof(char) * cr);
      if (!new) 
        return buf; 
      
      buf = new; 
    }
    
    ch = getchar();
    i++;
  }
  buf[i] = '\0';

  return buf;
 }