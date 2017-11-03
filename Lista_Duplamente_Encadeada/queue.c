#include "ListaEncadeada.h"
void print(Queue* Q){
	Node* Aux = Q->begin;
	while(Aux){
		printf(" %i", Aux->data);
		Aux = Aux->next;
	}
	printf("\n");
}
void main(){
	Queue* Q = Queue_Criar();
	int a;
	int *A = &a;
	Queue_Push(Q, 1, 0);
	Queue_Imprimir(Q, print);
	Queue_Push(Q, 2, 0);
	Queue_Imprimir(Q, print);
	Queue_Push(Q, 3, 0);
	Queue_Imprimir(Q, print);
	Queue_Push(Q, 4, 0);
	Queue_Imprimir(Q, print);
	Queue_Push(Q, 5, 0);
	Queue_Imprimir(Q, print);
	Queue_Push(Q, 6, 0);
	Queue_Imprimir(Q, print);
	A = Queue_Pop1(Q, 2);
	Queue_Imprimir(Q, print);

	printf("%i\n", *A);


}