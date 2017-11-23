#include <stdio.h>
#include <stdlib.h>
#include "caixeiro.h"

FILE *abreArq (char *nomeArq, int *tam)
{
	
	FILE *arq;
	/*Tenta abrir o arquivo*/
	arq = fopen(nomeArq, "r");
	if ( arq == NULL)//falha em abrir
	{	
		printf("Nao foi possivel abrir arquivo\n");
		exit(1); // sai do console
	}
	//pega o valor da primeira posição e atribui a tam
	fscanf( arq,"%d", tam);
	printf("A quantidade de cidade que sera visitada pelo Caixeiro Viajantes: %d\n",*tam );
	//retorna o ponteiro file
	return arq;
}
void leituraArquivo( int **mat,  int tam, FILE *arq)
{
	int i, j;	

	for (i = 0; i < tam; i++)
	{
		for( j = 0; j < tam; j++)
		{	
			//Distribui as distanccias na matriz
			fscanf(arq, "%d", &mat[i][j]);
			if (mat[i][j] == -1)//cidades não estão conectadas
			{
				mat[i][j] = 100000;//Assim são desconsideradas
			}			
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

int **alocaMatriz(int tam)
{
    
	int **mat, i, j;
	mat = (int**) malloc( tam * sizeof(int*));
	if ( !mat)
	{
		printf("Nao e possivel alocar matriz\n");
		exit(1);
	}
	for( i = 0; i < tam;  i++)
	{
		mat[i] = (int*)malloc(tam * sizeof(int));
		if (!mat[i])
		{
			for (j = 0; j < i; j++)
			{
				free (mat[j]);
			}
			free(mat);
			printf("Nao e possivel alocar matriz\n");
			exit(1);
		}
	}
	return mat;
}
int  *alocaVetor(int tam)
{
   
	int *vet, i;
	vet = (int *) malloc ( tam * sizeof(int));
	if ( !vet)
	{
		printf("Nao foi possivel alocar memoria.\n");
		exit(1);
	}
	for (i = 0; i < tam; i++)
	{
		//Atribui as posições de cada cidade para permitir a permutação
		vet[i] = i;
	}
	return vet;
}

int calcCustoMin(int *ciclo, int **m, int tam) {
	int custo = 0;
	int j;
	
	for (j = 0; j < tam-1; j++)
	{		
		custo += m[ciclo[j]][ciclo[j+1]];
		 // calcula o custo de cada vertice
	}	
									 // porem o  ultimo custo nao eh calculado pelo pelo looping
	custo += m[ciclo[tam-1]][ciclo[0]]; // calcula o ultimo o custo do ultimo vertice
	
	return custo; // retorna o custo calculado 
}

int *troca (int *ciclo, int i, int j)
{
	int aux = ciclo[i];
	ciclo[i] = ciclo[j];
	ciclo[j] = aux;
	return ciclo;
}

void forcabruta (int *ciclo, int **mat, int tam, int pos, int *custoMinimo)
 {
	int custo = 0; // custo calculado para cada vertice do caminho
	int j; 	
	
	
	if (pos == tam-1)
	{
		custo = calcCustoMin(ciclo, mat, tam);
		
		if (custo < *custoMinimo) 
		{
			*custoMinimo = custo;
		}
	}
	else 
	{
		
		for (j = pos; j < tam; j++)
		{
			ciclo = troca (ciclo, pos, j); // responsavel por fazer a troca dos vertices de cidades (permutação)
		
			forcabruta (ciclo, mat, tam, pos+1, custoMinimo);// 
			ciclo = troca (ciclo, pos, j);
		}
	}
	return;
}



