#include <stdio.h>
#include <math.h>

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