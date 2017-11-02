#include <stdio.h>
#include <stdlib.h>

typedef int Tipo; // Tipo do dado armazenado

typedef struct{
	Tipo* array; // array para o tipo de dado armazenado
	int end; // indice do final da fila
	int begin; // indice do início da fila
	int tam; // tamanho da fila
}Fila;

Fila* fila_criar();
int fila_inserir(Fila* F, Tipo item);
Tipo* fila_remover1(Fila* F);
int fila_remover2(Fila* F, Tipo* end);
Tipo* fila_primeiro(Fila* F);
void fila_imprimir(Fila* F,  void (*printElemento)(Fila*));
int fila_tamanho(Fila* F);
void fila_desalocar(Fila* F);
int fila_contem(Fila* F, Tipo elemento);


void fila_desalocar(Fila* F){
	free(F->array);
	free(F);
}
int Fila_Aumentar(Fila* F){ // função para aumentar o tamanho do/a array/fila
	if(!F) return 0; // retorna zero para falha
	int j = 0, i; 
	Tipo V[F->tam]; // criação de um vetor auxiliar
	if(F->begin > F->end){ // ------------------//
		i = F->begin;							//
		while(i != F->end){						//
			V[j] = F->array[i];					//
			i = (i+1) % F->tam;					//
			++j;								//
		}										//---->Copia os elementos dependendo do caso que se encontra a fila circular
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
int Fila_Diminuir(Fila* F){ // função para aumentar o tamanho do/a array/fila
	if(!F) return 0; // retorna zero para falha
	int j = 0, i; 
	Tipo V[F->tam]; // criação de um vetor auxiliar
	if(F->begin > F->end){ // ------------------//
		i = F->begin;							//
		while(i != F->end){						//
			V[j] = F->array[i];					//
			i = (i+1) % F->tam;					//
			++j;								//
		}										//---->Copia os elementos dependendo do caso que se encontra a fila circular
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
void Fila_Verifica(Fila* F){ // verifica se precisa aumentar ou diminuir a fila
	int j = 0;
	int i = F->begin;
	if(F->begin > F->end){//   -------------//
		while(i != F->end){					//
			i = (i+1) % F->tam;				//
			++j;							//
		}									//
	}else{									//-------> Verifica a quantidade de elementos
		while(i < F->end){					//
			++i;							//
			++j;							//
		}									//
	}//				------------------------//
	if(F->begin < 2 && F->end == F->tam-1) // verifica para aumentar
		Fila_Aumentar(F);
	else if(F->end == F->begin-1) // verifica para aumentar
		Fila_Aumentar(F);
	else if(((float)j/(float)F->tam) < 0.25 && F->tam > 5) // verifica se a fila está com mais de 25% da capacidade total
		Fila_Diminuir(F);
}
Fila* fila_criar(){ // funçao que cria uma fila
	Fila* F = (Fila* )malloc(sizeof(Fila)); // alocação
	F->end = 0; // indice zero
	F->begin = 0; // indice zero
	F->tam = 5; // tamanho inicial da fila
	F->array = (Tipo* )calloc(F->tam, sizeof(Tipo)); // alocação do array

	return F; // retorna a fila criada
}
int fila_inserir(Fila* F, Tipo item){ // função de inserção
	if(!F) return 0;
	Fila_Verifica(F); // verifica a nescessidade de aumento/diminuição
	F->array[F->end] = item; // insere no fim
	F->end = (F->end+1) % F->tam; // acrecenta no indice fim usando mod

	return 1;
}
Tipo* fila_remover1(Fila* F){ // função para a remoção, retorna um endereço com o valor coletado
	if(!F) return NULL;
	Tipo* V = (Tipo* )calloc(1, sizeof(Tipo)); // aloca uma variável aux para receber o dado
	*V = F->array[F->begin]; // atribuição
	F->begin = (F->begin + 1) % F->tam; // acrecenta o indice de inicio com o mod

	return V; // retorna o endereço onde foi armazenado o dado
}
int fila_remover2(Fila* F, Tipo* end){ // função para a remoção, recebe o endereço por parâmetro
	if(!F) return 0;
	*end = F->array[F->begin]; // atribuição do dado
	F->begin = (F->begin + 1) % F->tam; // acrecenta o indice de inicio com o mod

	return 1; // retorna um para sucesso
}
Tipo* fila_primeiro(Fila* F){ // função para checagem do topo/inicio
	if(!F) return NULL;
	Tipo* end = (Tipo* )calloc(1, sizeof(Tipo));
	*end = F->array[F->begin]; // copia o dado para um endereço recebido
	return end;
}
void fila_imprimir(Fila* F,  void (*printElemento)(Fila*)){ // função de impressão, recebe uma funçao como parametro

	(*printElemento)(F); // chama a função que sabe imprimir o tipo de dado
}
int fila_tamanho(Fila* F){ // função que retorna a quantidade de elementos da fila
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