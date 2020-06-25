#include <stdio.h>
#include <stdlib.h>

int main(void)
// 1. Crie uma função que recebe como parâmetro um número X e
// retorna o endereço de um vetor de X inteiros.
{
  int i = 5;
  int *vetor;
  vetor = malloc(sizeof(int) * i);

  for (int j = 0; j < i; j++)
  {
    vetor[j] = j;
    printf("%d - ", vetor[j]);
  }

  printf("%d", malloc(sizeof(vetor)));

  free(vetor);

  return 0;
}
