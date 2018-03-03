#include <stdio.h>
#include <stdlib.h>


typedef int Tipo;

typedef struct no{
	Tipo data;
	struct no* next;
	struct no* prev;
}Node;

typedef struct{
	Node* begin;
	Node* end;
	int qtde;
}Queue;

Queue* Queue_Criar(); // Cria lista 
int Queue_Push(Queue* Q, Tipo item, int pos); // Insere elemento em determinada posição
Tipo* Queue_Pop0(Queue* Q); // remove elemento do início
Tipo* Queue_Pop1(Queue* Q, int pos); // remove elemento de uma posição
int Queue_Begin(Queue* Q, Tipo* end); // devolve elemento do início
void Queue_Imprimir(Queue* Q,  void (*printElemento)(Queue*)); // imprime a lista
int Queue_Tamanho(Queue* Q); // devolve a quantidade de elementos da lista

Queue* Queue_Criar(){
	Queue* Q = (Queue* )malloc(sizeof(Queue));
	Q->begin = NULL;
	Q->end = NULL;

	return Q;
}
int Queue_Push(Queue* Q, Tipo item, int pos){
	if(!Q) return 0;
	Node* novo = (Node* )malloc(sizeof(Node));
	novo->data = item;
	novo->next == NULL;
	novo->prev == NULL;
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
			return 1;
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

			Aux = NULL;

			return 1;
		}
	}
	else{
		novo->prev = Q->end;
		Q->end->next = novo;
		Q->end = novo;
		++Q->qtde;
		return 1;
	}

	return 0;
}
Tipo* Queue_Pop0(Queue* Q){
	if(!Q) return NULL;
	Tipo* O = (Tipo* )calloc(1, sizeof(Tipo));
	*O = Q->begin->data;
	Node* Aux = Q->begin;
	Q->begin = Aux->next;
	Aux->next->prev = NULL;
	free(Aux);
	--Q->qtde;

	return O;	
}
Tipo* Queue_Pop1(Queue* Q, int pos){
	if(!Q) return NULL;
	Tipo* O = (Tipo* )calloc(1, sizeof(Tipo));
	int a = 0;
	if(pos >= 0 && pos < Q->qtde){
		Node* Aux = Q->begin;
		while(a != pos){
			Aux = Aux->next;
			++a;
		}
		*O = Aux->data;
		Aux->prev->next = Aux->next;
		Aux->next->prev = Aux->prev;
		Aux->prev = NULL;
		Aux->next = NULL;
		free(Aux);

		--Q->qtde;
		return O;
	}
	return NULL;
}
int Queue_Begin(Queue* Q, Tipo* end){
	if(!Q || !end || !Q->begin) return 0;
	*end = Q->begin->data;

	return 1;
}
void Queue_Imprimir(Queue* Q,  void (*printElemento)(Queue*)){

	(*printElemento)(Q);
}
int Queue_Tamanho(Queue* Q){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	int a = 0;
	while(Aux){
		++a;
		Aux = Aux->next;
	}

	return a;
}