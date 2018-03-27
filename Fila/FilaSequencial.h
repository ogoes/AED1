#include <stdio.h>
#include <stdlib.h>


typedef int Tipo; // Tipo do dado armazenado

typedef struct{
	Tipo* array; // array para o tipo de dado armazenado
	int end; // indice do final da Queue
	int begin; // indice do início da Queue
	int tam; // tamanho da Queue
}Queue;

Queue* Queue_criar();
int Queue_inserir(Queue* F, Tipo item);
Tipo* Queue_remover1(Queue* F);
int Queue_remover2(Queue* F, Tipo* end);
Tipo* Queue_primeiro(Queue* F);
void Queue_imprimir(Queue* F,  void (*printElemento)(Queue*));
int Queue_tamanho(Queue* F);
void Queue_desalocar(Queue* F);
int Queue_contem(Queue* F, Tipo elemento);


void Queue_desalocar(Queue* F){
	free(F->array);
	free(F);
}
int Queue_Aumentar(Queue* F){ // função para aumentar o tamanho do/a array/Queue
	if(!F) return 0; // retorna zero para falha
	int j = 0, i; 
	Tipo V[F->tam]; // criação de um vetor auxiliar
	if(F->begin > F->end){ // ------------------//
		i = F->begin;							//
		while(i != F->end){						//
			V[j] = F->array[i];					//
			i = (i+1) % F->tam;					//
			++j;								//
		}										//---->Copia os elementos dependendo do caso que se encontra a Queue circular
	}else{										//
		i = F->begin;							//
		while(i < F->end){						//
			V[j] = F->array[i];					//
			++i, ++j;							//
		}										//	
	}						//------------------//

	free(F->array); // libera a memória alocada anteriormente
	F->tam *= 2; // dobra o tamanho do array
	F->array = (Tipo* )calloc(F->tam, sizeof(Tipo)); // aloca o dobro da quantidade anterior
	F->begin = 0; // inicio volta a valer zero
	F->end = j; // o fim fica com o mesmo valor de quantidade de elementos
	for(i = 0; i < j; ++i){ //-----//
		F->array[i] = V[i];		   //-----> Transfere od dados para o array principal
	}//                     //-----//
	return 1; // retorna um para sucesso
}
int Queue_Diminuir(Queue* F){ // função para aumentar o tamanho do/a array/Queue
	if(!F) return 0; // retorna zero para falha
	int j = 0, i; 
	Tipo V[F->tam]; // criação de um vetor auxiliar
	if(F->begin > F->end){ // ------------------//
		i = F->begin;							//
		while(i != F->end){						//
			V[j] = F->array[i];					//
			i = (i+1) % F->tam;					//
			++j;								//
		}										//---->Copia os elementos dependendo do caso que se encontra a Queue circular
	}else{										//
		i = F->begin;							//
		while(i < F->end){						//
			V[j] = F->array[i];					//
			++i, ++j;							//
		}										//	
	}						//------------------//

	free(F->array); // libera a memória alocada anteriormente
	F->tam /= 2; // diminue o tamanho do array pela metade
	F->array = (Tipo* )calloc(F->tam, sizeof(Tipo)); // aloca o dobro da quantidade anterior
	F->begin = 0; // inicio volta a valer zero
	F->end = j; // o fim fica com o mesmo valor de quantidade de elementos
	for(i = 0; i < j; ++i){ //-----//
		F->array[i] = V[i];		   //-----> Transfere od dados para o array principal
	}//                     //-----//
	return 1; // retorna um para sucesso
}
void Queue_Verifica(Queue* F){ // verifica se precisa aumentar ou diminuir a Queue
	int j = Queue_tamanho(F);
	int i = F->begin;
	if(F->begin < 2 && F->end == F->tam-1) // verifica para aumentar
		Queue_Aumentar(F);
	else if(F->end == F->begin-1) // verifica para aumentar
		Queue_Aumentar(F);
	else if(((float)j/(float)F->tam) < 0.25 && F->tam > 5) // verifica se a Queue está com mais de 25% da capacidade total
		Queue_Diminuir(F);
}
Queue* Queue_criar(){ // funçao que cria uma Queue
	Queue* F = (Queue* )malloc(sizeof(Queue)); // alocação
	F->end = 0; // indice zero
	F->begin = 0; // indice zero
	F->tam = 5; // tamanho inicial da Queue
	F->array = (Tipo* )calloc(F->tam, sizeof(Tipo)); // alocação do array

	return F; // retorna a Queue criada
}
int Queue_inserir(Queue* F, Tipo item){ // função de inserção
	if(!F) return 0;
	Queue_Verifica(F); // verifica a nescessidade de aumento/diminuição
	F->array[F->end] = item; // insere no fim
	F->end = (F->end+1) % F->tam; // acrecenta no indice fim usando mod

	return 1;
}
Tipo* Queue_remover1(Queue* F){ // função para a remoção, retorna um endereço com o valor coletado
	if(!F) return NULL;
	Tipo* V = (Tipo* )calloc(1, sizeof(Tipo)); // aloca uma variável aux para receber o dado
	*V = F->array[F->begin]; // atribuição
	F->begin = (F->begin + 1) % F->tam; // acrecenta o indice de inicio com o mod

	return V; // retorna o endereço onde foi armazenado o dado
}
int Queue_remover2(Queue* F, Tipo* end){ // função para a remoção, recebe o endereço por parâmetro
	if(!F) return 0;
	*end = F->array[F->begin]; // atribuição do dado
	F->begin = (F->begin + 1) % F->tam; // acrecenta o indice de inicio com o mod

	return 1; // retorna um para sucesso
}
Tipo* Queue_primeiro(Queue* F){ // função para checagem do topo/inicio
	if(!F) return NULL;
	Tipo* end = (Tipo* )calloc(1, sizeof(Tipo));
	*end = F->array[F->begin]; // copia o dado para um endereço recebido
	return end;
}
void Queue_imprimir(Queue* F,  void (*printElemento)(Queue*)){ // função de impressão, recebe uma funçao como parametro

	(*printElemento)(F); // chama a função que sabe imprimir o tipo de dado
}
int Queue_tamanho(Queue* F){ // função que retorna a quantidade de elementos da Queue
	if(!F) return 0;
	if(F->begin == F->end) return 0;
	int j = 0;
	int	i = F->begin;

	if(F->begin > F->end){
		while(i != F->end){
			i = (i+1) % F->tam;
			++j;
		}
	}else{
		i = F->begin;
		while(i < F->end){		
			++i, ++j;
		}
	}
	return j;
}