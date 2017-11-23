
/*recebe o nome do arquivo e retorna um ponteiro do arquivo
Atribui o valor da primeira linha na variavel tam*/
FILE *abreArq (char *nomeArq, int *tam);

/*fecha o arquivo*/
FILE *fechaArq (FILE *arq);

/*Faz todas as permutações entre as cidades e calcula o custi minimo*/
void forcabruta (int *ciclo, int **mat, int tam, int pos, int *custoMinimo);

//recebe uma permutação e calcula o menor distancia entre as cidades
int calcCustoMin(int *ciclo, int **m, int tam);

//troca dois elementos do vetor (gera uma permução)
int *troca(int *vetor, int i, int j);

//Aloca a matriz de distancias
int **alocaMatriz( int tam);

//aloca um vetor (ciclo) atribui posições para as cidades
int  *alocaVetor(int tam);

//recebe um ponteiro do arquivo que contem as distancias entre as cidades e atribui as distancias para as posições da matriz (mat) de distancias
void leituraArquivo( int **mat,  int tam, FILE *arq);
