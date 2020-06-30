#include <stdio.h>
#include <stdlib.h>

// 1. Crie uma função que recebe como parâmetro um número X e
// retorna o endereço de um vetor de X inteiros.

int *retornaEndereco(num)
{
  int *vetor;

  vetor = malloc(sizeof(int) * num);

  if (vetor == NULL)
  {
    printf("O sistema operacional não conseguiu reservar a memória!");
  }
  else
  {
    return (int *)vetor;
  }
}

int main(void)
{
  int numero;
  scanf("%d", &numero);

  printf("O endereço do vetor com %d é de %p\n", numero, retornaEndereco(numero));

  return 0;
}
