#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *v;
	int tamanho;
	int qtde;
}Vetor;

Vetor* vetor_criar();
void vetor_aumenta(Vetor *vetor, int tamanho);
void vetor_inicializar(Vetor *vetor, int value, int quant);
void vetor_inserirFim(Vetor* vetor, int valor);
void vetor_imprimir(Vetor* vetor);
void vetor_ordenar_Cres(Vetor *vetor);
void vetor_ordenar_Decres(Vetor *vetor);
void vetor_atualizar(Vetor *vetor, int pos, int valor);
void vetor_inserir_Espec(Vetor *vetor, int pos, int valor);
void vetor_remover(Vetor *vetor, int pos, int elemento);
void vetor_procurar(Vetor *vetor, int valor);

void vetor_aumenta(Vetor *vetor, int tamanho){
	free(vetor);
	vetor = (Vetor *) calloc(1, sizeof(Vetor));
	vetor->tamanho = tamanho+1;
	vetor->v = (int *) calloc(vetor->tamanho, 4);
}
Vetor* vetor_criar(){
	Vetor *V = (Vetor *) alloc(sizeof(Vetor));
	V->tamanho = 0;
	V->qtde	 = 0;

	V->v = (int *) malloc(4);
	return V;
}
void vetor_inicializar(Vetor *vetor, int value, int quant){
	int i = 0;
	vetor->tamanho = quant;
	vetor->qtde = vetor->tamanho;

	for(i = 0; i < vetor->tamanho; ++i){
		*(vetor->v) = value;
		++(vetor->v);
	}

	(vetor->v) -= i;
}
void vetor_inserirFim(Vetor* vetor, int valor){
	if(vetor->tamanho == 0){
		++vetor->tamanho;
		++vetor->qtde;
		*(vetor->v) = valor;
	}
	else{
		int Tam = vetor->tamanho, i;
		int V[Tam+1];

		for(i = 0; i < Tam; ++i){
			V[i] = *(vetor->v);
			++(vetor->v);	
		}
		(vetor->v) -= i;

		V[Tam] = valor;

		vetor_aumenta(vetor, Tam);
		for(i = 0; i < vetor->tamanho; ++i){
			*(vetor->v) = V[i];
			++(vetor->v);
		}

		(vetor->v) -= i;
		vetor->qtde = i;
	}
}
void vetor_imprimir(Vetor* vetor){
	int i;
	for(i = 0; i < vetor->tamanho; ++i)	{
		printf("%i ", *(vetor->v));
		++(vetor->v);
	}
	(vetor->v) -= i;
	printf("\n");
}
void vetor_ordenar_Cres(Vetor *vetor){
	int a;
	for(int i = 0; i < vetor->tamanho; ++i){
		for(int j = 0; j < vetor->tamanho; ++j){
			if(vetor->v[i] < vetor->v[j]){
				a = vetor->v[i];
				vetor->v[i] = vetor->v[j];
				vetor->v[j] = a;
			}
		}
	}
}
void vetor_ordenar_Decres(Vetor *vetor){
	int a;
	for(int i = 0; i < vetor->tamanho; ++i){
		for(int j = 0; j < vetor->tamanho; ++j){
			if(vetor->v[i] > vetor->v[j]){
				a = vetor->v[i];
				vetor->v[i] = vetor->v[j];
				vetor->v[j] = a;
			}
		}
	}
}
void vetor_atualizar(Vetor *vetor, int pos, int valor){
	if(vetor->tamanho != 0 || pos < vetor->tamanho)
		vetor->v[pos-1] = valor;
}
void vetor_inserir_Espec(Vetor *vetor, int pos, int valor){
	if(vetor->tamanho != 0 || pos <= vetor->tamanho){
		int Tam = vetor->tamanho, i, j;
		int V[Tam+1];

		for(i = 0; i < Tam; ++i){
			V[i] = *(vetor->v);
			++(vetor->v);	
		}
		(vetor->v) -= i;

		vetor_aumenta(vetor, Tam);
		for(i = 0, j = 0; i < vetor->tamanho; ++i, ++j){
			if(i != pos-1)
				*(vetor->v) = V[j];
			else{
				*(vetor->v) = valor;
				--j;
			}
			++vetor->v;
		}
		vetor->v -= i;
		vetor->qtde = i;

	}
	else{
		vetor_inserirFim(vetor, valor);
	}
}
void vetor_remover(Vetor *vetor, int pos, int elemento){
	if(pos <= vetor->tamanho || vetor->tamanho != 0){
		int Tam = vetor->tamanho, i, j, a = 0;
		int V[Tam-1], VV[Tam];

		for(i = 0; i < Tam; ++i){
			VV[i] = vetor->v[i];
		}

		for(i = 0, j = 0; i < Tam; ++i){
			if(i == (pos-1) && vetor->v[i] == elemento)
				++a;
			else{
				V[j] = vetor->v[i];
				++j;
			}
		}
		if(a == 1){
			vetor_aumenta(vetor, Tam-2);
			for(i = 0; i < vetor->tamanho; ++i){
				*(vetor->v) = V[i];
				++(vetor->v);
			}

			(vetor->v) -= i;
			vetor->qtde = i;
		}

	}
}
void vetor_procurar(Vetor *vetor, int valor){
	int a = 0, j = 0;
	for(int i = 0; i < vetor->tamanho; ++i){
		if(vetor->v[i] == valor)
			++a;
	}
	if(a != 0){
		printf("O valor %i foi encontrado na posição: ", valor);
		for(int i = 0; i < vetor->tamanho; ++i){
		if(vetor->v[i] == valor)
			if(j == a-1)
				printf("e %i.", i+1);
			else if(j == a-2){
				printf("%i ", i+1);
				++j;
			}
			else{
				printf("%i, ", i+1);
				++j;
			}
		}
	}
	printf("\n");
}