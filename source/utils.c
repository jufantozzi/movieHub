#include <stdio.h>
#include <stdlib.h>
#include "graphTad.h"

Movie_Node **getMovies(char *moviePath, int *totalMovies){
	FILE *fp = fopen(moviePath, "r");
	if (!fp){
		printf("couldnt load moviePath.");
		exit(-1);
	}

	int moviesCount = 0;
	Movie_Node **movies = (Movie_Node**)malloc(sizeof(Movie_Node*) * (moviesCount+1));
	while(!feof(fp)){ 
		movies[moviesCount] = (Movie_Node*)malloc(sizeof(Movie_Node));

 		fscanf(fp, "%[^\n]", movies[moviesCount]->nome);			
		fscanf(fp, "%*c%d%*c", &movies[moviesCount]->ano);
		fscanf(fp, "%[^\n]%*c", movies[moviesCount]->genero);
		fscanf(fp, "%[^\n]%*c", movies[moviesCount]->sinopse);

		moviesCount++;
		movies = (Movie_Node**)realloc(movies, sizeof(Movie_Node*) * (moviesCount+1));
	}
	printf("moviescount = %d\n", moviesCount);
	*totalMovies = moviesCount;
	fclose(fp);
	return movies;
}

char *getTarget() {
	char *s;
	scanf("%ms%*c", &s);
	return s; 
}

int op(){
	int i;
	scanf("%d%*c", &i);
	return i; 	
}

int lexicalCompare(char *s1, char *s2){
	return 1;
}