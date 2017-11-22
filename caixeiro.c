#include <stdio.h>
#include <stdlib.h>
#include "caixeiro.h"
FILE *abreArq (char *nomeArq, int *vet, int **mat, int *tam)
{
	
	FILE *arq;
	arq = fopen(nomeArq, "r");
	if ( arq == NULL)
	{	
		printf("Nao foi possivel abrir arquivo\n");
		exit(1); // sai do console
	}
	fscanf( arq,"%d", tam);
	printf("A quantidade de cidade que sera visitada pelo Caixeiro Viajantes: %d\n",*tam );

	return arq;
}
void leituraArquivo( int **mat, int * ciclo,  int *tam, FILE *arq)
{
	int i, j;	
	for  ( i = 0; i < *tam;  i++)
	{
		fscanf( arq, "%d", &ciclo[i]);

	}
	
	for (i = 0; i < *tam; i++)
	{
		for( j = 0; j < *tam; j++)
		{
			fscanf(arq, "%d", &mat[i][j]);
			
		}
	}
	
		
}
FILE *fechaArq (FILE *arq)
{
	if ( arq  == NULL)
	{
		printf("Nao e possivel fechar arquivo pois nao esta aberto\n");
		exit(1);
	}	
	fclose (arq);
	return arq;
}

int **alocaMatriz( int *tam)
{
    
	int **mat, i;
	mat = (int**) malloc( *tam * sizeof(int*));
	if ( !mat)
	{
		printf("Nao e possivel alocar matriz\n");
		exit(1);
	}
	for( i = 0; i < *tam;  i++)
	{
		mat[i] = (int*)malloc(*tam * sizeof(int));
	}
	return mat;
}
int  *alocaVetor(int *tam)
{
   
	int *vet;
	vet = (int *) malloc ( *tam * sizeof(int));
	if ( !vet)
	{
		printf("Nao foi possivel alocar memoria.\n");
		exit(1);
	}
	return vet;
}

int calcCustoMin(int *ciclo, int **m, int *tam) 
{
	int custo = 0;
	int j;
        int Tam = *tam;
        printf("NANNANAN%d", Tam);
	
	for (j = 0; j < Tam-1; j++)
	{		
		custo += m[ciclo[j]][ciclo[j+1]];
	}	
	custo += m[ciclo[Tam-1]][ciclo[0]];
        return custo; // retorna o custo calculado 
}

int *troca (int *ciclo, int i, int j)
{
	int aux = ciclo[i];
	ciclo[i] = ciclo[j];
	ciclo[j] = aux;
	return ciclo;
}

void forcabruta (int *ciclo, int **mat, int *tam, int pos, int *custoMinimo)
 {
	
	int j; 	
 	printf("ehehhehe\n");
	
	if (pos == *tam-1)
	{
		int custo = calcCustoMin(ciclo, mat, tam);
		
		if (custo < *custoMinimo) 
		{
			*custoMinimo = custo;
			printf("%d\t",custo );
		}
	}
	else 
	{
		
		for (j = pos; j < *tam; j++)
		{
			ciclo = troca (ciclo, pos, j); // responsavel por fazer a troca dos vertices de cidades
			forcabruta (ciclo, mat, tam, pos+1, custoMinimo);// 
			ciclo = troca (ciclo, pos, j);
		}
	}
	return;
}
void menu(char *nomeArq)
{
    int opcao;
    do
    {
        printf("\t\t\nMenu do Calculo do menor caminha do caixeiro viajante\n");
        printf("0. Sair\n");
        printf("1. Calcular com 10 cidades\n");
        printf("2. Calcular com 11 cidades\n");
        printf("3. Calcular com 12 cidades\n");
        printf("4. Calcular com 13 cidades\n");
        printf("5. Calcular com 14 cidades\n");


        printf("Opcao: ");
        scanf("%d", &opcao);

        switch( opcao )
        {
            case 0:
                    system("cls || clear");
                    printf("Saindo do menu...\n");
                    break;
            case 1:
                    system("cls || clear");
                    printf(" Insira o nome do arquivo\n");
                    scanf( "  %s", nomeArq);
                    forcabruta (vet, mat, tam, 0, &custoMinimo);		
                    printf(" O menor custo entre as cidades e %d\n", custoMinimo);
                    break;
            case 2:
                   system("cls || clear");
                   printf(" Insira o nome do arquivo\n");
                   scanf( "  %s", nomeArq);
                   forcabruta (vet, mat, tam, 0, &custoMinimo);		
                   printf(" O menor custo entre as cidades e %d\n", custoMinimo);
                    break;
            case 3:
            case 4:
                    system("cls || clear");
                    printf(" Insira o nome do arquivo\n");
                    scanf( "  %s", nomeArq);
                    forcabruta (vet, mat, tam, 0, &custoMinimo);		
                    printf(" O menor custo entre as cidades e %d\n", *custoMinimo);
                    break;
            case 5 :
                   system("cls || clear");
                   printf(" Insira o nome do arquivo\n");
                   scanf( "  %s", nomeArq);
                   forcabruta (vet, mat, tam, 0, &custoMinimo);		
                   printf(" O menor custo entre as cidades e %d\n", *custoMinimo);
                   break;
             default:
                  system("cls || clear");
                   printf("Opcao invalida! Tente novamente.\n");
        }
        } while(opcao);

}
