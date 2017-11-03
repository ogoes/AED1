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
	
	for(int i = 0; i < 6; ++i){
		Queue_Push(Q, i+1, 0);
		Queue_Imprimir(Q, print);
	}
	A = Queue_Pop1(Q, 2);
	Queue_Imprimir(Q, print);

	printf("%i\n", *A);


}
