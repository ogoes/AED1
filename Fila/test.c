#include <stdio.h>
#include <stdlib.h>
#include "FilaEncadeada.h"

// #include "FilaSequencial.h"

void Intprint(Queue* F){
	Node* Aux = F->begin;
	while(Aux){
		printf("%2i ", Aux->data);
		Aux = Aux->next;
	}
	printf("\n");
}
/*void Intprint2(Queue* F){
	int a = F->begin;
	while(a != F->end){
		printf(" %i", F->array[a]);
		a = (a + 1)%F->tam;
	}
	printf("\n");
}*/



void main(){
	Queue* F = Queue_criar();
	int j, k = 0;
	int *a = &k;
	for(int i = 1; i < 10; ++i){
		k = (k + 1)%10;
		Queue_inserir(F, k);
		Queue_imprimir(F, Intprint);
		
	}
	k = 0;
	j = Queue_tamanho(F);
	printf("Tamanho: %i\n", j);
	for(int i = 1; i < 10; ++i){
		k = (k + 1)%10;
		Queue_imprimir(F, Intprint);
		Queue_remover2(F, &k);
		
	}
	j = Queue_tamanho(F);
	printf("Tamanho: %i\n", j);
}
