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
void Bubble(int* V, int n){ // Método da 'Bolha'
	int aux;
	for(int i = n-1; i > 0; --i){
		for(int j = 0; j < i; ++j){
			if(V[j] > V[j+1]){
				aux = V[j];
				V[j] = V[j+1];
				V[j+1] = aux;
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
			aux = V[i];
			V[i] = V[M];
			V[M] = aux;	
		}
	}
}
void Insertion(int* V, int n){ // Método da 'Inserção' ou 'Baralho'
	int j, aux;
	for(int i = 1; i < n; ++i){
		j = i;
		while(j > 0 && V[j-1] > V[j]){
           	aux = V[j];
			V[j] = V[j-1];
			V[j-1] = aux;
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
