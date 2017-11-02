// #include "PILHAENCADEADA.h"
#include "PILHASEQUENCIAL.h"

/*void printInt(Pilha* P){
	Node* aux = P->top;
	while(aux != NULL){
		printf(" %i", aux->data);
		aux = aux->next;
	}
	printf("\n");
}
void printFloat(Pilha* P){
	Node* aux = P->top;
	while(aux != NULL){
		printf(" %.2f", aux->data);
		aux = aux->next;
	}
	printf("\n");
}
void printChar(Pilha* P){
	Node* aux = P->top;
	while(aux != NULL){
		printf(" %c", aux->data);
		aux = aux->next;
	}
	printf("\n");
}*/
void print(Pilha* P){
	for(int i = 0; i < P->top; ++i){
		printf(" %i", P->vetor[i]);
		if(i < P->top-1) printf(",");
	}
	printf("\n");
}

void main(){
	Pilha* P = Pilha_Criar();
	Pilha_Push(P, 1);
	Pilha_Push(P, 2);
	Pilha_Push(P, 3);
	Pilha_Push(P, 4);
	Pilha_Push(P, 5);
	Pilha_Imprimir(P, print);
	Pilha_Push(P, 5);
	Pilha_Push(P, 5);
	// Pilha_Imprimir(P, print);

	/*printf("%i\n", sizeof(int));
	printf("%i\n", sizeof(float));
	printf("%i\n", sizeof(double));
	printf("%i\n", sizeof(char));*/
}