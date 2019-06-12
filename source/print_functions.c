#include <stdio.h>
#include <stdlib.h>
#include "graphTad.h"

void printHeader(){
	puts("================MOVIE HUB==============");
	puts("Selecione a opção desejada:");
	puts("(1) - Filmes relacionados");
	puts("(2) - Filmes aversos");
	puts("(3) - Filmes de uma mesma categoria");
	puts("(4) - Sair");
	puts("================MOVIE HUB==============");
}

void printSelectTarget(){
	puts("Digite o titulo alvo...");
}

void printExit(){
	puts("Saindo...");
}

void printError(){
	puts("Opção invalida! Por favor escolha uma opção valida.");
}

void printRelatedMovies(Graph *g, char *movieTarget){
	int n;
	char **relatedMovies = findRelatedMovies(movieTarget, &n);
	
	for(int i=0;i<n;i++){
		printf("%s\n", relatedMovies[i]);
		free(relatedMovies[i]);
	}

	free(relatedMovies);
	return;
}

void printUnrelatedMovies(Graph *g, char *movieTarget){
	int n;
	char **unrelatedMovies = findUnrelatedMovies(movieTarget, &n);
	
	for(int i=0;i<n;i++){
		printf("%s\n", unrelatedMovies[i]);
		free(unrelatedMovies[i]);
	}

	free(unrelatedMovies);
	return;
}

void printSameCategory(Graph *g, char *movieTarget){
	int n;
	char **sameCategory = findSameCategory(movieTarget, &n);
	
	for(int i=0;i<n;i++){
		printf("%s\n", sameCategory[i]);
		free(sameCategory[i]);
	}

	free(sameCategory);
	return;
}

