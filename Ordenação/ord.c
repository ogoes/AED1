#include <stdio.h>
#include <stdlib.h>
#include "ord.h"


int main(){
    
    int v1[] = {25,48,37,12,57,86,33,92};
    Imprime(v1, 8);
    // Bubble(v1, 8);
    // Selection(v1, 8);
    // Insertion(v1, 8);
    Heap(v1, 8);
    Imprime(v1, 8);

    return 0;
}