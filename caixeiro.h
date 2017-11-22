FILE *abreArq (char *nomeArq, int *vet, int **mat, int *tam);

FILE *fechaArq (FILE *arq);

void forcabruta (int *ciclo, int **mat, int *tam, int pos, int *custoMinimo);

void permuta(int *vetor, int inf, int sup, int *custo);

int *troca(int *vetor, int i, int j);

int **alocaMatriz( int *tam);

int  *alocaVetor(int *tam);
 
void leituraArquivo( int **mat, int * ciclo,  int *tam, FILE *arq);

void menu(char *nomeAqr);