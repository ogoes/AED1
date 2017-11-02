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
}Fila;

Fila* fila_criar(); // feita
int fila_inserir(Fila* F, Tipo item); // feita
Tipo* fila_remover1(Fila* F); // feita
int fila_remover2(Fila* F, Tipo* end); // feita
void fila_imprimir(Fila* F,  void (*printElemento)(Fila*)); // feita
int fila_tamanho(Fila* F); // feita
void fila_desalocar(Fila* F); // feita
Tipo* fila_primeiro(Fila* F); // feita
int fila_contem(Fila* F, Tipo elemento); // feita





int fila_contem(Fila* F, Tipo elemento){
	Node* Aux =F->begin;
	while(Aux){
		if(elemento == Aux->data)
			return 1;
		Aux = Aux->next;
	}

	return 0;
}
void fila_desalocar(Fila* F){
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
Fila* fila_criar(){
	Fila* F = (Fila* )malloc(sizeof(Fila));
	F->begin = NULL;
	F->end = NULL;

	return F;
}
int fila_inserir(Fila* F, Tipo item){
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
Tipo*fila_remover1(Fila* F){
	if(!F || !F->begin) return NULL;
	Tipo* data = (Tipo* )malloc(sizeof(Tipo));
	*data = F->begin->data;
	Node* aux = F->begin;
	F->begin = F->begin->next;
	free(aux);

	return data;
}
int fila_remover2(Fila* F, Tipo* end){
	if(!F || !F->begin) return 0;
	*end = F->begin->data;
	Node* aux = F->begin;
	F->begin = F->begin->next;
	free(aux);

	return 1;
}
Tipo* fila_primeiro(Fila* F){
	if(!F || !F->begin) return NULL;
	Tipo* end = (Tipo* )calloc(1, sizeof(Tipo));
	*end = F->begin->data;
	
	return end;
}
void fila_imprimir(Fila* F,  void (*printElemento)(Fila*)){

	(*printElemento)(F);
}
int fila_tamanho(Fila* F){
	if(!F) return -1;
	Node* aux = F->begin;
	int a = 0;
	while(aux){
		++a;
		aux = aux->next;
	}

	return a;
}