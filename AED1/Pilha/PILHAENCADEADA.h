#include <stdio.h>
#include <stdlib.h>

typedef int Tipo;

typedef struct no{
	Tipo data;
	struct no* next;
}Node;

typedef struct{
	Node* top;
	int qtde;
}Pilha;

Pilha* Pilha_Criar(); // feita
int Pilha_Push(Pilha* P, Tipo item); // feita
Tipo* Pilha_Pop1(Pilha* P); // feita
int Pilha_Pop2(Pilha* P, Tipo* end); // feita
int Pilha_Top(Pilha* P, Tipo* end); // feita
void Pilha_Imprimir(Pilha* P,  void (*printElemento)(Pilha*)); // feita
int Pilha_Tamanho(Pilha* P); // feita

Pilha* Pilha_Criar(){
	Pilha* P = (Pilha* )calloc(1, sizeof(Pilha));
	P->top = NULL;
	P->qtde = 0;

	return P;
}
int Pilha_Push(Pilha* P, Tipo item){
	if(!P) return 0;
	Node* novo = (Node* )malloc(sizeof(Node));
	novo->next = NULL;
	novo->data = item;

	if(P->qtde == 0){
		P->top = novo;
		++P->qtde;
	}
	else{
		Node* aux = P->top;
		P->top = novo;
		novo->next = aux;
		++P->qtde;
	}

	return 1;
}
Tipo* Pilha_Pop1(Pilha* P){
	if(!P || !P->top) return NULL;
	Tipo* aux = (Tipo* )malloc(sizeof(Tipo));
	*aux = (P->top)->data;
	Node* Aux = P->top; 
	P->top = (P->top)->next;
	free(Aux);
	--P->qtde;

	return aux;
}
int Pilha_Pop2(Pilha* P, Tipo* end){
	if(!P) return 0;
	*end = (P->top)->data;
	Node* Aux = P->top; 
	P->top = (P->top)->next;
	free(Aux);
	--P->qtde;

	return 1;
}
int Pilha_Top(Pilha* P, Tipo* end){
	if(!P) return 0;
	*end = (P->top)->data;
	return 1;
}
void Pilha_Imprimir(Pilha* P, void (*printElemento)(Pilha*)){
	(*printElemento)(P);
}
int Pilha_Tamanho(Pilha* P){
	if(!P) return -1;
	return P->qtde;
}