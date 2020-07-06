#include <stdio.h>
#include <stdlib.h>

/*
  Modificar o programa de alocação dinâmica de matrizes dado
  anteriormente (slides 25 a 28) para que leia aloque dinamincamente
  duas matrizes de 3 por 4, leia seus elementos e imprima na matriz
  soma.
*/

int montaMatriz(float linhas, float colunas) 
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
  for(int i = 1; i <= linhas; i ++)
  {
    matriz[i] = (float *)malloc(sizeof(float) * colunas);
    if(matriz[i] == NULL)
    {
      printf("Memonira insuficiente!");
      return 0;
    }
  }

  // Populando a matriz:
  for (int i = 1; i <= linhas; i++)
  {
    for (int j = 1; j <= colunas; j++){
      printf("Insira um valor para a linha %d e coluna %d: \n", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  // Imprimindo a Matriz:
  for (int i = 1; i <= linhas; i++)
  {
    for (int j = 1; j <= colunas; j++){
      printf("%f ", matriz[i][j]);
    }
    printf("\n");
  }

  // Limpando memória:
  for (int i = 1; i <= linhas; i++){
    free(matriz[i]);
  }

  free(matriz);

  return 0;
}

int main() 
{
  montaMatriz(2,2);
}


