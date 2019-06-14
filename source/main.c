#include <stdio.h>
#include <stdlib.h>

#include "print_functions.h"
#include "graphTad.h"
#include "utils.h"

char *moviePath = "assets/movies.txt";

int main(int argc, char const *argv[]){
	int operation, moviesCount;
	char *target;
	Graph *g = init();

	g->nodeList = getMovies(moviePath, &moviesCount);
 
 	calculateEdges(g, moviesCount);

	do{
		printHeader();
		
		operation = op();
		
		switch(operation){
			case 1:
				printSelectTarget();
				target = getTarget();
				printRelatedMovies(g, target);
				free(target);
				break;
			case 2:
				printSelectTarget();
				target = getTarget();
				printUnrelatedMovies(g, target);
				free(target);
				break;
			case 3:
				target = getTarget();
				printSelectTarget();
				printSameCategory(g, target);
				free(target);
				break;
			case 4:
				printExit();
				break;
			default:
				printError();
		}
	}
	while(operation != EXIT);
	
	for(int i=0; i<moviesCount; i++){
		free(g->nodeList[i]);
	}
	free(g->nodeList); free(g);
	return 0;
}