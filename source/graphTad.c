#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "graphTad.h"
#include "compare.h"
#include "utils.h"

#define _GNU_SOURCE

Graph *init(){
	return (Graph*)malloc(sizeof(Graph));
}
int compar_adj(const void *a, const void *b, void *r) {
	double *rd = (double *)r;
	int u = *(int *)a;
	int v = *(int *)b;
	double temp = rd[u]-rd[v];
	if (fabs(temp) < 1e-6) return 0;
	if (temp < 0) return -1;
	return 1;
}

// 2089. Elizabeth Shaw (Noomi Rapace) e Charlie Holloway (Logan Marshall-Green) sãoexploradores que encontram a mesma pintura em várias cavernas na Terra. Com base nisto,eles desenvolvem uma teoria em que a pintura aponta para um lugar específico do universo,que teria alguma relação com o início da vida no planeta. A dupla convence um milionário,Peter Weyland (Guy Pearce), a bancar uma cara expedição interestelar para investigar oassunto. Desta forma, Elizabeth e Charlie entram para a tripulação da nave Prometheus,composta pelo robô David (Michael Fassbender), a diretora Meredith Vickers (CharlizeTheron), o capitão Janek (Idris Elba), entre outros. Todos, com exceção de David, hibernamem sono criogênico até que a nave chegue ao objetivo, o que acontece em 2093. Encantadoscom a descoberta de um novo mundo e a possibilidade de revelarem o segredo da origem davida na Terra, Elizabeth e Charlie não percebem que o local é também bastante perigoso.
void calculateEdges(Graph *g, int moviesCount){
	if (moviesCount > MAX_VERTEX) {
		printf("Maximum size reached.");
		exit(-1);
	}

	trie_t *trie = newTrie();
	char **words = NULL;
	int nWords = 0, *start = malloc(sizeof(int)*g->numVertex), *end = malloc(sizeof(int)*g->numVertex);

	for (int i = 0; i < g->numVertex; i++) {
		char *sin = g->nodeList[i]->sinopse;
		int len = strlen(sin);
		start[i] = nWords;
		for (int j = 0; j < len; j++) {
			if (!isalpha(sin[j])) continue;
			int k = j;
			while (k < len && isalpha(sin[k])) k++;
			words = realloc(words, (nWords + 1) * sizeof(char *));
			words[nWords++] = calloc(k-j+1, sizeof(char));
			strncpy(words[nWords-1], sin+j, k-j);
			
			for(int l=0; l<k-j; l++) words[nWords-1][l] = tolower(words[nWords-1][l])-'a';
			get(trie, words[nWords-1]);
			j = k;
		}
		end[i] = nWords;
	}
	for (int i = 0; i < g->numVertex; i++) {
		double *v = calloc(trie->size, sizeof(double));
		for (int j = start[i]; j < end[i]; j++) v[get(trie, words[j])]++;
		normalize(v, trie->size);
		g->nodeList[i]->sinopseVec = v;
	}	


	//calculate edge values
	for(int i=0; i<moviesCount; i++){
		for(int j=0; j<moviesCount; j++){
			g->p[i][j] = j;
			if(i != j) {
				g->m[i][j] = lexicalCompare(g->nodeList[i]->sinopseVec, 
					g->nodeList[j]->sinopseVec, trie->size);
			}
		}
		qsort_r(g->p[i], moviesCount, sizeof(int), compar_adj, g->m[i]);
		for (int k = 0; k < moviesCount; k++) {
			int j = g->p[i][k];
			printf("%s %s %lf\n", g->nodeList[i]->nome, g->nodeList[j]->nome, g->m[i][j]);
		}
	}

	free(start);
	free(end);
}
//findRelatedMovies runs a graph search algorithm for related movies 
char **findRelatedMovies(Graph *g, char *movieTarget, int *n){
	int index = getTargetIndex(g, movieTarget);
	for(int i=0; i<MAX_RELATED; i++){
		Movie_Node *r = g->nodeList[g->p[index][g->numVertex-1-i]];
	}	
	return NULL;
}

//findUnrelatedMovies runs a graph search algorithm for unrelated movies 
char **findUnrelatedMovies(Graph *g, char *movieTarget, int *n){
	return NULL;
}

//findSameCategory runs a graph search algorithm for same category movies 
char **findSameCategory(Graph *g, char *movieTarget, int *n){
	return NULL;
}