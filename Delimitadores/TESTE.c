// #include "DELIMITADORES.h"
#include "Del.h"
#include <stdio.h>
#include <stdlib.h>


void main(){
	FILE* Read;
	Read = fopen("arquivoteste.c", "r");
	if(!Read){
		printf("Erro em abrir arquivo\n");
		exit(0);
	}
	Pilha* P = Pilha_Criar();
	Read_Begin(Read, P);

	fclose(Read);
}