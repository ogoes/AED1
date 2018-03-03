#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct noDado{
    void* dado;
    int tamDado;
    struct noDado* dir;
    struct noDado* esq;
    struct noDado* cima;
    struct noDado* baixo;
} NoDado;

typedef struct noAtributo{
    char nome[30];
    char tipo[30];
    NoDado* valores;
    struct noAtributo* dir;
    struct noAtributo* esq;
} NoAtributo;

typedef struct {
    char nome[30];
    NoAtributo* atributos;
    NoDado** tuplas;
    unsigned short int tamTuplas;
    unsigned short int qtdeTuplas;
} Tabela;

typedef struct {
    char nome[30];
    Tabela** tabelas;
    unsigned short int tamTabelas;
    unsigned short int qtdeTabelas;
} Database;


// PROTOTIPOS EXEMPLO
Database* criarDatabase(char* nome);
void criarTabela(Database* db, char* nome, char* atributos, char* tipos, int qtdeAtributos);




void criarTabela(Database* db, char* nome, char* atributos, char* tipos, int qtdeAtributos){
    Tabela* TAB = (Tabela*)calloc(1, sizeof(Tabela));
    strcpy(TAB->nome, nome);


    db->tabelas[db->qtdeTabelas] = TAB;
    TAB = NULL;

}


Database* criarDatabase(char* nome){
    Database* db = (Database*)calloc(1, sizeof(Database));
    strcpy(db->nome, nome);
    db->tabelas = (Tabela**)calloc(5, sizeof(Tabela*));
    for(int i = 0; i < 5; ++i){
        db->tabelas[i] = NULL;
    }
    db->tamTabelas = 5;
    db->qtdeTabelas = 0;

    return db;
}


// FUNCOES AUXILIARES
void printDado(void* dado, char* tipo){
    if(strcmp(tipo,"string")==0){
        printf("%s\t", *(char*)dado);
    } else if (strcmp(tipo,"integer")==0){
        printf("%d\t", *(int*)dado);
    } else if (strcmp(tipo,"float")==0){
        printf("%.2f\t", *(float*)dado);
    }
}

void imprimirTupla(NoDado* tupla, NoAtributo* atributo){
    
    while(tupla != null){
        printDado(tupla->dado, atributo->tipo);
        tupla = tupla->dir;
        atributo = atributo->dir;
    }
}

void imprimirTabela(Tabela* table){
    printf("Tabela: %s\n", table->nome);
    //imprime o cabecalho da tabela
    NoAtributo* aux = table->atributos;
    while(aux != null){
        printf("%s\t", aux->nome);
        aux = aux->dir;
    }
    //imprime os dados
    int i;
    aux = table->atributos;
    for (int i = 0; i < table->qtdeTuplas; i++){
        imprimirTupla(table->tuplas[i], aux);
        aux = aux->dir;
    }
}

void imprimirDatabase(Database* db){
    printf("Database: %s\n", db->nome);
    printf("TABELAS \n", );
    int i;
    for (int i = 0; i < db->qtdeTabelas; i++){
        imprimirTabela(db->tabelas[i]);    
    }

}





int main(){
    
    Database* db = criarDatabase("Universidade");
    criarTabela(db, "Alunos", {"ra", "nome", "nota"}, {"integer", "string", "float"}, 3);
    imprimirDatabase(db);


}