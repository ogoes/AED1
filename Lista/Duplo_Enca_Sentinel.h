#include <stdio.h>
#include <stdlib.h>

typedef int Tipo;

typedef struct no{
	Tipo data;
	struct no* prev;
	struct no* next;
}Node;

typedef struct{
	Node* sentinel;
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
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*)); // feita


Node* novono(Tipo valor, Node* next, Node* prev){
	Node* novo = (Node* )calloc(1, sizeof(Node));
	novo->data = valor;
	novo->next = next;
	novo->prev = prev;

	return novo;
}
Node* auxpos(Queue* Q, int pos){
	if(pos < 0) pos = 0;
	if(pos > Q->qtde) pos = Q->qtde;
	Node* Aux = Q->sentinel;
	int i = 0;
	while(i < pos){
		Aux = Aux->next;
		++i;
	}

	return Aux;
}
void addfrente(Node* A, Node* B){
	B->prev = A;
	B->next = A->next;
	A->next->prev = B;
	A->next = B;
}
void remove1(Node* A, Tipo* B){
	A->prev->next = A->next;
	A->next->prev = A->prev;

	*B = A->data;
	free(A);
}
Queue* queue_cria(){
	Queue* Q = (Queue* )calloc(1, sizeof(Queue));
	Q->qtde = 0;
	Q->sentinel = (Node*)calloc(1, sizeof(Node));
	Q->sentinel->next = Q->sentinel;
	Q->sentinel->prev = Q->sentinel;

	return Q;
}
void queue_desaloca(Queue* Q){
	if(Q->sentinel->next == Q->sentinel){
		free(Q->sentinel->next);
		
	}
	else{
		free(Q->sentinel->next);
		free(Q->sentinel->prev);
		free(Q->sentinel);
		free(Q);
	}
}
void queue_insere(Queue* Q, Tipo elemento, int pos){
	Node* novo = novono(elemento, NULL, NULL);
	Node* AUX = auxpos(Q, pos);
	addfrente(AUX, novo);
	++Q->qtde;
}
void queue_insere_fim(Queue* Q, Tipo elemento){
	if(Q)	
		queue_insere(Q, elemento, Q->qtde);
}
Tipo* queue_remove(Queue* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 || pos >= Q->qtde) return NULL;
	if(Q->sentinel->next == Q->sentinel) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	Node* AUX = auxpos(Q, pos+1);
	remove1(AUX, T);
	--Q->qtde;
	
	return T;
}
int queue_remove2(Queue* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 || pos >= Q->qtde) return 0;
	if(Q->sentinel->next == Q->sentinel) return 0;
	Node* AUX = auxpos(Q, pos+1);
	remove1(AUX, ende);
	--Q->qtde;
	
	return 1;
}
int queue_remove_elemento(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	if(Q->sentinel->next == Q->sentinel) return 0;
	Node* Aux = Q->sentinel->next;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	int a = 0;
	while(Aux){
		if((*compara)(&elemento, &Aux->data)){
			T = queue_remove(Q, a);
			return 1;
		}
		Aux = Aux->next;
		++a;
	}
	free(T);
	return 0;
}
Tipo* queue_busca(Queue* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 && pos >= Q->qtde) return NULL;
	if(Q->sentinel->next == Q->sentinel) return NULL;
	int a = 0;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));

	Node* Aux = Q->sentinel->next;
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
	if(Q->sentinel->next == Q->sentinel) return 0;
	int a = 0;

	Node* Aux = Q->sentinel;
	while(a != pos){
		Aux = Aux->next;
		++a;
	}

	*ende = Aux->data;
	return 1;
}
int queue_contem(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	if(Q->sentinel->next == Q->sentinel) return 0;
	Node* Aux = Q->sentinel->next;
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
	if(Q->sentinel->next == Q->sentinel) return -1;
	Node* Aux = Q->sentinel->next;
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
	if(!Q) return -1;
	if(Q->sentinel->next == Q->sentinel) return -1;
	Node* Aux = Q->sentinel->next;
	int a = 0;
	while(Aux){
		++a;
		Aux = Aux->next;
	}

	return a;
}
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*)){
	if(Q && Q->sentinel->next != Q->sentinel){
		Node* Aux = Q->sentinel->next;
		Tipo AA;
		while(Aux != Q->sentinel){
			AA = Aux->data;
			(*imprimeElemento)(&AA);
			if(Aux->next != Q->sentinel) printf(",");
			Aux = Aux->next;
		}
		printf("\n");
	}
}