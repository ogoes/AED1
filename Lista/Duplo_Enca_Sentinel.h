#include <stdio.h>
#include <stdlib.h>


typedef int Tipo;

typedef struct no{
	Tipo data;
	struct no* prev;
	struct no* next;
}Node;

typedef struct{
	Node* sentinel;
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
void Stack_imprime(Stack* Q, void (*imprimeElemento)(Tipo*)); // feita


Node* novono(Tipo valor, Node* next, Node* prev){
	Node* novo = (Node* )calloc(1, sizeof(Node));
	novo->data = valor;
	novo->next = next;
	novo->prev = prev;

	return novo;
}
Node* auxpos(Stack* Q, int pos){
	if(pos < 0) pos = 0;
	if(pos > Q->qtde) pos = Q->qtde;
	Node* Aux = Q->sentinel;
	int i = 0;
	while(i < pos){
		Aux = Aux->next;
		++i;
	}

	return Aux;
}
void addfrente(Node* A, Node* B){
	B->prev = A;
	B->next = A->next;
	A->next->prev = B;
	A->next = B;
}
void remove1(Node* A, Tipo* B){
	A->prev->next = A->next;
	A->next->prev = A->prev;

	*B = A->data;
	free(A);
}
Stack* Stack_cria(){
	Stack* Q = (Stack* )calloc(1, sizeof(Stack));
	Q->qtde = 0;
	Q->sentinel = (Node*)calloc(1, sizeof(Node));
	Q->sentinel->next = Q->sentinel;
	Q->sentinel->prev = Q->sentinel;

	return Q;
}
void Stack_desaloca(Stack* Q){
	Node* Aux = Q->sentinel->next;
	Node* XXX;
	while(Aux != Q->sentinel){
		XXX = Aux;
		Aux = Aux->next;
		free(XXX); XXX = NULL;
	}
	Aux = NULL;
	free(Q->sentinel); Q->sentinel = NULL;
	free(Q); Q = NULL;
}
void Stack_insere(Stack* Q, Tipo elemento, int pos){
	Node* novo = novono(elemento, NULL, NULL);
	Node* AUX = auxpos(Q, pos);
	addfrente(AUX, novo);
	++Q->qtde;
}
void Stack_insere_fim(Stack* Q, Tipo elemento){
	if(Q)	
		Stack_insere(Q, elemento, Q->qtde);
}
Tipo* Stack_remove(Stack* Q, int pos){
	if(!Q) return NULL;
	if(pos < 0 || pos >= Q->qtde) return NULL;
	if(Q->sentinel->next == Q->sentinel) return NULL;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	Node* AUX = auxpos(Q, pos+1);
	remove1(AUX, T);
	--Q->qtde;
	
	return T;
}
int Stack_remove2(Stack* Q, int pos, Tipo* ende){
	if(!Q) return 0;
	if(pos < 0 || pos >= Q->qtde) return 0;
	if(Q->sentinel->next == Q->sentinel) return 0;
	Node* AUX = auxpos(Q, pos+1);
	remove1(AUX, ende);
	--Q->qtde;
	
	return 1;
}
int Stack_remove_elemento(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	if(Q->sentinel->next == Q->sentinel) return 0;
	Node* Aux = Q->sentinel->next;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));
	int a = 0;
	while(Aux != Q->sentinel){
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
	if(Q->sentinel->next == Q->sentinel) return NULL;
	int a = 0;
	Tipo* T = (Tipo* )calloc(1, sizeof(Tipo));

	Node* Aux = Q->sentinel->next;
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
	if(Q->sentinel->next == Q->sentinel) return 0;
	int a = 0;

	Node* Aux = Q->sentinel;
	while(a != pos){
		Aux = Aux->next;
		++a;
	}

	*ende = Aux->data;
	return 1;
}
int Stack_contem(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return 0;
	if(Q->sentinel->next == Q->sentinel) return 0;
	Node* Aux = Q->sentinel->next;
	Tipo AA;
	while(Aux != Q->sentinel){
		AA = Aux->data;
		if((*compara)(&elemento, &AA))
			return 1;

		Aux = Aux->next;
	}

	return 0;
}
int Stack_posicao(Stack* Q, Tipo elemento, int (*compara)(Tipo*, Tipo*)){
	if(!Q) return -1;
	if(Q->sentinel->next == Q->sentinel) return -1;
	Node* Aux = Q->sentinel->next;
	Tipo AA;
	int i = 0;
	while(Aux != Q->sentinel){
		AA = Aux->data;
		if((*compara)(&elemento, &AA))
			return i;
		++i;
		Aux = Aux->next;
	}

	return -1;
}
int Stack_tamanho(Stack* Q){
	if(!Q) return -1;
	if(Q->sentinel->next == Q->sentinel) return -1;
	Node* Aux = Q->sentinel->next;
	int a = 0;
	while(Aux != Q->sentinel){
		++a;
		Aux = Aux->next;
	}

	return a;
}
void Stack_imprime(Stack* Q, void (*imprimeElemento)(Tipo*)){
	if(Q != NULL){
		Node* Aux = Q->sentinel->next;
		Tipo AA;
		while(Aux != Q->sentinel){
			AA = Aux->data;
			(*imprimeElemento)(&AA);
			if(Aux->next != Q->sentinel) printf(",");
			Aux = Aux->next;
		}
		printf("\n");
	}
}