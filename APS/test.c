#include <stdio.h>

int main(){
	float A, B, C;
	printf("informe o primeiro lado do triângulo: ");
	scanf("%f", &A);
	printf("informe o segundo lado do triângulo: ");
	scanf("%f", &B);
	printf("informe o terceiro lado do triângulo: ");
	scanf("%f", &C);

	if(A > (B+C)){
		printf(" Não formam um triângulo\n");
		return 0;
	}
	else if(B > (A+C)){
		printf(" Não formam um triângulo\n");
		return 0;
	}
	else if(C > (A+B)){
		printf(" Não formam um triângulo\n");
		return 0;
	}
	else{
		printf("Formam um triângulo!!!\n");
	}
	return 0;
}