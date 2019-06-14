#ifndef GRAPHTAD_H
#define GRAPHTAD_H

#define MAX_VERTEX 200

typedef struct {
	char nome[100];
	int ano;
	char genero[50];
	char sinopse[5000];
}Movie_Node;

typedef struct {
	int numVertex;
	Movie_Node adjMatrix[MAX_VERTEX][MAX_VERTEX];	
}Graph;


Graph *init();
void loadGraphValues(Graph *g, Movie_Node **movies, int moviesCount);

char **findRelatedMovies(char *movieTarget, int *n);
char **findUnrelatedMovies(char *movieTarget, int *n);
char **findSameCategory(char *movieTarget, int *n);

#endif
