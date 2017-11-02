#include "POS_FIXO.h"

void main(){
	FILE* F;
	FILE* P;

	Pilha* P1 = Pilha_Criar();
	F = fopen("Teste1_RNP.txt", "r");
	P = fopen("Teste1_RNP_resultado.txt", "w");
	if(!F || !P){
		printf("Erro em abrir arquivos\n");
		exit(0);
	}
	
	Read_Begin(F, P, P1);

	free(P1);
	fclose(F);
	fclose(P);
}