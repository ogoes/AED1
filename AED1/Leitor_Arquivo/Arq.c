#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	FILE* arq;
	char* Buffer;
	char del;
	long int tamArq;
	int tamBuffer, i, a;
}Leitor;

Leitor* leitor_novo(char* arquivo, char del, int tamBuffer);
char* leitor_ler1(Leitor* L);
void leitor_ler2(Leitor* L, char* end);
int tem_mais_token(Leitor* L);
void leitor_Buffer(Leitor* L);



Leitor* leitor_novo(char *arquivo, char del, int tamBuffer){
	Leitor * L = (Leitor *) calloc(1, sizeof(Leitor));
	L->arq = fopen(arquivo, "r");
	if(!L->arq){
		free(L);
		return NULL;
	}
	L->del = del;
	L->tamBuffer = tamBuffer;
	fseek(L->arq, 0, SEEK_END);
	L->tamArq = ftell(L->arq);
	rewind(L->arq);

	L->Buffer = (char *) calloc(tamBuffer+1, sizeof(char));
	leitor_Buffer(L);
	return L;
}
char* leitor_ler1(Leitor* L){
	int i = 0, a = 0;
	while(i < L->tamBuffer - L->i && a == 0){
		if(L->Buffer[i] == L->del || L->Buffer[i] == '\n' || L->Buffer[i] == '\0')
			++a;
		else
			++i;
	}
	if(a == 0 && L->tamArq > 0){
		fseek(L->arq, -(i+1), SEEK_CUR);
		L->tamArq += i;
		leitor_Buffer(L);
	}
	i = 0, a = 0;
	while(i < L->tamBuffer && a == 0){
		if(L->Buffer[i] == L->del || L->Buffer[i] == '\n' || L->Buffer[i] == '\0')
			++a;
		else
			++i;
	}
	printf("%s\n", L->Buffer);
	char *S = (char *) calloc(i+1, sizeof(char));
	int c = 0;
	while(c < i){
		*S = *(L->Buffer);
		++c, ++S;
		++(L->Buffer), ++L->i, ++L->a;
	}
	++S;
	*S = '\0';
	S -= (c+1);
	++(L->Buffer), ++L->i, ++L->a;

	if(L->a == L->tamBuffer){
		leitor_Buffer(L);
	}
	if(L->tamArq == 0)
		L->a -= i;
	return S;
}
void leitor_Buffer(Leitor* L){
	int i = 0;
	if(L->a >= L->tamBuffer)
		L->a = 0;
	L->Buffer -= L->i;

	if(L->tamArq >= L->tamBuffer){
		while(i <= L->tamBuffer){
			*(L->Buffer) = fgetc(L->arq);
			++(L->Buffer);
			++i;
		}
		(L->Buffer) -= i;
		L->tamArq -= i;
	}
	else{
		if(L->tamArq >= 0){
			printf("%li\n", L->tamArq);
			while(i <= L->tamArq){
				*(L->Buffer) = fgetc(L->arq);
				++(L->Buffer);
				++i;
			}
			*(L->Buffer) = '\0';
			L->tamArq = 0;	
			(L->Buffer) -= (i+1);
		}
	}

	L->i = 0;
}
int tem_mais_token(Leitor* L){
	if(L->tamArq == 0 && L->a == 0)
		return 0;
	else
		return 1;
}


void main(){
	Leitor* L = leitor_novo("lista.txt", ';', 15);
	char* s;
	while(tem_mais_token(L)){
		getchar();
		s = leitor_ler1(L);
		printf("%s\n", s);
		free(s);
		printf("%li\n", L->tamArq);

	}


	fclose(L->arq);
}