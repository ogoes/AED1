#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Imprime(int* V, int n){
	for(int i = 0; i < n; ++i){
		printf(" %i", V[i]);
		if(i < n-1) printf(",");
	}
	printf("\n");
}
void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;   
}
void Bubble(int* V, int n){ // Método da 'Bolha'
	int aux;
	for(int i = n-1; i > 0; --i){
		for(int j = 0; j < i; ++j){
			if(V[j] > V[j+1]){
				troca(&V[j], &V[j+1]);
			}
		}
	}
}
void Selection(int* V, int n){ // Método de 'Seleção'
	int M, aux;
	for(int i = n-1; i > 0; --i){
		M = 0;
		for(int j = 1; j <= i; ++j){
			if(V[j] > V[M]){
				M = j;
			}
		}
		if(i != M){
			troca(&V[i], &V[M]);
		}
	}
}
void Insertion(int* V, int n){ // Método da 'Inserção' ou 'Baralho'
	int j, aux;
	for(int i = 1; i < n; ++i){
		j = i;
		while(j > 0 && V[j-1] > V[j]){
			troca(&V[j], &V[j-1]);
			--j;
		}
	}
}
int BuscaBin(int V[], int n, int P){
	int min = 0, max = n-1, M;
	if(P < V[0] || P > V[n-1])
		return 0;
	while(min <= max){
		M = (int)(min+max)/2;
		if(P == V[M])
			return 1;
		else if(V[M] < P){
			min = M+1;
		}
		else{
			max = M-1;
		}
	}
	return 0;
}
int BuscaLin(int V[], int n, int P){
	for(int i = 0; i < n; ++i){
		if(P == V[i])
			return 1;
	}
	return 0;
}
void criaHeap(int* V, int i, int f){
	int aux = V[i];
	int j = i*2 + 1;
	while(j <= f){
		if(j < f)
			if(V[j] < V[j + 1])
				j += 1;
		if(aux < V[j]){
			V[i] = V[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			j = f + 1;
	}
	V[i] = aux;
}
void Heap(int* V, int n){
	int i, aux;
	for(i = (n-1)/2; i >= 0; --i){
		criaHeap(V, i, n-1);
	}
	for(i = n-1; i >= 1; --i){
		troca(&V[0], &V[i]);
		criaHeap(V, 0, i - 1);
	}
}
