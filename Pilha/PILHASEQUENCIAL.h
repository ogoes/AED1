#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Tipo;

typedef struct{
	Tipo* vetor;
	int top;
	int tam;
}Pilha;

Pilha* Pilha_Criar(); // feita
int Pilha_Push(Pilha* P, Tipo item); // feita
Tipo* Pilha_Pop1(Pilha* P); // feita
int Pilha_Pop2(Pilha* P, Tipo* end); // feita
int Pilha_Top(Pilha* P, Tipo* end); // feita
int Pilha_Aumentar(Pilha* P); // feita
int Pilha_Diminuir(Pilha* P); // feita
void Pilha_Imprimir(Pilha* P, void (*printElemento)(Tipo*)); // feita
int Pilha_tamanho(Pilha* P); // feita

int Pilha_tamanho(Pilha* P){
	if(!P) return 0;
	return P->top;
}
void Pilha_Imprimir(Pilha* P, void (*printElemento)(Tipo*)){
	for(int i = P->top-1; i >= 0; --i){
		(*printElemento)(&P->vetor[i]);
		if(i > 0) printf(",");
	}
	printf("\n");
}
void Pilha_Verifica(Pilha* P){
	if(!P)
		P = Pilha_Criar();
	else if(((float)P->top/(float)P->tam)*100 <= 25 && P->tam > 5)
		Pilha_Diminuir(P);
	else if(P->top == P->tam)
		Pilha_Aumentar(P);
}
int Pilha_Aumentar(Pilha* P){
	if(!P) return 0;
	Tipo* V = (Tipo* ) calloc(P->tam, sizeof(Tipo));
	memcpy(V, P->vetor, sizeof(Tipo)*P->top);
	free(P->vetor);
	P->vetor = (Tipo* ) calloc(P->tam*2, sizeof(Tipo));
	for(int i = 0; i < P->tam; ++i){
		P->vetor[i] = V[i];
	}
	P->tam *= 2;
	return 1;
}
int Pilha_Diminuir(Pilha* P){
	if(!P) return 0;
	Tipo* V = (Tipo* ) calloc(P->top+1, sizeof(Tipo));
	memcpy(V, P->vetor, sizeof(Tipo)*P->top);
	free(P->vetor);
	P->vetor = (Tipo* ) calloc(P->tam/2, sizeof(Tipo));
	memcpy(P->vetor, V,sizeof(Tipo));
	P->tam /= 2;
	return 1;
}
Pilha* Pilha_Criar(){
	Pilha* P = (Pilha* ) calloc(1, sizeof(Pilha));
	P->top = 0;
	P->tam = 5;
	P->vetor = (Tipo* )calloc(P->tam, sizeof(Tipo));

	return P;
}
int Pilha_Push(Pilha* P, Tipo item){
	if(!P) return 0;
	Pilha_Verifica(P);
	P->vetor[P->top] = item;
	++P->top;
	return 1;
}
Tipo* Pilha_Pop1(Pilha* P){
	if(P->top == 0) return NULL;
	Tipo* V = (Tipo* ) calloc(1, sizeof(Tipo));
	--P->top;
	*V = P->vetor[P->top];
	return V;
}
int Pilha_Pop2(Pilha* P, Tipo* end){
	if(P->top == 0 || !end) return 0;
	--P->top;
	*end = P->vetor[P->top];
	return 1;
}
int Pilha_Top(Pilha* P, Tipo* end){
	if(P->top == 0 || !end) return 0;
	*end = P->vetor[P->top-1];
	return 1;
}