#include <stdio.h>
#include <stdlib.h>


typedef int Tipo;

typedef struct no{
	Tipo data;
	struct no* next;
}Node;

typedef struct{
	Node* begin;
	Node* end;
}Queue;

Queue* Queue_criar(); // feita
int Queue_inserir(Queue* F, Tipo item); // feita
Tipo* Queue_remover1(Queue* F); // feita
int Queue_remover2(Queue* F, Tipo* end); // feita
void Queue_imprimir(Queue* F,  void (*printElemento)(Queue*)); // feita
int Queue_tamanho(Queue* F); // feita
void Queue_desalocar(Queue* F); // feita
Tipo* Queue_primeiro(Queue* F); // feita
int Queue_contem(Queue* F, Tipo elemento); // feita





int Queue_contem(Queue* F, Tipo elemento){
	Node* Aux =F->begin;
	while(Aux){
		if(elemento == Aux->data)
			return 1;
		Aux = Aux->next;
	}

	return 0;
}
void Queue_desalocar(Queue* F){
	Node* Aux = F->begin;
	Node* XXX;
	while(Aux){
		XXX = Aux;
		Aux = Aux->next;
		free(XXX);
	}
	free(F);
	if(!F)
		printf("Desalocado com sucesso\n");
}
Queue* Queue_criar(){
	Queue* F = (Queue* )malloc(sizeof(Queue));
	F->begin = NULL;
	F->end = NULL;

	return F;
}
int Queue_inserir(Queue* F, Tipo item){
	if(!F) return 0;
	Node* Novo = (Node* )malloc(sizeof(Node));
	Novo->data = item;
	Novo->next = NULL;
	if(!F->begin && !F->end){
		F->begin = Novo;
		F->end = Novo;
	}
	else{
		F->end->next = Novo;
		F->end = Novo;
	}


	return 1;
}
Tipo*Queue_remover1(Queue* F){
	if(!F || !F->begin) return NULL;
	Tipo* data = (Tipo* )malloc(sizeof(Tipo));
	*data = F->begin->data;
	Node* aux = F->begin;
	F->begin = F->begin->next;
	free(aux);

	return data;
}
int Queue_remover2(Queue* F, Tipo* end){
	if(!F || !F->begin) return 0;
	*end = F->begin->data;
	Node* aux = F->begin;
	F->begin = F->begin->next;
	free(aux);

	return 1;
}
Tipo* Queue_primeiro(Queue* F){
	if(!F || !F->begin) return NULL;
	Tipo* end = (Tipo* )calloc(1, sizeof(Tipo));
	*end = F->begin->data;
	
	return end;
}
void Queue_imprimir(Queue* F,  void (*printElemento)(Queue*)){

	(*printElemento)(F);
}
int Queue_tamanho(Queue* F){
	if(!F) return -1;
	Node* aux = F->begin;
	int a = 0;
	while(aux){
		++a;
		aux = aux->next;
	}

	return a;
}