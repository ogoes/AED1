#include <stdlib.h>

typedef struct{
    FILE *arq;
    char delimitador;
    char *buffer;
}LeitorArquivo;

LeitorArquivo* leitor_novo(char* arquivo, char delimitador, int tamBuffer);
char* leitor_ler1(LeitorArquivo* leitor);
void leitor_ler2(LeitorArquivo* leitor, char* endereco);
int leitor_temMaisToken(LeitorArquivo* leitor);

LeitorArquivo* leitor_novo(char* arquivo, char delimitador, int tamBuffer){
	LeitorArquivo *L = (LeitorArquivo *) calloc(1, sizeof(LeitorArquivo));
	L->arq = fopen(arquivo, "r");
	L->delimitador = delimitador;
	L->buffer = (char *) calloc(tamBuffer, sizeof(char));
	return L;
}

char* leitor_ler1(LeitorArquivo* leitor){
	
}