#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char codigo[15];
	char descricao[40];
	float valor;
}Produto;


void imprimeVetor(int v[], int n){
    int i;
    printf("{");
    for (i=0; i<n; i++){
        printf("%d",v[i]);
        if (i < n-1) printf(",");
    }
    printf("}");
    printf("\n");
}

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;   
}

void bubble_sort (int* v, int n){
    int i, fim;
    for (fim=n-1; fim>0; fim--) {
        int houve_troca = 0;
        for (i=0; i<fim; i++){
            if (v[i]>v[i+1]) {
                troca(&v[i], &v[i+1]);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0) return;
    }
}

void imprimeProduto(Produto V[], int n){
	 int i;
    printf("[");
    for (i=0; i<n; i++){
        printf("{%s, %s, R$%.2f}",V[i].codigo, V[i].descricao, V[i].valor);
        if (i < n-1) printf(",");
    }
    printf("]");
    printf("\n");
}

int main(){
    
    int v1[8] = {25,48,37,12,57,86,33,92};
    imprimeVetor(v1, 8);
    bubble_sort(v1, 8);
    imprimeVetor(v1, 8);

    Produto P[3] = {{"A1", "Mouse", 30}, {"A2", "Teclado", 50}, {"A3", "HeadPhone", 99.99}};
    printf("\n");
    imprimeProduto(P, 3);
    return 0;
}