#include <stdio.h>

// a) Uma matriz M pode ser transposta em uma matriz N onde o número de
// linhas/colunas da primeira passa a ser o número de colunas/linhas da segunda.
// Faça um programa que:
// - Leia uma matriz M (o usuário deve fornecer a quantidade de linhas e a
// quantidade de colunas que não deverão exceder 50 linhas e 50 colunas).
// - Calcule a transposta N da matriz M.
// - Imprima a transposta calculada.

int main(void)
{
  // Declaraçao de variáveis
  int matriz[50][50];
  int matrizTransp[50][50];
  int i, j;

  //  Input matriz
  printf("Digite o número de linhas da matriz M: ");
  scanf("%d", &i);
  printf("Digite o número de colunas da matriz M: ");
  scanf("%d", &j);

  for (int linha = 0; linha < i; linha++)
  {
    for (int coluna = 0; coluna < j; coluna++)
    {
      printf("Digite o valor da celula %d e %d: ", linha, coluna);
      scanf("%d", &matriz[linha][coluna]);
    }
  }

  printf("\n");

  // Print matriz
  for (int linha = 0; linha < i; linha++)
  {
    for (int coluna = 0; coluna < j; coluna++)
    {
      printf("%d ", matriz[linha][coluna]);
    }
    printf("\n");
  }

  printf("\n");

  // Print matriz transp
  for (int linha = 0; linha < j; linha++)
  {
    for (int coluna = 0; coluna < i; coluna++)
    {
      printf("%d ", matriz[coluna][linha]);
    }
    printf("\n");
  }

  return 0;
}
