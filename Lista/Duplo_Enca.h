#include <stdio.h>
#include <stdlib.h>


typedef char Tipo;

typedef struct no{
	Tipo data;
	struct no* prev;
	struct no* next;
}Node;

typedef struct{
	Node* begin;
	Node* end;
	int qtde;
}Stack;

Stack* Stack_cria(); // feita	
void Stack_desaloca(Stack* Q); // feita
void Stack_insere(Stack* Q, Tipo elemento, int pos); // feita
void Stack_insere_fim(Stack* Q, Tipo elemento); // feita
Tipo* Stack_remove(Stack* Q, int pos); // feita
int Stack_remove2(Stack* Q, int pos, Tipo* ende); // feita
int Stack_remove_elemento(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
Tipo* Stack_busca(Stack* Q, int pos); // feita 
int Stack_busca2(Stack* Q, int pos, Tipo* ende); // feita
int Stack_contem(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int Stack_posicao(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)); // feita
int Stack_tamanho(Stack* Q); // feita
void Stack_imprime(Stack* Q, void (*imprimeElemento)(Tipo*));

Stack* Stack_cria(){
	Stack* Q = (Stack* )calloc(1, sizeof(Stack));
	Q->begin = NULL;
	Q->end = NULL;
	Q->qtde = 0;

	return Q;
}
void Stack_desaloca(Stack* Q){
	Node* Aux = Q->begin;
	Node* XXX;
	while(Aux){
		XXX = Aux;
		Aux = Aux->next;
		free(XXX);
	}
	free(Q->begin);
	free(Q->end);
	free(Q);
}
void Stack_insere(Stack* Q, Tipo elemento, int pos){
	if(Q){
		Node* novo = (Node* )calloc(1, sizeof(Node));
		novo->data = elemento;
		novo->prev = NULL;
		novo->next = NULL;
		int a = 0;
		if(Q->qtde == 0){
			Q->begin = novo;
			Q->end = novo;
			++Q->qtde;
		}
		else if(pos < Q->qtde){
			if(pos <= 0){
				novo->next = Q->begin;
				Q->begin->prev = novo;
				Q->begin = novo;
				++Q->qtde;
			}
			else{
				Node* Aux = Q->begin;
				while(a != pos){
					Aux = Aux->next;
					++a;
				}
				novo->prev = Aux->prev;
				novo->next = Aux;
				Aux->prev = novo;
				novo->prev->next = novo;
				++Q->qtde;
			}
		}
		else{
			novo->prev = Q->end;
			Q->end->next = novo;
			Q->end = novo;
			++Q->qtde;
		}

	}
}
void Stack_insere_fim(Stack* Q, Tipo elemento){
	if(Q){
		Stack_insere(Q, elemento, Q->qtde);

	}
}
Tipo* Stack_remove(Stack* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 || pos > Q->qtde) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	Node* Aux = Q->begin;
	int a = 0;

	if(pos == 0){
		Q->begin = Aux->next;
		Aux->next->prev = NULL;
		*T = Aux->data;
		free(Aux);
		--Q->qtde;
	}
	else{
		while(a != pos){
			Aux = Aux->next;
			++a;
		}
		*T = Aux->data;
		Aux->prev->next = Aux->next;
		Aux->next->prev = Aux->prev;
		free(Aux);
		--Q->qtde;
	}
	return T;
}
int Stack_remove2(Stack* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 || pos > Q->qtde) return 0;
	Node* Aux = Q->begin;
	int a = 0;

	if(pos == 0){
		Q->begin = Aux->next;
		Aux->next->prev = NULL;
		*ende = Aux->data;
		free(Aux);
		--Q->qtde;
	}
	else{
		while(a != pos){
			Aux = Aux->next;
			++a;
		}
		*ende = Aux->data;
		Aux->prev->next = Aux->next;
		Aux->next->prev = Aux->prev;
		free(Aux);
		--Q->qtde;
	}
	return 1;
}
int Stack_remove_elemento(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	int a = 0;
	while(Aux){
		if((*compara)(&elemento, &Aux->data)){
			T = Stack_remove(Q, a);
			return 1;
		}
		Aux = Aux->next;
		++a;
	}
	free(T);
	return 0;
}
Tipo* Stack_busca(Stack* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 && pos >= Q->qtde) return NULL;
	int a = 0;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));

	Node* Aux = Q->begin;
	while(a != pos){
		Aux = Aux->next;
		++a;
	}

	*T = Aux->data;
	return T;
}
int Stack_busca2(Stack* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 && pos >= Q->qtde) return 0;
	int a = 0;

	Node* Aux = Q->begin;
	while(a != pos){
		Aux = Aux->next;
		++a;
	}

	*ende = Aux->data;
	return 1;
}
int Stack_contem(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	Tipo AA;
	while(Aux){
		AA = Aux->data;
		if((*compara)(&elemento, &AA))
			return 1;

		Aux = Aux->next;
	}

	return 0;
}
int Stack_posicao(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return -1;
	Node* Aux = Q->begin;
	Tipo AA;
	int i = 0;
	while(Aux){
		AA = Aux->data;
		if((*compara)(&elemento, &AA))
			return i;
		++i;
		Aux = Aux->next;
	}

	return -1;
}
int Stack_tamanho(Stack* Q){
	if(!Q) return 0;
	Node* Aux = Q->begin;
	int a = 0;
	while(Aux){
		++a;
		Aux = Aux->next;
	}

	return a;
}
void Stack_imprime(Stack* Q, void (*imprimeElemento)(Tipo*)){
	if(Q){
		Node* Aux = Q->begin;
		Tipo AA;
		while(Aux){
			AA = Aux->data;
			(*imprimeElemento)(&AA);
			if(Aux->next) printf(",");
			Aux = Aux->next;
		}
		printf("\n");
	}
}