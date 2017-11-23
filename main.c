#include <stdio.h>
#include <stdlib.h>
#include "caixeiro.h"
#include <string.h>
 

int main()
{
//-----------------DECLARAÇÃO DE VARIAVEL----------------------
	char nomeArq[124];
	int **mat , *vet , tam, op;
	FILE *arq;
	int custoMinimo = 19999;
//----------------ENTRADA DE DADOS PELO USUARIO-----------------
	/**/
	//strcpy(nomeArq, "arq10.txt");
//---------------CHAMADA DE FUNÇOES----------------------------

	do {

		printf("********************\n");
		printf("*  MENU PRINCIPAL  *\n");
		printf("********************\n");
		printf("* 1 - Abrir arquivo*\n");
		printf("* 2 - sair         *\n");
		printf("********************\n");
		scanf (" %d", &op);
		switch (op){
			case 1:
				printf("Informe o nome do arquivo\n");
				scanf(" %s", nomeArq);

				arq = abreArq (nomeArq, &tam);
				vet = alocaVetor(tam);

				mat = alocaMatriz(tam);
				
				
				leituraArquivo(mat, tam, arq);

				forcabruta (vet, mat, tam, 0, &custoMinimo);
					
				printf(" O menor custo entre as cidades e %d\n", custoMinimo);
				break;
			case 2:
				printf ("Encerrando programa\n");
				break;
			default:
				printf("Entre com a opção correta\n");
				break;
		}
	}while (op != 2);
	return 0;
}
