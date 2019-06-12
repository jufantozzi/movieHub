#ifndef GRAPHTAD_H
#define GRAPHTAD_H

#define MAX_VERTEX 200

typedef struct {
	char nome[100];
	char genero[50];
	char sinopse[5000];
	int isValid;
}Movie_Node;

typedef struct {
	int numVertex;
	Movie_Node adjMatrix[MAX_VERTEX][MAX_VERTEX];	
}Graph;


Graph *init();
void loadData(Graph *g);

char **findRelatedMovies(char *movieTarget, int *n);
char **findUnrelatedMovies(char *movieTarget, int *n);
char **findSameCategory(char *movieTarget, int *n);

#endif
