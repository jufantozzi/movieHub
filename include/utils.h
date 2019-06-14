#ifndef UTILS_H
#define UTILS_H
#include "graphTad.h"


int op();
char *getTarget();
int lexicalCompare(char *s1, char *s2);
Movie_Node **getMovies(char *moviePath, int *moviesCount);

#endif
