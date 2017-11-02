#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char codigo[15];
	char *descricao;
	float valor;
	int qtde;
}Produto;

typedef struct{
	char nome[30];
	int capacidade;
	int qtde;
	Produto **estoque;
}Empresa;


Produto* produto_novo(char *cod, char *desc, float valor);
Empresa* empresa_novo(char *nome, int cap); 
int cadastraProduto(Empresa *E, char *cod, char *desc, float valor);
int incluiEstoque(Empresa *E, char *cod, int qtde);
int removeEstoque(Empresa *E, char *cod, int qtde);
int descadastraProduto(Empresa *E, char *cod);
void produto_imprimir(Produto *P);
void empresa_imprimir(Empresa *E);


Produto* produto_novo(char *cod, char *desc, float valor){
	Produto *P = (Produto *) calloc(1, sizeof(Produto));
	strcpy(P->codigo, cod);
	P->descricao = (char *) calloc(strlen(desc)+1, sizeof(char));
	strcpy(P->descricao, desc);
	P->valor = valor;
	P->qtde = 0;

	return P;
}
Empresa* empresa_novo(char *nome, int cap){
	Empresa *E = (Empresa *) calloc(1, sizeof(Empresa));
	strcpy(E->nome, nome);
	E->capacidade = cap;
	E->qtde = 0;
	E->estoque = (Produto **) calloc(cap, sizeof(Produto *));

	return E;
}
int cadastraProduto(Empresa *E, char *cod, char *desc, float valor){
	if(!E || E->qtde == E->capacidade)
		return -1;

	E->estoque[E->qtde] = produto_novo(cod, desc, valor);
	E->qtde += 1;

	return E->qtde;
}
int incluiEstoque(Empresa *E, char *cod, int qtde){
	if(!E)
		return -1;
	int a, i;
	for(i = 0, a = 0; i < E->qtde; ++i){
		if(strcmp((E->estoque[i])->codigo, cod) == 0){
			(E->estoque[i])->qtde += qtde;
			++a;
			return (E->estoque[i])->qtde;
		}
		if(a == 0 && i == (E->qtde-1))
			return -1;
	}
}
int removeEstoque(Empresa *E, char *cod, int qtde){
	if(!E)
		return -1;
	int a, i;
	for(i = 0, a = 0; i < E->qtde; ++i){
		if(strcmp((E->estoque[i])->codigo, cod) == 0){
			if((E->estoque[i])->qtde > 0){
				(E->estoque[i])->qtde -= qtde;
				++a;
				return (E->estoque[i])->qtde;
			}
			else
				return -1;
		}
		if(a == 0 && i == (E->qtde-1))
			return -1;
	}
}
int descadastraProduto(Empresa *E, char *cod){
	if(!E)
		return -1;
	int a, i;
	for(i = 0, a = 0; i < E->qtde; ++i){
		if(strcmp((E->estoque[i])->codigo, cod) == 0){
			for(int j = i; j < E->qtde-1; ++j){
				// free(E->estoque[i]);
				memcpy(E->estoque[j], E->estoque[j+1], sizeof(Produto));
			}
			++a;
			--E->qtde, --i;
		}
		if(a == 0 && i == (E->qtde-1))
			return -1;
	}
	return E->qtde;
}
void produto_imprimir(Produto *P){
	if(!P)
		printf("Endereço não encontrado\n");
	else{
		printf("Codigo: %s\n", P->codigo);
		printf("Descrição: %s\n", P->descricao);
		printf("Valor: R$%.2f\n", P->valor);
		printf("Quantidade: %i\n", P->qtde);
	}
	printf("\n");
}
void empresa_imprimir(Empresa *E){
	printf("Nome: %s\n", E->nome);
	printf("Capacidade: %i\n", E->capacidade);
	printf("Estoque = {");
	if(E->qtde > 0){
		for(int i = 0; i < E->qtde; ++i){
			printf(" [%i](%s; %i)", i+1, (E->estoque[i])->codigo, (E->estoque[i])->qtde);
			if(i != E->qtde-1) printf(":");
		}
	}
	printf(" }\n\n");
}