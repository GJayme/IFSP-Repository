#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // 2. Crie uma funcão que recebe como parâmetro um vetor de inteiros,
  // faz uma cópia em uma nova área de memória e retorna o endereço
  // da cópia.

  int vetor1[10];
  int *vetor2;

  vetor2 = malloc(sizeof(vetor1[10]));

  for (int i = 0; i <= 10; i++)
  {
    vetor2[i] = vetor1[i];
  }
  int endereco1 = malloc(sizeof(vetor1));
  int endereco2 = malloc(sizeof(vetor2));

  printf("%d", endereco1);
  printf("%d", endereco2);

  free(vetor2);

  return 0;
}
