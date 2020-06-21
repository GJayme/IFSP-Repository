#include <stdio.h>
#include <math.h>

int main(void)
{
  int num, quadrado, cubo, raiz;

  printf("Digite um número: ");
  scanf("%d", &num);

  for (num; num >= 0; num--)
  {
    quadrado = pow(num, 2);
    cubo = pow(num, 3);
    raiz = sqrt(num);

    printf("Número ao quadrado: %d\n", quadrado);
    printf("Número ao cubo: %d\n", cubo);
    printf("Número ao raiz: %d\n", raiz);
    printf(" \n");
  }

  return 0;
}
