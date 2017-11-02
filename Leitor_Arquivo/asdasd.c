#include <stdlib.h>
#include <stdio.h>

typedef struct{
    FILE *arq;
    char *Buffer;
    char del;
    int tamBuffer, i;
    long int tamArq;
}LeitorArquivo;

LeitorArquivo* leitor_novo(char* arquivo, char delimitador, int tamBuffer); // --- feita
char* leitor_ler1(LeitorArquivo* leitor); // --- feita
void leitor_ler2(LeitorArquivo* leitor, char* endereco); // --- em andamento
int leitor_temMaisToken(LeitorArquivo* leitor); // --- ajustes
void leitor_Buffer(LeitorArquivo * L); // --- feita

void leitor_Buffer(LeitorArquivo * L){
	int i = 0;
	L->Buffer -= L->i;

	if(L->tamArq >= L->tamBuffer){
		while(i <= L->tamBuffer && L->tamArq > 0){
			*(L->Buffer) = fgetc(L->arq);
			++(L->Buffer);
			++i;
		}
		(L->Buffer) -= i;
		L->tamArq -= i;
	}
	else if(L->tamArq >= 0){
		printf("%li\n", L->tamArq);
		while(i <= L->tamArq){
			*(L->Buffer) = fgetc(L->arq);
			++(L->Buffer);
			++i;
		}
		*(L->Buffer) = '\0';
		L->tamArq = -1;	
		(L->Buffer) -= (i+1);
	}
	if(L->tamArq == 0){
		L->tamArq = -1;
	}
	
	L->i = 0;
}

LeitorArquivo* leitor_novo(char* arquivo, char delimitador, int tamBuffer){
	LeitorArquivo * L = (LeitorArquivo *) calloc(1, sizeof(LeitorArquivo));
	L->arq = fopen(arquivo, "r");
	if(!L->arq){
		free(L);
		return NULL;
	}
	fseek(L->arq, 0, SEEK_END);
	L->tamArq = ftell(L->arq);
	rewind(L->arq);
	
	L->tamBuffer = tamBuffer;
	L->del = delimitador;
	L->Buffer = (char *) calloc(tamBuffer, sizeof(char));
	leitor_Buffer(L);
	return L;
}

int leitor_temMaisToken(LeitorArquivo* leitor){
	if(leitor->tamArq != 0){
		return 1;
	}
	else
		return 0;
}

char *leitor_ler1(LeitorArquivo* leitor){
	int i = 0, a = 0, k = 0;

	// printf("%s\n", leitor->Buffer);
	while(i < leitor->tamBuffer - leitor->i && a == 0){
		if(*(leitor->Buffer) == leitor->del || *(leitor->Buffer) == '\n' || *(leitor->Buffer) == '\0')
			++a;
		else{
			++i;
			++(leitor->Buffer);
		}
	}
	leitor->Buffer -= i;
	if(a == 0){
		fseek(leitor->arq, -(i+1), SEEK_CUR);
		leitor->tamArq += i;
		leitor_Buffer(leitor);
	}

	i = 0, a = 0;
	while(i < leitor->tamBuffer && a == 0){
		if(*(leitor->Buffer) == leitor->del || *(leitor->Buffer) == '\n' || *(leitor->Buffer) == '\0')
			++a;
		else{
			++i;
			++(leitor->Buffer);
		}
	}
	leitor->Buffer -= i;
	char * S = (char *) calloc(i+1, sizeof(char));
	int c = 0;
	while(c < i){
		*S = *(leitor->Buffer);
		++c, ++S;
		++(leitor->Buffer), ++leitor->i;
	}
	++S;
	*S = '\0';
	S -= (c+1);
	++(leitor->Buffer), ++leitor->i;

	if(leitor->tamArq < leitor->tamBuffer){
		// leitor_Buffer(leitor);
		printf("EROR\n");
	}
	if(leitor->tamArq == -1)
		leitor->tamArq = 0;
	return S;
}

void leitor_ler2(LeitorArquivo* leitor, char *endereco){
	int i = 0, a = 0;
	while(i < leitor->tamBuffer - leitor->i && a == 0){
		if(*(leitor->Buffer) == leitor->del || *(leitor->Buffer) == '\n' || feof(leitor->arq))
			++a;
		else{
			++i;
			++(leitor->Buffer);
		}
	}
	leitor->Buffer -= i;
	if(a == 0){
		fseek(leitor->arq, -i, SEEK_CUR);
		leitor_Buffer(leitor);
	}
	int c = 0;
	while(*(leitor->Buffer) != leitor->del || *(leitor->Buffer) != '\n'){
		*endereco = *(leitor->Buffer);
		++c, ++endereco;
		++(leitor->Buffer), ++leitor->i;
	}
	++endereco;
	*endereco = '\0';
	endereco -= (c+1);
	++(leitor->Buffer), ++leitor->i;

	if(leitor->i == leitor->tamBuffer)
		leitor_Buffer(leitor);
}

void main(){
	LeitorArquivo *L = leitor_novo("lista.txt", ';', 15);
	char *s;
	while(leitor_temMaisToken(L)){
		// getchar();
		s = leitor_ler1(L);
		printf("%s\n", s);
		free(s);
	}
	printf("%li\n", L->tamArq);

	fclose(L->arq);
}