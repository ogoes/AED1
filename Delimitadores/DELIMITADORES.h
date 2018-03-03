#include <stdio.h>

#include <stdlib.h>
// #include "PILHAENCADEADA.h"
#include "PILHASEQUENCIAL.h"

DEL* AUX;
DEL* AUX22;

void Read_Begin(FILE* Read, Pilha* P);
void Verifica(Pilha* P, char c);
void Empilha(Pilha* P, char c);
void Desempilha(Pilha* P, char c);
void ImprimeErro(Tipo* P);

int A = 0;
int B = 0;
int Ln = 1;

void Read_Begin(FILE* Read, Pilha* P){
	char c = fgetc(Read);
	DEL* AUX = (Tipo*)malloc(sizeof(Tipo));
	DEL* AUX22 = (Tipo*)malloc(sizeof(Tipo));
	do{
		if(c == '\n'){
			++Ln;		
		}
		Verifica(P, c);
		c = fgetc(Read);
	}while(c != -1);
	if(A > 0){
		for(int i = 0; i < A; ++i){
			printf("Delimitador de Fechamento Faltando\n");
			Pilha_Pop2(P, AUX);
			--A;
			ImprimeErro(AUX);
		}
	}
	if(A == 0 && B == 0)
		printf("Tudo Ok\n");
}
void Verifica(Pilha* P, char c){
	if(c == '{')
		Empilha(P, '{');
	else if(c == '}'){
		Empilha(P, '}');
		Desempilha(P, '}');
	}
	else if(c == '[')
		Empilha(P, '[');
	else if(c == ']'){
		Empilha(P, ']');
		Desempilha(P, ']');
	}
	else if(c == '(')
		Empilha(P, '(');
	else if(c == ')'){
		Empilha(P, ')');
		Desempilha(P, ')');
	}
}
void Empilha(Pilha* P, char c){
	DEL* AUX = (Tipo*)malloc(sizeof(Tipo));

	AUX->dado = c;
	AUX->linha = Ln;
	Pilha_Push(P, AUX);
	if(c != ')' && c != ']'&& c != '}')
		++A;
	free(AUX);
}
void Desempilha(Pilha* P, char c){
	AUX = (Tipo*)malloc(sizeof(Tipo));
	AUX22 = (Tipo*)malloc(sizeof(Tipo));

	if(A == 0){
		Pilha_Pop2(P, AUX22);
		ImprimeErro(AUX22);
		printf("Delimitador de Fechamento Sobrando\n");	
	}
	else{
		Pilha_Pop2(P, AUX22);
		Pilha_Pop2(P, AUX);
		if(AUX->dado == '{')
			if(AUX22->dado != '}'){
				printf("Imcompatibilidade de delimitadores\n");
				ImprimeErro(AUX22);
				Pilha_Push(P, AUX);
				Pilha_Push(P, AUX22);
			}
		else if(AUX->dado == '[')
			if(AUX22->dado != ']'){
				printf("Imcompatibilidade de delimitadores\n");
				ImprimeErro(AUX22);
				Pilha_Push(P, AUX);
				Pilha_Push(P, AUX22);
			}
		else if(AUX->dado == '(')
			if(AUX22->dado != ')'){
				printf("Imcompatibilidade de delimitadores\n");
				ImprimeErro(AUX22);
				Pilha_Push(P, AUX);
				Pilha_Push(P, AUX22);
			}
		--A;
	}
	free(AUX);
	free(AUX22);
}
void ImprimeErro(Tipo* P){
	printf("Erro, caractere: '%c' --- ", P->dado);
	printf("Linha %i\n", P->linha);
	B = 1;
}
