#include "Enterprise.h"

void main(){
	Empresa *E = empresa_novo("GOES & CIA", 10);
	// Produto *P = produto_novo("TEST1", "testse", 12.2);
	cadastraProduto(E, "TEST2", "testess", 12.6);
	cadastraProduto(E, "TEST1", "testess", 12.6);
	cadastraProduto(E, "TEST5", "testess", 12.6);
	incluiEstoque(E, "TEST2", 4);
	incluiEstoque(E, "TEST1", 4);	
	empresa_imprimir(E);
	descadastraProduto(E, "TEST2");
	// removeEstoque(E, "TEST3", 1);
	empresa_imprimir(E);
	// produto_imprimir(E->estoque[/* posição */]);
}