#include <stdio.h>
#include <stdlib.h>
#include "caixeiro.h"
 

int main()
{
//-----------------DECLARAÇÃO DE VARIAVEL----------------------
	char nomeArq[100] ;
	int **mat, *vet, *tam;
	int custo = 10000;
	FILE *arq;
//----------------ENTRADA DE DADOS PELO USUARIO-----------------
	printf("Informe o nome do arquivo\n");
	scanf(" %s", nomeArq);
//---------------CHAMADA DE FUNÇOES----------------------------
	vet = alocaVetor(tam);
	mat = alocaMatriz(tam);
	arq = abreArq (nomeArq,vet,mat, tam);

	
	int custoMinimo = 10000;
	
	forcaBruta (vet, mat, &tam, 0, &custoMinimo);
		
	printf(" O menor custo entre as cidades e %d\n", custoMinimo);

	
	return 0;
}
