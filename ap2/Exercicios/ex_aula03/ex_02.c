#include <stdio.h>
#include <math.h>

/*
2- Escreva um programa que leia um número inteiro positivo e
mostre o seu fatorial.
*/

int main(void)
{
  int num, fatorial;

  printf("Digite um número para calcular seu fatorial: ");
  scanf("%d", &num);

  for (fatorial = 1; num > 1; num--)
  {
    fatorial = fatorial * num;
  }

  printf("%d", fatorial);

  return 0;
}