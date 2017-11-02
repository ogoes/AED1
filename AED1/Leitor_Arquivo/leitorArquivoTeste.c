#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "leitorArquivo.h"




void testeTempo1(){
	LeitorArquivo* l = leitor_novo("lista.txt", ';', 100);
	time_t inicio = time(NULL);
	while(leitor_temMaisToken(l)){
		char* s = leitor_ler1(l);
		printf("[%s] \n", s);
		free(s);	
	}
	time_t fim = time(NULL); 
	printf("Tempo1: %.2f\n", difftime(fim, inicio));
}

void testeTempo2(){
	LeitorArquivo* l = leitor_novo("lista.txt", ';', 100);
	time_t inicio = time(NULL);
	while(leitor_temMaisToken(l)){
		char* s = leitor_ler2(l);
		printf("[%s] \n", s);
		free(s);	
	}
	time_t fim = time(NULL); 
	printf("Tempo 2: %.2f\n", difftime(fim, inicio));
}


int main(){
	testeTempo1();
	testeTempo2();

}