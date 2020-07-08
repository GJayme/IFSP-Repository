#include <stdio.h>
#include <stdlib.h>

/*
  Modificar o programa de alocação dinâmica de matrizes dado
  anteriormente (slides 25 a 28) para que leia aloque dinamincamente
  duas matrizes de 3 por 4, leia seus elementos e imprima na matriz
  soma.
*/

float **montaMatriz(float linhas, float colunas) 
{
  float **matriz;

  // Verificando validade das linhas e colunas:
  if(linhas < 0 || colunas < 0) 
  {
    printf("Número de linhas e colunas inválidas!");
    return 0;
  }

  // Alocando memoria para as Linhas:
  matriz = malloc(sizeof(float *) * linhas);
  if (matriz == NULL)
  {
    printf("Memória insuficiente!");
    return 0;
  }

  // Alocando memoria para as colunas:
  for(int i = 0; i < linhas; i ++)
  {
    matriz[i] = (float *)malloc(sizeof(float) * colunas);
    if(matriz[i] == NULL)
    {
      printf("Memonira insuficiente!");
      return 0;
    }
  }

  // Populando a matriz:
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++){
      printf("Insira um valor para a linha %d e coluna %d: \n", i+1, j+1);
      scanf("%f", &matriz[i][j]);
    }
  }

  // Imprimindo a Matriz:
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++){
      printf("%f ", matriz[i][j]);
    }
    printf("\n");
  }

  return matriz;
}

// Limpando memória:
int **limpaMatriz(float **matriz, int linha)
{
  for (int i = 0; i < linha; i++){
    free(matriz[i]);
  }

  free(matriz);

  return 0;
}

int main() 
{
  float **matriz1 = montaMatriz(3,4);
  float **matriz2 = montaMatriz(3,4);
  
  float **matrizSoma;

  matrizSoma = malloc(sizeof(float *) * 3);
  if (matrizSoma == NULL)
  {
    printf("Memória insuficiente!");
    return 0;
  }

  for(int i = 0; i < 3; i++)
  {
    matrizSoma[i] = (float *)malloc(sizeof(float) * 4);
    if(matrizSoma[i] == NULL)
    {
      printf("Memoria insuficiente!");
      return 0;
    }
  }

  printf("\n");

  for (int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j];
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      printf("%f ", matrizSoma[i][j]);
    }
    printf("\n");
  }

  limpaMatriz(matriz1, 3);
  limpaMatriz(matriz2, 3);
  limpaMatriz(matrizSoma, 3);

  return 0;
}