#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Tipo;

typedef struct{
	Tipo* array;
	int qtde;
	int tam;
}Queue;

Queue* queue_cria(); // feita
void queue_desaloca(Queue* Q); // feita
void queue_insere(Queue* Q, Tipo elemento, int pos); // feita
void queue_insere_fim(Queue* Q, Tipo elemento); // feita
Tipo* queue_remove(Queue* Q, int pos); // feita
int queue_remove2(Queue* Q, int pos, Tipo* ende); // feita
Tipo* queue_remove_elemento(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
Tipo* queue_busca(Queue* Q, int pos); // feita
int queue_busca2(Queue* Q, int pos, Tipo* ende); // feita
int queue_contem(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int queue_posicao(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int queue_tamanho(Queue* Q); // feita
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*)); // feita

void diminui(Queue* Q){
	if(Q){
		Tipo* AA = (Tipo*)calloc(Q->tam/2, sizeof(Tipo));
		for(int i = 0; i < Q->qtde; ++i){
			AA[i] = Q->array[i];
		}
		free(Q->array);
		Q->array = AA;
		Q->tam /= 2;
	}
}
void aumenta(Queue* Q){
	if(Q){
		Tipo* AA = (Tipo*)calloc(Q->tam*2, sizeof(Tipo));
		for(int i = 0; i < Q->qtde; ++i){
			AA[i] = Q->array[i];
		}
		free(Q->array);
		Q->array = AA;
		Q->tam *= 2;
	}
}
void verifica(Queue* Q){
	if(Q->qtde == Q->tam-1)
		aumenta(Q);
	else if(((float)Q->qtde/(float)Q->tam) < 0.25 && Q->tam > 5)
		diminui(Q);
}
Queue* queue_cria(){
	Queue* Q = (Queue* )calloc(1, sizeof(Queue));
	Q->array = (Tipo* )calloc(5, sizeof(Tipo));
	Q->qtde = 0;
	Q->tam = 5;

	return Q;
}
void queue_desaloca(Queue* Q){
	free(Q->array);
	free(Q);
}
void queue_insere(Queue* Q, Tipo elemento, int pos){
	if(Q){
		int a = 0, b = pos+1;
		Tipo* A = (Tipo* )calloc(Q->tam - pos, sizeof(Tipo));
		for(int i = pos; i < Q->qtde; ++i, ++a){
			A[a] = Q->array[i];
		}
		b += a;
		a = 0;
		verifica(Q);
		Q->array[pos] = elemento;
		for(int i = pos+1; i < b; ++i, ++a){
			Q->array[i] = A[a];
		}
		++Q->qtde;
	}
}
void queue_insere_fim(Queue* Q, Tipo elemento){
	if(Q){
		verifica(Q);
		Q->array[Q->qtde] = elemento;
		++Q->qtde;
	}
}
Tipo* queue_remove(Queue* Q, int pos){
	if(!Q) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	*T = Q->array[pos];
	memcpy(&Q->array[pos], &Q->array[pos + 1], ((Q->tam - (pos+1)) * sizeof(Tipo)) );
	--Q->qtde;

	return T;
}
int queue_remove2(Queue* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	*ende = Q->array[pos];
	memcpy(&Q->array[pos], &Q->array[pos + 1], ((Q->tam - (pos+1)) * sizeof(Tipo)) );
	--Q->qtde;

	return 1;
}
Tipo* queue_remove_elemento(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));

	for(int i = 0; i < Q->qtde; ++i){
		if((*compara)(&elemento, &Q->array[i])){
			T = queue_remove(Q, i);
			return T;
		}
	}
	free(T);

	return NULL;
}
Tipo* queue_busca(Queue* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 || pos >= Q->qtde) return NULL;
	Tipo* T = (Tipo*)calloc(1, sizeof(Tipo));

	if(pos >= 0 && pos < Q->qtde){
		*T = Q->array[pos];
		return T;
	}

	free(T);
	return NULL;
}
int queue_busca2(Queue* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 || pos >= Q->qtde) return 0;

	if(pos >= 0 && pos < Q->qtde){
		*ende = Q->array[pos];
		return 1;
	}

	return 0;
}
int queue_contem(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	for(int i = 0; i < Q->qtde; ++i){
		if((*compara)(&elemento, &Q->array[i]))
			return 1;
	}

	return 0;
}
int queue_posicao(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return -1;
	for(int i = 0; i < Q->qtde; ++i){
		if((*compara)(&elemento, &Q->array[i]))
			return i;
	}

	return -1;
}
int queue_tamanho(Queue* Q){
	if(!Q) return 0;
	return Q->qtde;
}
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*)){
	Tipo AA;
	int i = 0
	while(i < Q->qtde){
		AA = Q->array[i];
		(*imprimeElemento)(&AA);
		if(i < Q->qtde-1) printf(",");
		++i;
	}
	printf("\n");
}