#include "Duplo_Enca_Sentinel.h"
#include <stdbool.h>
#include <stdlib.h>
// #include "Duplo_Enca.h"
// #include "Sequencial.h"


typedef struct{
	Node* node;
	Queue* Q;
}Interator;

bool HasNext(Interator* I);
Tipo Next(Interator* I);
Tipo Remove(Interator* I);

Interator* initialize(Queue* Q){
	Interator* I = (Interator* )calloc(1, sizeof(Interator));
	I->node = Q->sentinel;
	I->Q = Q;
	return I;
}

bool HasNext(Interator* I){
	if(I->node->next == I->Q->sentinel) return false;
	return true;
}

Tipo Next(Interator* I){
	I->node = I->node->next;
	Tipo A = I->node->data;
	return A;
}

Tipo Remove(Interator* I){
	I->node = I->node->next;
	Tipo* A = queue_remove(I->Q, 0);

	return *A;
}