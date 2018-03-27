#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int Tipo;

typedef struct{
	Tipo* array;
	int qtde;
	int tam;
}Stack;

Stack* Stack_cria(); // feita
void Stack_desaloca(Stack* Q); // feita
void Stack_insere(Stack* Q, Tipo elemento, int pos); // feita
void Stack_insere_fim(Stack* Q, Tipo elemento); // feita
Tipo* Stack_remove(Stack* Q, int pos); // feita
int Stack_remove2(Stack* Q, int pos, Tipo* ende); // feita
int Stack_remove_elemento(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
Tipo* Stack_busca(Stack* Q, int pos); // feita
int Stack_busca2(Stack* Q, int pos, Tipo* ende); // feita
int Stack_contem(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int Stack_posicao(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int Stack_tamanho(Stack* Q); // feita
void Stack_imprime(Stack* Q, void (*imprimeElemento)(Tipo*)); // feita

void diminui(Stack* Q){
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
void aumenta(Stack* Q){
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
void verifica(Stack* Q){
	if(Q->qtde == Q->tam-1)
		aumenta(Q);
	else if(((float)Q->qtde/(float)Q->tam) < 0.25 && Q->tam > 5)
		diminui(Q);
}
Stack* Stack_cria(){
	Stack* Q = (Stack* )calloc(1, sizeof(Stack));
	Q->array = (Tipo* )calloc(5, sizeof(Tipo));
	Q->qtde = 0;
	Q->tam = 5;

	return Q;
}
void Stack_desaloca(Stack* Q){
	free(Q->array);
	free(Q);
}
void Stack_insere(Stack* Q, Tipo elemento, int pos){
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
void Stack_insere_fim(Stack* Q, Tipo elemento){
	if(Q){
		verifica(Q);
		Q->array[Q->qtde] = elemento;
		++Q->qtde;
	}
}
Tipo* Stack_remove(Stack* Q, int pos){
	if(!Q) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	*T = Q->array[pos];
	memcpy(&Q->array[pos], &Q->array[pos + 1], ((Q->tam - (pos+1)) * sizeof(Tipo)) );
	--Q->qtde;

	return T;
}
int Stack_remove2(Stack* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	*ende = Q->array[pos];
	memcpy(&Q->array[pos], &Q->array[pos + 1], ((Q->tam - (pos+1)) * sizeof(Tipo)) );
	--Q->qtde;

	return 1;
}
int Stack_remove_elemento(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));

	for(int i = 0; i < Q->qtde; ++i){
		if((*compara)(&elemento, &Q->array[i])){
			T = Stack_remove(Q, i);
			return 1;
		}
	}
	free(T);

	return 0;
}
Tipo* Stack_busca(Stack* Q, int pos){
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
int Stack_busca2(Stack* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 || pos >= Q->qtde) return 0;

	if(pos >= 0 && pos < Q->qtde){
		*ende = Q->array[pos];
		return 1;
	}

	return 0;
}
int Stack_contem(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	for(int i = 0; i < Q->qtde; ++i){
		if((*compara)(&elemento, &Q->array[i]))
			return 1;
	}

	return 0;
}
int Stack_posicao(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return -1;
	for(int i = 0; i < Q->qtde; ++i){
		if((*compara)(&elemento, &Q->array[i]))
			return i;
	}

	return -1;
}
int Stack_tamanho(Stack* Q){
	if(!Q) return 0;
	return Q->qtde;
}
void Stack_imprime(Stack* Q, void (*imprimeElemento)(Tipo*)){
	Tipo AA;
	int i = 0;
	while(i < Q->qtde){
		AA = Q->array[i];
		(*imprimeElemento)(&AA);
		if(i < Q->qtde-1) printf(",");
		++i;
	}
	printf("\n");
}