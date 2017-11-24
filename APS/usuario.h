#include <ctype.h>
#include "database.h"




Database* createData(char string[]);
int createTable(Database* db, char* string);
int Select(Database* db, char* string);
int Insert(Database* db, char* string);
int A = 0, B = -1, C = 0, T = 0, atts = 0;
int V[10];
int qtdeatts = 1;
void vetor(int B){
	V[C] = B;
	++C;
}
void veri(char c){
	if(c == '1')
		B = 1;
	else if(c == '2')
		B = 2;
	else if(c == '3')
		B = 3;
	else if(c == '4')
		B = 4;
	else if(c == '5')
		B = 5;
	else if(c == '6')
		B = 6;
	else if(c == '7')
		B = 7;
	else if(c == '8')
		B = 8;
	else if(c == '9')
		B = 9;
	else if(c == '0')
		B = 0;


	if(B != -1){
		vetor(B);
	}
}
int decimalInt(){
	if(C != 0){
		int aux = 0;
		for(int i = 0; i < C; ++i)
			for(int j = i; j < C-1; ++j)
				V[i] *= 10;
		for(int i = 0; i < C; ++i)
			aux += V[i];
		C = 0;
		return aux;
	}
}



Database* createData(char* string){
	int t = strlen(string);
	while(string[t] != ';' && t > 16)
		--t;
	if(string[t] != ';'){
		bold(1);
		printf(" ERROR: invalid command line\n \";\" not founded\n");
		bold(0);
		return NULL;
	}
	for(int i = 0; i < 16; ++i){
		string[i] = toupper(string[i]);
	}
	if(strncmp(string, "CREATE DATABASE ", 16) != 0)
		return NULL;
	string += 16;
	char nome[30];
	int i = 0;
	while(string[i] != ' ' && string[i] != ';'){
		nome[i] = string[i];
		++i;
	}
	nome[i] = '\0';
	Database* db = criarDatabase(nome);
	++A;
	if(db) printf("Success\n");
	else printf("Failure\n"), --A;
	return db;
}
int createTable(Database* db, char* string){
	if(A == 0){
		bold(1);
		printf("\tDatabase don't exists\n");
		bold(0);
		return 0;
	}
	int t = strlen(string);
	while(string[t] != ';' && t > 16)
		--t;
	if(string[t] != ';'){
		bold(1);
		printf(" ERROR: invalid command line\n \";\" not founded\n");
		bold(0);
		return 0;
	}
	int a = 0, i = 0;
	/*while(string[i] != ';'){
		if(string[i] == '(' || string[i] == ')')
			++a;
	}
	if(a < 2){
		bold(1);
        printf("    ERROR: invalid command line\n");
        bold(0);
        return 0;
	}*/
	for(int i = 0; i < 13; ++i){
		string[i] = toupper(string[i]);
	}
	if(strncmp(string, "CREATE TABLE ", 13) != 0)
		return 0;
	string += 13;
	char nome[30];
	for(i = 0; i < db->qtdeTabelas; ++i){
		if(strcmp(nome, db->tabelas[i]->nome) == 0){
			bold(1);
			printf(" ERROR: This table already exists\n");
			bold(0);
			return 0;
		}

	}
	i = 0;
	while(string[i] != ' ' && string[i] != '('){
		if(string[i] == ';'){
			bold(1);
			printf(" ERROR: invalid command line\n");
			bold(0);
			return 0;
		}
		nome[i] = string[i];
		++i;
	}
	nome[i] = '\0';
	string += i;
	while(string[0] == ' ')
		string += 1;
	if(string[0] != '('){
		printf("Failure\n");
		return 0;
	}
	string += 1;
	char** atts;
	char** tipos;
	atts = (char**) calloc(10, sizeof(char*));
	tipos = (char**) calloc(10, sizeof(char*));
	int aux = 1;
	i = 0;
	while(string[i] != ')'){
		if(string[i] == ',' && string[i+1] == ')'){
			printf("Failure\n");
			return 0;
		}
		if(string[i] == ',') ++qtdeatts;
		++i;
	}
	for(i = 0; i < qtdeatts; ++i){
		atts[i] = (char*) calloc(30, sizeof(char));
		tipos[i] = (char*) calloc(30, sizeof(char));
	}
	i = 0;
	int b = 0, c = 0;
	a = 0;
	while(string[i] != ')'){
		do{
			if(string[i] == ' ') ++i;
			if(string[i] == ':'){
				++a;
				++i;
				c = 0;
			}
			if(a == 0 && string[i] != ','){
				atts[b][c] = string[i];
				++c;
			}
			else if(string[i] != ','){
				tipos[b][c] = string[i];
				++c;
			}
			++i;
			if(string[i] == ',') ++b;
		}while(string[i] != ',' && string[i] != ')');
		a = 0;
		c = 0;
	}
	criarTabela(db, nome, atts, tipos, qtdeatts);
	++T;
	printf("Success\n");
}
int Insert(Database* db, char* string){
	int t = strlen(string);
	while(string[t] != ';' && t > 11)
		--t;
	if(string[t] != ';'){
		bold(1);
		printf(" ERROR: invalid command line\n \";\" not founded\n");
		bold(0);
		return 0;
	}
	if(T == 0){	
		bold(1);
		printf("\tTable don't exists\n");
		bold(0);
		return 0;
	}
	string += 11;
	while(string[0] == ' ')
		string += 1;
	char nome[30];
	int i = 0, a = 0;
	while(string[i] != ' ' && string[i] != '('){
		if(string[i] == ';'){
			bold(1);
			printf(" ERROR: invalid command line\n");
			bold(0);
			return 0;
		}
		nome[i] = string[i];
		++i;
	}
	nome[i] = '\0';
	string += i;
	while(string[0] == ' ' || string[0] == '(')
		string += 1;
	for(i = 0; i < db->qtdeTabelas; ++i){
		if(strcmp(nome, db->tabelas[i]->nome) == 0){
			++a;
		}
	}
	if(a == 0){
		bold(1);
		printf(" ERROR: This table don't exists\n");
		bold(0);
	}
	char** atts = (char**) calloc(10, sizeof(char*));
	i = 0;
	int aux = 1;
	while(string[i] != ')'){
		if(string[i] == ',' && string[i+1] == ')'){
			printf("Failure\n");
			return 0;
		}
		if(string[i] == ',') ++aux;
		++i;
	}
	if(aux != qtdeatts){
		bold(1);
		printf(" ERROR: numbers of atributes different\n");
		bold(0);
		return 0;
	}
	for(i = 0; i < qtdeatts; ++i)
		atts[i] = (char*) calloc(30, sizeof(char));
	i = 0;
	int b = 0, c = 0;
	while(string[i] != ')'){
		do{
			if(string[i] == ' ') ++i;
			if(string[i] != ','){
				atts[b][c] = string[i];
				++c;
			}
			++i;
			if(string[i] == ',') ++b;
		}while(string[i] != ',' && string[i] != ')');
		c = 0;
	}
	for(i = 0; i < qtdeatts; ++i)
		printf("%s\n", atts[i]);
	inseretupla(db, nome, atts);
	++atts;
}
int Select(Database* db, char* string){
}
void help(){
	system("clear");
	printf("\n\n\n\n --- -- -- create database (\"Name of database\"): create a database\n");
	printf(" --- -- -- create table \"Name of table\" ");
	printf("(numbers of attributes, {\"Names of attributes\"}, {\"Types of attributes\"}): create a table\n");
	printf(" --- -- -- insert into \"Name of table\" (\"datas\"): Insert into the table especifics\n");
	printf(" --- -- -- select * from \"Name of table\" where \"Condition\" : show tuples that satisfy the condition\n");
	printf(" --- -- -- |-l| clear: clear screen\n");
	printf(" --- -- -- |-x| exit: exit of program\n");
	printf(" --- -- -- |-h| help: show this menu\n");
}




Database* verifica(char* string, Database* db){
	
	for(int i = 0; i < 11; ++i){
		string[i] = toupper(string[i]);
	}
	if(strcmp(string, "CLEAR") == 0 || strcmp(string, "-L") == 0)
        system("clear");
	else if(strcmp(string, "HELP") == 0 || strcmp(string, "-H") == 0 )
		help();
	else if(strncmp(string, "CREATE DATA", 11) == 0)
		db = createData(string);
	else if(strncmp(string, "CREATE TABL", 11) == 0)
		createTable(db, string);
	else if(strncmp(string, "INSERT INTO", 11) == 0)
		Insert(db, string);
	else if(strncmp(string, "SELECT * FR", 11) == 0)
		Select(db, string);
	else if(strcmp(string, "SHOW") == 0 || strcmp(string, "-S") == 0){
		if(A != 0)
			imprimirDatabase(db);
		else{
			bold(1);
			printf("\tDatabase don't exists\n");
			bold(0);
		}
	}
	else if(strcmp(string, "EXIT") != 0 && strcmp(string, "-X") != 0){
		bold(1);
        printf("    ERROR: invalid command line\n");
        bold(0);
	}
    return db;
}