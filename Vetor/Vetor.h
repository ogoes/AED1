#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int *v;
	int tamanho;
	int qtde;
}Vetor;

Vetor* Cria_vetor();
void Aumenta_vetor(Vetor *vetor, int tamanho);
void Inicializa_vetor(Vetor *vetor, int value, int quant);
void Insere_fim_vetor(Vetor* vetor, int valor);
void Imprime_vetor(Vetor* vetor);
void Ordena_cres_vetor(Vetor *vetor);
void Ordena_decre_vetor(Vetor *vetor);
void Atualiza_vetor(Vetor *vetor, int pos, int valor);
void Insere_espec_vetor(Vetor *vetor, int pos, int valor);
void Remove_vetor(Vetor *vetor, int pos, int elemento);
int Procura_vetor(Vetor *vetor, int valor);

void Aumenta_vetor(Vetor *vetor, int tamanho){
	free(vetor->v);
	vetor->tamanho = tamanho+1;
	vetor->v = (int *) calloc(vetor->tamanho, 4);
}
Vetor* Cria_vetor(){
	Vetor *V = (Vetor *)malloc(sizeof(Vetor));
	V->tamanho = 0;
	V->qtde	 = 0;

	V->v = (int *)malloc(4);
	return V;
}
void Inicializa_vetor(Vetor *vetor, int value, int quant){
	int i = 0;
	vetor->tamanho = quant;
	vetor->qtde = quant;
	free(vetor->v);
	if(quant == 0)
		vetor->v = (int *) calloc(1, 4);
	else
		vetor->v = (int *) calloc(quant, 4);

	for(i = 0; i < quant; ++i){
		*(vetor->v) = value;
		++(vetor->v);
	}
	(vetor->v) -= i;
}
void Insere_fim_vetor(Vetor* vetor, int valor){
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

		Aumenta_vetor(vetor, Tam);
		for(i = 0; i < vetor->tamanho; ++i){
			*(vetor->v) = V[i];
			++(vetor->v);
		}

		(vetor->v) -= i;
		vetor->qtde = i;
	}
}
void Imprime_vetor(Vetor* vetor){
	int i, a = 0;
	printf("Vetor {");
	for(i = 0; i < vetor->tamanho; ++i)	{
		if(i == vetor->tamanho-1){
			printf("%i} ", *(vetor->v));
			++a;
		}
		else{
			printf("%i, ", *(vetor->v));
			++a;
		}
		++(vetor->v);
	}
	(vetor->v) -= i;
	if(a == 0){
		printf("}");
	}
	printf("\n");
}
void Ordena_cres_vetor(Vetor *vetor){
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
void Ordena_decre_vetor(Vetor *vetor){
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
void Atualiza_vetor(Vetor *vetor, int pos, int valor){
	if(vetor->tamanho != 0 && pos <= vetor->tamanho && pos > 0)
		vetor->v[pos-1] = valor;
}
void Insere_espec_vetor(Vetor *vetor, int pos, int valor){
	if(vetor->tamanho != 0 || pos <= vetor->tamanho){
		int Tam = vetor->tamanho, i, j;
		int V[Tam+1];

		for(i = 0; i < Tam; ++i){
			V[i] = *(vetor->v);
			++(vetor->v);	
		}
		(vetor->v) -= i;

		Aumenta_vetor(vetor, Tam);
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
		Insere_fim_vetor(vetor, valor);
	}
}
void Remove_vetor(Vetor *vetor, int pos, int elemento){
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
			Aumenta_vetor(vetor, Tam-2);
			for(i = 0; i < vetor->tamanho; ++i){
				*(vetor->v) = V[i];
				++(vetor->v);
			}

			(vetor->v) -= i;
			vetor->qtde = i;
		}

	}
}
int Procura_vetor(Vetor *vetor, int valor){
	int a = 0, j = 0;
	for(int i = 0; i < vetor->tamanho; ++i){
		if(vetor->v[i] == valor)
			return i;
	}
	return -1;	
}