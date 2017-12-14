#include "auxxx.h"



Database* criarDatabase(char* nome);
void criarTabela(Database* db, char* nome, char *atributos[], char *tipos[], int qtdeAtributos);
void criaAtributos(NoAtributo* AA, char *nome, char *tipo);
void criarTuplas(NoDado* TT, char* dado);
void aumentaTU(Tabela* TA);

void criarTuplas(NoDado* TT, char* dado){
    NoDado* NO = (NoDado*)calloc(1, sizeof(NoDado));
    NO->dado = dado;

    NO->esq = TT;
    NO->dir = TT->dir;
    TT->dir->esq = NO;
    TT->dir = NO;
}
void UneTV(NoDado* Valor, NoDado* Tupla){
    Tupla->cima = Valor;
    Tupla->baixo = Valor->baixo;
    Valor->baixo->cima = Tupla;
    Valor->baixo = Tupla;
}
void criaAtributos(NoAtributo* AA, char *nome, char *tipo){

    NoAtributo* no = (NoAtributo*)calloc(1, sizeof(NoAtributo));
    strcpy(no->nome, nome);
    strcpy(no->tipo, tipo);
    

    NoDado* BB = (NoDado*) calloc(1, sizeof(NoDado));
    BB->dir = NULL;
    BB->esq = NULL;
    BB->cima = BB;
    BB->baixo = BB;


    no->valores = BB; 


    no->esq = AA;
    no->dir = AA->dir;
    AA->dir->esq = no;
    AA->dir = no;
}
void criarTabela(Database* db, char* nome, char *atributos[], char *tipos[], int qtdeAtributos){
    Tabela* AUX = (Tabela*) calloc(1, sizeof(Tabela));
    strcpy(AUX->nome, nome);
    AUX->atributos = (NoAtributo*) calloc(1, sizeof(NoAtributo));
    AUX->atributos->dir = AUX->atributos;
    AUX->atributos->esq = AUX->atributos;


    NoAtributo* no = AUX->atributos;
    for(int i = 0; i < qtdeAtributos; ++i){
        criaAtributos(no, atributos[i], tipos[i]);
        no = no->dir;
    }
    AUX->tamTuplas = 5;
    AUX->qtdeTuplas = 0;
    AUX->tuplas = (NoDado**) calloc(5, sizeof(NoDado*));
    for(int i = 0; i < AUX->tamTuplas; ++i){
        AUX->tuplas[i] = NULL;
    }

    db->tabelas[db->qtdeTabelas] = AUX;
    ++db->qtdeTabelas;
}
Database* criarDatabase(char* nome){
    Database* db = (Database* ) calloc(1, sizeof(Database));
    if(!db) return NULL;
    strcpy(db->nome, nome);
    db->tabelas = (Tabela**)calloc(5, sizeof(Tabela*));
    if(!db->tabelas) return NULL;
    for(int i = 0; i < 5; ++i){
        db->tabelas[i] = NULL;
    }
    db->tamTabelas = 5;
    db->qtdeTabelas = 0;

    return db;
}
void inseretupla(Database* db, char* NomeTabela, char *dados[]){
    Tabela* TA;
    for(int i = 0; i < db->qtdeTabelas; ++i){
        if(strcmp(NomeTabela, (db->tabelas[i])->nome) == 0)
            TA = db->tabelas[i];
    }
    if(TA->tamTuplas == TA->qtdeTuplas)
        aumentaTU(TA);
    NoDado* TU = (NoDado*)calloc(1, sizeof(NoDado));
    TU->cima = NULL;
    TU->baixo = NULL;
    TU->dir = TU;
    TU->esq = TU;
    TA->tuplas[TA->qtdeTuplas] = TU;
    NoAtributo* NOA = TA->atributos->dir;
    TU = TU->dir;
    int i = 0;
    while(NOA != TA->atributos){
        criarTuplas(TU, dados[i]);
        UneTV(NOA->valores->cima, TU);
        TU = TU->dir;
        NOA = NOA->dir;
        ++i;
    }
    ++TA->qtdeTuplas;
}
void aumentaTU(Tabela* TA){
    NoDado** novo = (NoDado**)calloc(TA->tamTuplas*2, sizeof(NoDado*));
    for(int i = 0; i < TA->qtdeTuplas; ++i){
        novo[i] = TA->tuplas[i];
    }
    free(TA->tuplas);
    TA->tamTuplas *= 2;
    TA->tuplas = novo;
}