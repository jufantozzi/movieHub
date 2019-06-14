#ifndef GRAPHTAD_H
#define GRAPHTAD_H

#define MAX_VERTEX 200

typedef struct {
	char nome[100];
	int ano;
	char genero[50];
	char sinopse[5000];

	
	char isVertex, isEdge;
}Movie_Node;

typedef struct {
	int numVertex;
	Movie_Node **nodeList;
	int m[MAX_VERTEX][MAX_VERTEX];	
}Graph;


Graph *init();
void loadGraphValues(Graph *g, int moviesCount);

char **findRelatedMovies(char *movieTarget, int *n);
char **findUnrelatedMovies(char *movieTarget, int *n);
char **findSameCategory(char *movieTarget, int *n);

#endif
