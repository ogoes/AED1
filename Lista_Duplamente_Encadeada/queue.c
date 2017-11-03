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
/*Queue* Queue_Criar(); // Cria lista 
int Queue_Push(Queue* Q, Tipo item, int pos); // Insere elemento em determinada posição
Tipo* Queue_Pop0(Queue* Q); // remove elemento do início
Tipo* Queue_Pop1(Queue* Q, int pos); // remove elemento de uma posição
int Queue_Begin(Queue* Q, Tipo* end); // devolve elemento do início
void Queue_Imprimir(Queue* Q,  void (*printElemento)(Queue*)); // imprime a lista
int Queue_Tamanho(Queue* Q); // devolve a quantidade de elementos da lista*/