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

void main(){
	int V[] = {0, 1, 9, 3, 4, 5, 6, 7, 2, 2};
	Imprime(V, 10);
	Bubble(V, 10);
	Selection(V, 10);
	Insertion(V, 10);
	Imprime(V, 10);

}