#include <stdio.h>
#include <stdlib.h>
// #include "PILHAENCADEADA.h"
#include "PILHASEQUENCIAL.h"

int A, B = 0, AUX;
int V[10];

void Read_Begin(FILE* F, FILE* P, Pilha* P1);
void Verifica(char c, Pilha* P1, FILE* P);
void Buffer();
void Opera(Pilha* P1, char c);
void Decimal(Pilha* P1);
void Manda(FILE* P);
void Manda2(FILE* P);


void Buffer(){
	V[B] = A;
	++B;
}
void Read_Begin(FILE* F, FILE* P, Pilha* P1){
	char c = fgetc(F);
	do{
		Verifica(c, P1, P);
		c = fgetc(F);
		if(c == -1)
			Manda2(P);
	}while(c != -1);
}
void Verifica(char c, Pilha* P1, FILE* P){
	if(c == '1'){
		A = 1;
		Buffer();
	}
	else if(c == '2'){
		A = 2;
		Buffer();
	}
	else if(c == '3'){
		A = 3;
		Buffer();
	}
	else if(c == '4'){
		A = 4;
		Buffer();
	}
	else if(c == '5'){
		A = 5;
		Buffer();
	}
	else if(c == '6'){
		A = 6;
		Buffer();
	}
	else if(c == '7'){
		A = 7;
		Buffer();
	}
	else if(c == '8'){
		A = 8;
		Buffer();
	}
	else if(c == '9'){
		A = 9;
		Buffer();
	}
	else if(c == '0'){
		A = 0;
		Buffer();
	}
	else if(c == '+'){
		Opera(P1, '+');
	}
	else if(c == '-'){
		Opera(P1, '-');
	}
	else if(c == '*'){
		Opera(P1, '*');
	}
	else if(c == '/'){
		Opera(P1, '/');
	}
	else if(c == '\n'){
		if(P1->qtde != 0){
			Pilha_Pop2(P1, &AUX);
			Manda(P);
		}
		else
			fprintf(P, "\n");
	}
	else{
		Decimal(P1);
	}
}
void Decimal(Pilha* P1){
	if(B != 0){
		int aux = 0;
		for(int i = 0; i < B; ++i){
			for(int j = i; j < B-1; ++j){
				V[i] *= 10;
			}
		}
		for(int i = 0; i < B; ++i){
			aux += V[i];
		}
		B = 0;
		Pilha_Push(P1, aux);
	}
}
void Opera(Pilha* P1, char c){
	int a, b;
	Pilha_Pop2(P1, &b);
	Pilha_Pop2(P1, &a);
	// if(P1->qtde == 0)
	// 	exit(0);
	if(c == '+'){
		AUX = a + b;
		Pilha_Push(P1, AUX);
	}
	else if(c == '-'){
		AUX = a - b;
		Pilha_Push(P1, AUX);
	}
	else if(c == '*'){
		AUX = a * b;
		Pilha_Push(P1, AUX);
	}
	else if(c == '/'){
		AUX = a / b;
		Pilha_Push(P1, AUX);
	}
}
void Manda(FILE* P){
	fprintf(P, "%i\n", AUX);  
	// askfjaskjda
}
void Manda2(FILE* P){
	fprintf(P, "%i", AUX);
	//alsdalsfa
}