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
Produto* produto_novo(char *cod, char *desc, float valor); // -- feita
Empresa* empresa_novo(char *nome, int cap); // -- feita
int cadastraProduto(Empresa *E, char *cod, char *desc, float valor); // -- feita
int incluiEstoque(Empresa *E, char *cod, int qtde); // -- feita
int removeEstoque(Empresa *E, char *cod, int qtde); // -- feita
int descadastraProduto(Empresa *E, char *cod); // -- em andamento
void produto_imprimir(Produto *P); // -- feita
void empresa_imprimir(Empresa *E); // -- feita



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
			(E->estoque[i])->qtde -= qtde;
			++a;
			return (E->estoque[i])->qtde;
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
			free(E->estoque[i]);
			++a;
			return --E->qtde;
		}
		if(a == 0 && i == (E->qtde-1))
			return -1;
	}
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
			if(i == E->qtde-1)
				printf(" [%i](%s; %i)", i+1, (E->estoque[i])->codigo, (E->estoque[i])->qtde);
			else
				printf(" [%i](%s; %i):", i+1, (E->estoque[i])->codigo, (E->estoque[i])->qtde);

		}
	}
	printf(" }\n\n");
}

void main(){
	Empresa *E = empresa_novo("GOES & CIA", 4);
	Produto *P = produto_novo("TEST1", "testse", 12.2);
	cadastraProduto(E, "TEST2", "testess", 12.6);
	// incluiEstoque(E, "TEST2", 4);
	descadastraProduto(E, "TEST2");
	// removeEstoque(E, "OO1", 1);
	empresa_imprimir(E);
	produto_imprimir(E->estoque[/* posição */]);
}