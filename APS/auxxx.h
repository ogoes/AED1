typedef struct noDado{
    char* dado;
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


void bold(int status) {
 static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
 printf("%s", seq[status]);
}



void printDado(char* dado, char* tipo){
    // if(strcmp(tipo,"string")==0){
        printf("\t%s\t", dado);
    // } else if (strcmp(tipo,"integer")==0){
        // printf("%i\t", *(int*)dado);
    // } else if (strcmp(tipo,"float")==0){
        // printf("%.2f\t", *(float*)dado);
    // }
}
void imprimirTupla(NoDado* sentinelaTupla, NoAtributo* sentinelaAtributo){
    NoDado* auxDado = sentinelaTupla->dir;
    NoAtributo* auxAtributo = sentinelaAtributo->dir;
    while(auxAtributo != sentinelaAtributo){
        printDado(auxDado->dado, auxAtributo->tipo);
        auxDado = auxDado->dir;
        auxAtributo = auxAtributo->dir;
    }
    printf("\n");
}
void imprimirTabela(Tabela* table){
    printf("Tabela: %s\n", table->nome);
    //imprime o cabecalho da tabela
    NoAtributo* aux = table->atributos->dir;
    while(aux != table->atributos){
        bold(1);
        printf("\t%s\t", aux->nome);
        bold(0);
        aux = aux->dir;
    }
    //imprime os dados
    printf("\n");
    
    for (int i = 0; i < table->qtdeTuplas; i++){
        imprimirTupla(table->tuplas[i], table->atributos);        
    }
}
void imprimirDatabase(Database* db){
    printf("Database:");
    bold(1);
    printf(" %s\n", db->nome);
    bold(0);
    if(db->qtdeTabelas != 0){
        printf("TABELAS \n" );
        for (int i = 0; i < db->qtdeTabelas; i++){
            imprimirTabela(db->tabelas[i]);    
        }
    }
}