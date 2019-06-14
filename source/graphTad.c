#include <stdio.h>
#include <stdlib.h>
#include "graphTad.h"

Graph *init(){
	return (Graph*)malloc(sizeof(Graph));
}

void loadGraphValues(Graph *g, Movie_Node **movies, int moviesCount){
	if (moviesCount > MAX_VERTEX) {
		printf("Maximum size reached.");
		exit(-1);
	}
	for(int i=0; i<moviesCount; i++){
		g->adjMatrix[i][i] = *movies[i];
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