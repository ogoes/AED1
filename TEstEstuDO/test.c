#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int* v; 
	int tamanho;
	int qtde;
}Vetor;

void Aumenta_Vetor(Vetor* V){
	int VV[V->qtde];
	for(int i = 0; i < V->qtde; ++i){
		VV[i] = V->v[i];
	}
	free(V->v);
	V->v = (int *) calloc(V->tamanho+10, sizeof(int));
	V->tamanho += 10;
	for(int i = 0; i < V->qtde; ++i){
		V->v[i] = VV[i];
	}
}
Vetor* Cria_vetor(){
	Vetor* V = (Vetor* ) calloc(1, sizeof(Vetor));
	V->v = (int *) calloc(10, sizeof(int));
	V->tamanho = 10;
	V->qtde = 0;

	return V;
}
void Insere_Vetor_fim(Vetor* V, int elemento){
	if(V->qtde == V->tamanho-1)
		Aumenta_Vetor(V);
	V->v[V->qtde] = elemento;
	++V->qtde;
}
void Imprime_Vetor(Vetor* V){
	printf("Vetor = [");
	for(int i = 0; i < V->qtde; ++i){
		printf(" %i", V->v[i]);
		if(i < V->qtde-1) printf(",");
	}
	printf(" ]\n");
}
void Remove_Vetor_Posicao(Vetor* V, int pos){
	if(pos >= 0 && pos < V->tamanho){	
		for(int i = pos; i < V->qtde; ++i){
			V->v[i] = V->v[i+1];
		}
		--V->qtde;
	}
}
void Remove_Vetor_Elemento(Vetor* V, int elemento){
	for(int i = 0; i < V->qtde; ++i){
		if(V->v[i] == elemento){
			for(int j = i; j < V->qtde; ++j){
				V->v[j] = V->v[j+1];
			}
		}
	}
	--V->qtde;
}
void Ordena_Vetor(Vetor* V){
	int prop;
	for(int i = 0; i < V->qtde; ++i){
		for(int j = 0; j < V->qtde; ++j){
			if(V->v[i] < V->v[j]){
				prop = V->v[i];
				V->v[i] = V->v[j];
				V->v[j] = prop;			
			}
		}
	}
}
void Atualiza_Vetor(Vetor* V, int pos, int elemento){
	if(pos >= 0 && pos < V->tamanho-1)
		V->v[pos] = elemento;
}
int Procura_Vetor(Vetor *V, int elemento){
	int a = 0, j = 0;
	for(int i = 0; i < V->tamanho; ++i){
		if(V->v[i] == elemento)
			return i;
	}
	return -1;	
}
void Insere_Posi_Espec_Vetor(Vetor* V, int pos, int elemento){
	int VV[V->qtde], j = 0;
	if(pos >= 0 && pos < V->qtde){
		for(int i = pos; i < V->qtde; ++i, ++j){
			VV[j] = V->v[i];
		}
		V->v[pos] = elemento;
		j = 0;
		++V->qtde;
		if(V->qtde == V->tamanho-1)
			Aumenta_Vetor(V);
		for(int i = pos+1; i < V->qtde; ++i, ++j){
			V->v[i] = VV[j];
		}
	}
	else if(pos >= 0 && pos < V->tamanho)
		Insere_Vetor_fim(V, elemento);
}
void main(){
	Vetor* V = Cria_vetor();
	
	for(int i = 1; i <= 5; ++i){
		Insere_Vetor_fim(V, i);
	}
	// Remove_Vetor_Posicao(V, 18);
	// Remove_Vetor_Elemento(V, 5);
	Insere_Posi_Espec_Vetor(V, 7, 9);
	Imprime_Vetor(V);
}