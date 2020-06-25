#include <stdio.h>

// b) Elabore um programa que multiplique duas Matrizes M e N (10x10) fornecidas pelo
// usuário. O programa deve:
// - Ler as matrizes M e N.
// - Calcular a multiplicação e armazenar na matriz Mult.
// - Imprimir o resultado.

int main(void)
{
  // Declaração de váriaveis:
  int ai, aj, bi, bj;

  // Input matriz A:
  printf("Input da matriz A \n");
  printf("Digite o número de Linhas que a matriz A vai possuir: ");
  scanf("%d", &ai);
  printf("Digite o número de Colunas que a matriz A vai possuir: ");
  scanf("%d", &aj);

  int matrizA[ai][aj];

  // Montando a matriz A:
  for (int linhaAAux = 0; linhaAAux < ai; linhaAAux++)
  {
    for (int colunaAAux = 0; colunaAAux < aj; colunaAAux++)
    {
      printf("Digite o valor da celula %d e %d: ", linhaAAux, colunaAAux);
      scanf("%d", &matrizA[linhaAAux][colunaAAux]);
    }
  }

  // Input matriz B:
  printf("Input da matriz B\n");
  printf("Digite o número de Linhas que a matriz B vai possuir: ");
  scanf("%d", &bi);
  printf("Digite o número de Colunas que a matriz B vai possuir: ");
  scanf("%d", &bj);

  int matrizB[bi][bj];

  // zerar matriz de resultado
  int matrizMult[aj][bi];

  for (int linhaAAux = 0; linhaAAux < aj; linhaAAux++)
  {
    for (int colunaBAux = 0; colunaBAux < bi; colunaBAux++)
    {
      matrizMult[linhaAAux][colunaBAux] = 0;
    }
  }

  // Montando a matriz B:
  for (int linhaBAux = 0; linhaBAux < ai; linhaBAux++)
  {
    for (int colunaBAux = 0; colunaBAux < aj; colunaBAux++)
    {
      printf("Digite o valor da celula %d e %d:", linhaBAux, colunaBAux);
      scanf("%d", &matrizB[linhaBAux][colunaBAux]);
    }
  }
  // Print Matriz A
  printf("Matriz A \n");
  for (int linhaAAux = 0; linhaAAux < ai; linhaAAux++)
  {
    for (int colunaAAux = 0; colunaAAux < aj; colunaAAux++)
    {
      printf("%d", matrizA[linhaAAux][colunaAAux]);
    }
    printf("\n");
  }

  printf("\n");
  // Print Matriz B
  printf("Matriz B \n");
  for (int linhaAAux = 0; linhaAAux < bi; linhaAAux++)
  {
    for (int colunaAAux = 0; colunaAAux < bj; colunaAAux++)
    {
      printf("%d", matrizB[linhaAAux][colunaAAux]);
    }
    printf("\n");
  }

  // Calculando a matrizMult:
  if (ai == bj)
  {
    for (int linhaAAux = 0; linhaAAux < ai; linhaAAux++)
    {
      for (int colunaBAux = 0; colunaBAux < bj; colunaBAux++)
      {
        for (int colunaAAux = 0; colunaAAux < aj; colunaAAux++)
        {
          matrizMult[linhaAAux][colunaBAux] += matrizA[linhaAAux][colunaAAux] * matrizB[colunaAAux][colunaBAux];
        }
      }
    }
  }

  printf("\n");

  // Print matriz:
  printf("Matriz Multiplicação: \n");
  for (int linhaAAux = 0; linhaAAux < ai; linhaAAux++)
  {
    for (int colunaAAux = 0; colunaAAux < aj; colunaAAux++)
    {
      printf("%d ", matrizMult[linhaAAux][colunaAAux]);
    }
    printf("\n");
  }
  return 0;
}