#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

int main(){
    // M();
    Database* db;
    char text[1000];
    int i, a;
    do{ 
        i = 0, a = 0;
        text[0] = '\0';
        printf("»»» ");
        scanf("%[^\n]s", text);
        __fpurge(stdin);
        while(i <= strlen(text)){
            if(text[i] == '(' || text[i] == ')') ++a;
            ++i;
        }
        if(a == 2 || a == 0){
            db = verifica(text, db, a);
        }
        else{
            bold(1);
            printf(" ERROR: invalid command line\n");
            bold(0);
        }
    }while(strcmp(text, "EXIT") != 0 && strcmp(text, "-X") != 0);
    
    
    printf("\t\t\t\t\t\t\tby: \"");
    bold(1);
    printf("GOrd");
    bold(0);
    printf("\"\n");
}