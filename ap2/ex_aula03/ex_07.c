#include <stdio.h>
#include <string.h>

int main(void)
{
  // Declaraçao das variaveis
  int linha, aux;
  aux = 1;

  // Input dos valores
  printf("Digite o número de linhas desejadas: ");
  scanf("%d", &linha);

  // Dois whiles, primeiro vai contar as linhas e o mais interno vai contar os
  // prints em cada linha
  while (aux <= linha)
  {
    int travaLinha;
    travaLinha = 0;
    while (travaLinha < aux)
    {
      printf("*");
      travaLinha++;
    }
    printf("\n");
    aux++;
  }

  return 0;
}