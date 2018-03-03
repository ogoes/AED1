#include <stdio.h>
#include <stdlib.h>



typedef int Tipo;

typedef struct{
	Tipo* array;
	int begin;
	int end;
	int tam;
}Queue;

Queue* Queue_Criar(); // Cria lista 
int Queue_Push(Queue* Q, Tipo item, int pos); // Insere elemento em determinada posição
Tipo* Queue_Pop0(Queue* Q); // remove elemento do início
Tipo* Queue_Pop1(Queue* Q, int pos); // remove elemento de uma posição
int Queue_Begin(Queue* Q, Tipo* end); // devolve elemento do início
void Queue_Imprimir(Queue* Q,  void (*printElemento)(Queue*)); // imprime a lista
int Queue_Tamanho(Queue* Q); // devolve a quantidade de elementos da lista

void aumenta(Queue* Q){
	if(!Q) return 0; // retorna zero para falha
	int j = 0, i; 
	Tipo* V = (Tipo*) calloc(Q->tam*2, sizeof(Tipo)); // criação de um vetor auxiliar
	if(Q->begin > Q->end){ // ------------------//
		i = Q->begin;							//
		while(i != Q->end){						//
			V[j] = Q->array[i];					//
			i = (i+1) % Q->tam;					//
			++j;								//
		}										//---->Copia os elementos dependendo do caso que se encontra a fila circular
	}else{										//
		i = Q->begin;							//
		while(i < Q->end){						//
			V[j] = Q->array[i];					//
			++i, ++j;							//
		}										//	
	}						//------------------//

	free(Q->array); // libera a memória alocada anteriormente
	Q->array = V;
	Q->tam *= 2; // dobra o tamanho do array
	Q->begin = 0; // inicio volta a valer zero
	Q->end = j; // o fim fica com o mesmo valor de quantidade de elementos

	return 1; // retorna um para sucesso
}
void diminui(Queue* Q){
	if(!Q) return 0; // retorna zero para falha
	int j = 0, i; 
	Tipo* V = (Tipo*) calloc(Q->tam/2, sizeof(Tipo)); // criação de um vetor auxiliar
	if(Q->begin > Q->end){ // ------------------//
		i = Q->begin;							//
		while(i != Q->end){						//
			V[j] = Q->array[i];					//
			i = (i+1) % Q->tam;					//
			++j;								//
		}										//---->Copia os elementos dependendo do caso que se encontra a fila circular
	}else{										//
		i = Q->begin;							//
		while(i < Q->end){						//
			V[j] = Q->array[i];					//
			++i, ++j;							//
		}										//	
	}						//------------------//

	free(Q->array); // libera a memória alocada anteriormente
	Q->array = V;
	Q->tam /= 2; // dobra o tamanho do array
	Q->begin = 0; // inicio volta a valer zero
	Q->end = j; // o fim fica com o mesmo valor de quantidade de elementos

	return 1; // retorna um para sucesso
}
void verifica(Queue* Q){
	int j = Queue_Tamanho(Q);
	if(Q->begin < 2 && Q->end == Q->tam-1)
		aumenta(Q);
	else if(Q->end == Q->begin-1)
		aumenta(Q);
	else if(((float)j/(float)Q->tam) < 0.25 && Q->tam > 5)
		diminui(Q);
}
Queue* Queue_Criar(){
	Queue* Q = (Queue*)calloc(1, sizeof(Queue));
	Q->array = (Tipo* )calloc(5, sizeof(Tipo));
	Q->begin = 0;
	Q->end = 0;
	Q->tam = 5;

	return Q;
}
int Queue_Push(Queue* Q, Tipo item, int pos){
}