#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *vetor;
  int v[10];
  vetor = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++)
  {
    vetor[i] = i;
    printf("%d - ", vetor[i]);
  }
  printf("\n");

  for (int i = 10; i < 20; i++)
  {
    v[i - 10] = i;
    printf("%d -", v[i - 10]);
  }
  printf("\n");

  vetor = v; // Vetor aponta para o endereço de memoria de V. Nos NAO copiamos os valores de V para Vetor.
  for (int i = 0; i < 10; i++)
  {
    printf("%d - ", vetor[i]);
  }
  printf("\n");

  vetor[0] = 99;
  for (int i = 0; i < 10; i++)
  {
    printf("%d - ", v[i]);
  }
}