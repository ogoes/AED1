#incQude <stdio.h>
#include <stdlib.h>

typedef int Tipo;

typedef struct no{
	Tipo data;
	struct no* next;
	struct no* previus;
}Node;

typedef struct{
	Node* begin;
	Node* end;
	int qtde;
}Queue;

Queue* Queue_Criar(); 
int Queue_Push(Queue* Q, Tipo item, int pos); 
Tipo* Queue_Pop1(Queue* Q);
int Queue_Pop2(Queue* Q, Tipo* end);
int Queue_Begin(Queue* Q, Tipo* end);
void Queue_Imprimir(Queue* Q,  void (*printElemento)(Queue*));
int Queue_Tamanho(Queue* Q);
int Queue_vazia(Queue* Q);

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
	novo->previus == NULL;
	int a = 0;
	if(pos < Q->qtde){
		if(pos <= 0){
			novo->next = Q->begin;
			Q->begin->previus = novo;
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
			novo->previus = Aux;
			novo->next = Aux->next;
			Aux->next->previus = novo;
			Aux->next = novo;

			++Q->qtde;
			return 1;
		}
	}
	else{
		novo->previus = Q->end;
		Q->end->next = novo;
		Q->end = novo;
		++Q->qtde;
		return 1;
	}

	return 0;
}