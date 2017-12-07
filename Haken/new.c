#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void retira_simbolos(char str1[], char str2[]) // função para retirar os simbolos
{
	int a = 0, k = 0;
	char string3[100]; // string que recebe o resuultado final

	strcpy(string3, str2); // copia da string, para não alterar o parametro original
	for(int i = 0; i < strlen(string3); i++){ // laço que percorre toda a string 3
		for(int j = 0; j < strlen(str1); j++){ // laço que percorre toda a string inicial com os simbolos
			if(string3[i] == str1[j]){ // campara cada elemento da string 1 com todos os elementos da string 3
				for(k = i; k < strlen(string3); k++)
					string3[k] = string3[k+1]; // passa o elemento posterior para traz
			}
		}
	}
	printf("%s\n", str1); ///   
	printf("%s\n", str2); /// Mostra as strings iniciais 
	printf("%s\n", string3); /// Mostra o resultado
}


int main(int argc, char* argv[]){
	FILE* F1 = fopen(argv[1], "r"); // abertura do arquivo do primeiro parametro de argv
	FILE* F2 = fopen(argv[2], "r"); // abertura do arquivo do segundo parametro de argv

	char string1[100]; // declara string
	char string2[100]; // declara string
	fgets(string1, sizeof(string1), F1); // recebe uma string do arquivo 1
	fgets(string2, sizeof(string2), F2); // recebe uma string do  arquivo 2


	retira_simbolos(string1,string2); // chama a função para resolver o problema
	
}