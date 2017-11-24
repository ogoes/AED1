#include "interator.h"
// #include "Duplo_Enca_Sentinel.h"
// #include "Duplo_Enca.h"
// #include "Sequencial.h"

void main(){
	Queue* Q = queue_cria();
	Interator* I = initialize(Q);
	for(int i = 0; i < 10; ++i){
		queue_insere_fim(Q, i);
	}
	while(HasNext(I)){
		printf(" %i", Next(I));
	}
	printf("\n");
}