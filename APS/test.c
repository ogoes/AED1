#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void M(){
    Database* db = criarDatabase("Universidade");
    /*char *A[] = {"ra", "nome", "nota"};
    char *B[] = {"interger", "string", "float"};
    criarTabela(db, "Alunos", A, B, 3);
    char *C[] = {"123", "GOrd", "9.5"};
    inseretupla(db, "Alunos", C);
    // imprimirDatabase(db);
   /* char *d[] = {"623", "Gord", "9.0"};
    inseretupla(db, "Alunos", d);*/
    // imprimirDatabase(db);


    /*char *F[] = {"rsa", "nomes", "notas"};
    char *G[] = {"interger", "string", "float"};

    criarTabela(db, "AUx", F, G, 3);
    char *Q[] = {"123", "GOrd", "9.0"};
    inseretupla(db, "AUx", Q);
    char *H[] = {"123", "GOrd", "8.5"};
    inseretupla(db, "AUx", H);
    char *J[] = {"123", "GOrd", "8.0"};
    inseretupla(db, "AUx", J);
    char *L[] = {"123", "GOrd", "7.5"};
    inseretupla(db, "AUx", L);
    char *T[] = {"123", "GOrd", "6.4"};
    inseretupla(db, "AUx", T);
*/
    imprimirDatabase(db);
}
int main(){
    // M();
    Database* db;
    char text[1000];
    int a;
    do{ 
        text[0] = '\0';
        printf("··· ");
        scanf("%[^\n]s", text);
        __fpurge(stdin);
        db = verifica(text, db);
    }while(strcmp(text, "EXIT") != 0 && strcmp(text, "-X") != 0);
    
    
    printf("\t\t\t\t\t\t\tby: \"");
    bold(1);
    printf("GOrd");
    bold(0);
    printf("\"\n");
}