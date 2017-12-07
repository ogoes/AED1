#include <ctype.h>
#include "database.h"

Database* createData( Database* db, char* string);
int createTable(Database* db, char* string);
int Select(Database* db, char* string);
int Insert(Database* db, char* string);
int A = 0, T = 0;
int qtdeatts[] = {1, 1, 1, 1, 1};
int QTDE = 0;

void ERROR(int a){
	bold(1);
	if(a == 0)
		printf(" ERROR: invalid command line\n \";\" not founded\n");
	else if(a == 1)
		printf(" ERROR: Database don't exists\n");
	else if(a == 2)
		printf(" ERROR: This table already exists\n");
	else if(a == 3)
		printf(" ERROR: invalid command line\n");
	else if(a == 4)
		printf(" ERROR: This table don't exists\n");
	else if(a == 5)
		printf(" ERROR: numbers of atributes different\n");
	else if(a == 6)
		printf(" ERROR: Database already exists\n");
	else if(a == 7)
		printf(" ERROR: Attribute don't exists\n");
	else if(a == 8)
		printf(" ERROR: Attribute incompatible\n");
	bold(0);
}

int compara(char *dado, char* tipo, char op, char* value){
	if(strcmp(tipo, "string") == 0){
		if(strcmp(dado, value) == 0)
			return 1;
		else
			return 0;
	}
	else if(strcmp(tipo, "float") == 0){
		float DD;
		float VV;
		DD = atof(dado);
		VV = atof(value);
		if(op == '='){
			if(VV == DD)
				return 1;
			else
				return 0;
		}
		else if(op == '>'){
			if(DD > VV)
				return 1;
			else
				return 0;
		}
		else if(op == '<'){
			if(DD < VV)
				return 1;
			else
				return 0;
		}
	}
	else if(strcmp(tipo, "integer") == 0){
		int DD;
		int VV;
		DD = atoi(dado);
		VV = atoi(value);
		if(op == '='){
			if(VV == DD)
				return 1;
			else
				return 0;
		}
		else if(op == '>'){
			if(DD > VV){
				return 1;
			}
			else
				return 0;
		}
		else if(op == '<'){
			if(DD < VV){
				return 1;
			}
			else
				return 0;
		}
	}
}
Database* createData(Database* db, char* string){
	int t = strlen(string);
	if(A == 0){
		string += 11;
		while(string[t] != ';' && t > 5)
			--t;
		if(string[t] != ';'){
			ERROR(0);
			return NULL;
		}
		for(int i = 0; i < 5; ++i){
			string[i] = toupper(string[i]);
		}
		if(strncmp(string, "BASE ", 5) != 0){
			ERROR(3);
			return 0;
		}
		string += 5;
		while(string[0] == ' ')
			string += 1;
		char nome[30];
		int i = 0;
		if(string[0] == '"') string += 1;
		while(string[i] != ' ' && string[i] != ';' && string[i] != '"'){
			nome[i] = string[i];
			++i;
		}
		nome[i] = '\0';
		db = criarDatabase(nome);
		if(db) ++A;
	}
	else 
		ERROR(6);
	return db;
}
int createTable(Database* db, char* string){
	if(A == 0){
		ERROR(1);
		return 0;
	}
	int t = strlen(string);
	while(string[t] != ';' && t > 16)
		--t;
	if(string[t] != ';'){
		ERROR(0);
		return 0;
	}
	int a = 0, i = 0;
	string += 13;
	
	char nome[30];
	i = 0;
	while(string[i] != ' ' && string[i] != '('){
		if(string[i] == ';'){
			ERROR(3);
			return 0;
		}
		nome[i] = string[i];
		++i;
	}
	nome[i] = '\0';
	string += i;
	for(i = 0; i < db->qtdeTabelas; ++i){
		if(strcmp(nome, db->tabelas[i]->nome) == 0){
			ERROR(2);
			return 0;
		}
	}
	while(string[0] == ' ')
		string += 1;
	if(string[0] != '('){
		ERROR(3);
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
		if(string[i] == ',')
			++qtdeatts[QTDE];
		++i;
	}
	for(i = 0; i < qtdeatts[QTDE]; ++i){
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
	for(i = 0; i < qtdeatts[QTDE]; ++i){
		a = strlen(atts[i]);
		atts[i][a] = '\0';
	}
	criarTabela(db, nome, atts, tipos, qtdeatts[QTDE]);
	++T, ++QTDE;
}
int Insert(Database* db, char* string){
	int t = strlen(string);
	while(string[t] != ';' && t > 11)
		--t;
	if(string[t] != ';'){
		ERROR(0);
		return 0;
	}
	if(T == 0){	
		ERROR(4);
		return 0;
	}
	string += 11;
	while(string[0] == ' ')
		string += 1;
	char nome[30];
	int i = 0, a = 0;
	while(string[i] != ' ' && string[i] != '('){
		if(string[i] == ';'){
			ERROR(3);
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
		ERROR(4);
		return 0;
	}
	char** atts = (char**) calloc(10, sizeof(char*));
	i = 0;
	int aux = 1, q = 0;
	while(string[i] != ')'){
		if(string[i] == ',' && string[i+1] == ')'){
			printf("Failure\n");
			return 0;
		}
		if(string[i] == ',') ++aux;
		++i;
	}
	int kk;
	for(i = 0; i < db->qtdeTabelas; ++i){
		if(strcmp(nome, db->tabelas[i]->nome) == 0){
			kk = i;
			i = db->qtdeTabelas;
		}
	}
	if(aux != qtdeatts[kk]){
		ERROR(5);
		return 0;
	}

	for(i = 0; i < aux; ++i)
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
	inseretupla(db, nome, atts);
	++atts;
}
int Select(Database* db, char* string){
	if(A == 0){
		ERROR(1);
		return 0;
	}
	int t = strlen(string);
	while(string[t] != ';' && t > 19)
		--t;
	if(string[t] != ';'){
		ERROR(0);
		return 0;
	}
	int a = 0, i = 0;
	string += 14;
	while(string[0] == ' ')
		string += 1;
	i = 0;
	char Table[30];
	while(string[i] != ' ' && string[i] != ';'){
		Table[i] = string[i];
		++i;
	}
	Table[i] = '\0';
	string += i;
	a = 0;
	if(A != 0 && T != 0){	
		for(i = 0; i < db->qtdeTabelas; ++i){
			if(strcmp(Table, db->tabelas[i]->nome) == 0){
				++a;
			}
		}
	}
	else{
		ERROR(1);
		ERROR(4);
		return 0;
	}
	if(a == 0){
		ERROR(4);
		return 0;
	}
	while(string[0] == ' ')
		string += 1;
	string += 5;
	while(string[0] == ' ')
		string += 1;
	if(string[0] == ';'){
		imprimirDatabase(db);
		return 0;
	}
	char ATTS[30];
	i = 0;
	while(string[i] != ' ' && string[i] != ';'){
		ATTS[i] = string[i];
		++i;
	}
	ATTS[i] = '\0';
	string += i;

	NoAtributo* AT;
	NoAtributo* ATTTT;
	char TYPE[30];
	int acc = 0;
	Tabela* TA;
	for(int p = 0; p < db->qtdeTabelas; ++p){
		if(strcmp(db->tabelas[p]->nome, Table) == 0){
			TA = db->tabelas[p];
			AT = TA->atributos->dir;
			while(AT != TA->atributos){
				if(strcmp(ATTS, AT->nome) == 0){
					ATTTT = AT;
					strcpy(TYPE, AT->tipo);
					++acc;
				}
				AT = AT->dir;
			}
		}
	}
	if(acc == 0){
		ERROR(7);
		return 0;
	}
	while(string[0] == ' ')
		string += 1;
	char OP;
	OP = string[0];
	string += 1;
	while(string[0] == ' ')
		string += 1;
	if(OP != '=' && strcmp(TYPE, "string") == 0){
		ERROR(8);
		return 0;
	}
	char VALUE[30];
	i = 0;
	while(string[i] != ' ' && string[i] != ';'){
		VALUE[i] = string[i];
		++i;
	}
	VALUE[i] = '\0';
	string += i;

	int tuu;
	AT = TA->atributos->dir;
	NoDado* DATA = ATTTT->valores->baixo;
    printf("Tabela: %s\n", TA->nome);
    while(AT != TA->atributos){
    	bold(1);
    	printf("\t%s\t", AT->nome);
    	bold(0);
    	AT = AT->dir;
    }
    printf("\n");
	for(i = 0; i < TA->qtdeTuplas; ++i){
		tuu = compara(DATA->dado, TYPE, OP, VALUE); 
		if(tuu == 1){
	        imprimirTupla(TA->tuplas[i], AT);
		}
		DATA = DATA->baixo;
	}
}
void help(){
	// system("clear");
	printf("\n\n\n\n\n\n\n\n >>>> create database \"Name of database\";\n");
	printf(" >>>> create table \"Name of table\" (Atribute1:Type1, ... , AtributeN:TypeN);\n");
	printf(" >>>> insert into \"Name of table\" (Data1, ... , DataN);\n");
	printf(" >>>> select * from \"Name of table\" where \"Condition\";\n");
	printf(" >>>> |-l| clear; clear screen\n");
	printf(" >>>> |-x| exit; exit of program\n");
	printf(" >>>> |-h| help; show this menu\n\n\n\n\n\n\n\n");
}
Database* verifica(char* string, Database* db, int a){
	
	for(int i = 0; i < 11; ++i){
		string[i] = toupper(string[i]);
	}
	if((strcmp(string, "CLEAR") == 0 || strcmp(string, "-L") == 0) && a == 0)
        system("clear");
	else if((strcmp(string, "HELP") == 0 || strcmp(string, "-H") == 0 ) && a == 0)
		help();
	else if(strncmp(string, "CREATE DATA", 11) == 0 && a == 0)
		db = createData(db, string);
	else if(strncmp(string, "CREATE TABL", 11) == 0 && a == 2)
		createTable(db, string);
	else if(strncmp(string, "INSERT INTO", 11) == 0 && a == 2)
		Insert(db, string);
	else if(strncmp(string, "SELECT * FR", 11) == 0 && a == 0)
		Select(db, string);
	else if((strcmp(string, "SHOW") == 0 || strcmp(string, "-S") == 0) && a == 0){
		if(A != 0)
			imprimirDatabase(db);
		else{
			ERROR(1);
		}
	}
	else if(strcmp(string, "EXIT") != 0 && strcmp(string, "-X") != 0 && a == 0){
		ERROR(3);
	}
    return db;  
}