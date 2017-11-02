#include <stdio.h>
#include <stdlib.h>
#include "FilaEncadeada.h"
// #include "FilaSequencial.h"

void Intprint(Fila* F){
	Node* Aux = F->begin;
	while(Aux){
		printf("%2i ", Aux->data);
		Aux = Aux->next;
	}
	printf("\n");
}
/*void Intprint2(Fila* F){
	int a = F->begin;
	while(a != F->end){
		printf(" %i", F->array[a]);
		a = (a + 1)%F->tam;
	}
	printf("\n");
}*/



void main(){
	Fila* F = fila_criar();
	int j, k = 0;
	int *a = &k;
	for(int i = 1; i < 10; ++i){
		k = (k + 1)%10;
		fila_inserir(F, k);
		fila_imprimir(F, Intprint);
		
	}
	k = 0;
	j = fila_tamanho(F);
	printf("Tamanho: %i\n", j);
	for(int i = 1; i < 10; ++i){
		k = (k + 1)%10;
		fila_imprimir(F, Intprint);
		fila_remover2(F, &k);
		
	}
	j = fila_tamanho(F);
	printf("Tamanho: %i\n", j);
}