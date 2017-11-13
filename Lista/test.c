// #include "Duplo_Enca.h"
#include "Duplo_Enca_Sentinel.h"
// #include "Sequencial.h"


void print(Tipo *A){
	printf(" %i", *A);
}
int compara(Tipo* A, Tipo* B){
	if(*A == *B) return 1;
	return 0;
}

void main(){
	Queue* Q = queue_cria();
	for(int i = 1; i < 11; ++i){
		queue_insere(Q, i, i-1);
	}
	queue_imprime(Q, print);
	printf("%i\n", queue_tamanho(Q));
	int a = queue_posicao(Q, 5, compara);
	printf("%i\n", a);


	queue_desaloca(Q);
}
/*Queue* queue_cria(); // feita
void queue_desaloca(Queue* Q); // feita
void queue_insere(Queue* Q, Tipo elemento, int pos); // feita
void queue_insere_fim(Queue* Q, Tipo elemento); // feita
Tipo* queue_remove(Queue* Q, int pos); // feita
int queue_remove2(Queue* Q, int pos, Tipo* ende); // feita
int queue_remove_elemento(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
Tipo* queue_busca(Queue* Q, int pos); // feita
int queue_busca2(Queue* Q, int pos, Tipo* ende); // feita
int queue_contem(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int queue_posicao(Queue* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int queue_tamanho(Queue* Q); // feita
void queue_imprime(Queue* Q, void (*imprimeElemento)(Tipo*)); // feita*/