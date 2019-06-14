#include <stdio.h>
#include <stdlib.h>
#include "graphTad.h"
#include "utils.h"

Graph *init(){
	return (Graph*)malloc(sizeof(Graph));
}

void loadGraphValues(Graph *g, int moviesCount){
	if (moviesCount > MAX_VERTEX) {
		printf("Maximum size reached.");
		exit(-1);
	}
	//calculate edge values
	for(int i=0; i<moviesCount; i++){
		for(int j=0; j<moviesCount; j++){
			if(i != j) 
				g->m[i][j] = lexicalCompare(g->nodeList[i]->sinopse, 
					g->nodeList[j]->sinopse);
		}
	}
}

//findRelatedMovies runs a graph search algorithm for related movies 
char **findRelatedMovies(char *movieTarget, int *n){
	return NULL;
}

//findUnrelatedMovies runs a graph search algorithm for unrelated movies 
char **findUnrelatedMovies(char *movieTarget, int *n){
	return NULL;
}

//findSameCategory runs a graph search algorithm for same category movies 
char **findSameCategory(char *movieTarget, int *n){
	return NULL;
}