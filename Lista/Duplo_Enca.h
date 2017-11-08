#include <stdio.h>
#include <stdlib.h>

typedef char Tipo;

typedef struct no{
	Tipo data;
	struct no* prev;
	struct no* next;
}Node;

typedef struct{
	Node* begin;
	Node* end;
	int qtde;
}Queue;

Queue* queue_cria(); // feita	
void queue_desaloca(Queue* Q); // feita
void queue_insere(Queue* Q, Tipo elemento, int pos); // feita
void queue_insere_fim(Queue* Q, Tipo elemento); // feita
Tipo* queue_remove(Queue* Q, int pos); // feita
int queue_remove2(Queue* Q, int pos, Tipo* ende); // feita
int queue_remove_elemento(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
Tipo* queue_busca(Queue* Q, int pos); // feita 
int queue_busca2(Queue* Q, int pos, Tipo* ende); // feita
int queue_contem(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int queue_posicao(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int queue_tamanho(Queue* Q); // feita
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*));

Queue* queue_cria(){
	Queue* Q = (Queue* )calloc(1, sizeof(Queue));
	Q->begin = NULL;
	Q->end = NULL;
	Q->qtde = 0;

	return Q;
}
void queue_desaloca(Queue* Q){
	Node* Aux = Q->begin;
	Node* XXX;
	while(Aux){
		XXX = Aux;
		Aux = Aux->next;
		free(XXX);
	}
	free(Q->begin);
	free(Q->end);
	free(Q);
}
void queue_insere(Queue* Q, Tipo elemento, int pos){
	if(Q){
		Node* novo = (Node* )calloc(1, sizeof(Node));
		novo->data = elemento;
		novo->prev = NULL;
		novo->next = NULL;
		int a = 0;
		if(Q->qtde == 0){
			Q->begin = novo;
			Q->end = novo;
			++Q->qtde;
		}
		else if(pos < Q->qtde){
			if(pos <= 0){
				novo->next = Q->begin;
				Q->begin->prev = novo;
				Q->begin = novo;
				++Q->qtde;
			}
			else{
				Node* Aux = Q->begin;
				while(a != pos){
					Aux = Aux->next;
					++a;
				}
				novo->prev = Aux->prev;
				novo->next = Aux;
				Aux->prev = novo;
				novo->prev->next = novo;
				++Q->qtde;
			}
		}
		else{
			novo->prev = Q->end;
			Q->end->next = novo;
			Q->end = novo;
			++Q->qtde;
		}

	}
}
void queue_insere_fim(Queue* Q, Tipo elemento){
	if(Q){
		queue_insere(Q, elemento, Q->qtde);

	}
}
Tipo* queue_remove(Queue* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 || pos > Q->qtde) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	Node* Aux = Q->begin;
	int a = 0;

	if(pos == 0){
		Q->begin = Aux->next;
		Aux->next->prev = NULL;
		*T = Aux->data;
		free(Aux);
		--Q->qtde;
	}
	else{
		while(a != pos){
			Aux = Aux->next;
			++a;
		}
		*T = Aux->data;
		Aux->prev->next = Aux->next;
		Aux->next->prev = Aux->prev;
		free(Aux);
		--Q->qtde;
	}
	return T;
}
int queue_remove2(Queue* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 || pos > Q->qtde) return 0;
	Node* Aux = Q->begin;
	int a = 0;

	if(pos == 0){
		Q->begin = Aux->next;
		Aux->next->prev = NULL;
		*ende = Aux->data;
		free(Aux);
		--Q->qtde;
	}
	else{
		while(a != pos){
			Aux = Aux->next;
			++a;
		}
		*ende = Aux->data;
		Aux->prev->next = Aux->next;
		Aux->next->prev = Aux->prev;
		free(Aux);
		--Q->qtde;
	}
	return 1;
}
int queue_remove_elemento(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	int a = 0;
	while(Aux){
		if((*compara)(&elemento, &Aux->data)){
			T = queue_remove(Q, a);
			return 1;
		}
		Aux = Aux->next;
	}
	free(T);
	return 0;
}
Tipo* queue_busca(Queue* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 && pos >= Q->qtde) return NULL;
	int a = 0;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));

	Node* Aux = Q->begin;
	while(a != pos){
		Aux = Aux->next;
		++a;
	}

	*T = Aux->data;
	return T;
}
int queue_busca2(Queue* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 && pos >= Q->qtde) return 0;
	int a = 0;

	Node* Aux = Q->begin;
	while(a != pos){
		Aux = Aux->next;
		++a;
	}

	*ende = Aux->data;
	return 1;
}
int queue_contem(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	Tipo AA;
	while(Aux){
		AA = Aux->data;
		if((*compara)(&elemento, &AA))
			return 1;

		Aux = Aux->next;
	}

	return 0;
}
int queue_posicao(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return -1;
	Node* Aux = Q->begin;
	Tipo AA;
	int i = 0;
	while(Aux){
		AA = Aux->data;
		if((*compara)(&elemento, &AA))
			return i;
		++i;
		Aux = Aux->next;
	}

	return -1;
}
int queue_tamanho(Queue* Q){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	int a = 0;
	while(Aux){
		++a;
		Aux = Aux->next;
	}

	return a;
}
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*)){
	if(Q){
		Node* Aux = Q->begin;
		Tipo AA;
		while(Aux){
			AA = Aux->data;
			(*imprimeElemento)(&AA);
			if(Aux->next) printf(",");
			Aux = Aux->next;
		}
		printf("\n");
	}
}