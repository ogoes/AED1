#include <stdio.h>
#include <stdlib.h>
#include "ord.h"


void main(){
	int V[] = {10, 8, 5, 2, 9, 7, 2, 4, 1, 6};
	int a;
	Insertion(V, 10);
	for(int i = -10; i < 20; ++i){
		a = BuscaBin(V, 10, i);
		printf("i%i a%i\n", i, a);
	}
	Imprime(V, 10);
}
