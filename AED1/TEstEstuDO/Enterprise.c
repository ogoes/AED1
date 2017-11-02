#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char cod[15];
	char desc[50];
	float valor;
	int qtde;
}Produto;

typedef struct{
	char nome[30];
	int capacidade;
	int qtde_itens;
	Produto** estoque;
}Empresa;

Produto* Produto_Novo(char* Cod, Char* Desc, float valor){
	Produto* P = (Produto* ) calloc(1, sizeof(Produto));
	strcpy(P->cod, Cod);
	strcpy(P->desc, Desc);
	P->valor = valor;
	P->qtde = 0;
	return P;
}
Empresa Empresa_Novo(char* Nome, int cap){
	Empresa* E = (Empresa* ) calloc(1, sizeof(Empresa));
	E->capacidade = cap;
	E->qtde_itens = 0;
	E->estoque = (Produto**) calloc(cap, sizeof(Produto*));
	return E;
}
int Cadastra_Produto(Empresa* E, char* Cod, char* Desc, float valor){
	if(!E || E->qtde_itens == E->capacidade)
		return -1;
	E->estoque[E->qtde] = Produto_Novo(Cod, Desc, valor);
	++E->qtde_itens;

	return E->qtde_itens;
}
int Inclui_Estoque(Empresa* E, char* Cod, int qtde){
	if(!E)
		return -1;
	for(int i = 0; i < E->qtde_itens; ++i){
		if(strcmp((E->estoque[i])->cod, Cod) == 0){
			(E->estoque[i])->qtde += qtde;
			return (E->estoque[i])->qtde;
		}
	}
	return -1;
}
int Remove_Estoque(Empresa* E, char* Cod, int qtde){
	if(!E)
		return -1;
	for(int i = 0; i < E->qtde_itens; ++i){
		if(strcmp((E->estoque[i])->cod, Cod) == 0){
			if((E->estoque[i])->qtde > 0){
				(E->estoque[i])->qtde -= qtde;
				return (E->estoque[i])->qtde;
			}
		}
	}
	return -1;
}
int Descadastra_Produto(Empresa* E, char* Cod){
	if(!E)
		return -1;
	for(int i = 0; i < E->qtde_itens; ++i){
		if(strcmp((E->estoque[i])->cod, Cod) == 0){
			for(int j = i; j < E->qtde_itens-1; ++j){
				memcpy(E->estoque[j], E->estoque[j+1], sizeof(Produto));
			}
			--E->qtde_itens;
			return E->qtde_itens;
		}
	}
	return -1;
}
void Imprime_Produto(Produto* P){
	printf("Código [%s]\n", P->cod);
	printf("Descrição [%s]\n", P->desc);
	printf("Valor [%.2f]\n", P->valor);
	printf("Quantidade [%i]\n", P->qtde);
	printf("\n");
}
void Imprime_Empresa(Empresa* E){
	printf("Nome [%s]\n", E->nome);
	printf("Capacidade [%i]\n", E->capacidade);
	printf("Quantidade de Itens [%i]\n", E->qtde_itens);
	for(int i = 0; i < E->qtde_itens; ++i){
		Imprime_Produto(E->estoque[i]);
	}
}
void main(){
}