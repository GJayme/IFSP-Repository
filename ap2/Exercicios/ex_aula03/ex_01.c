#include <stdio.h>
#include <math.h>

/* 1 - Escrever um programa que lê um conjunto de valores,
imprimindo, para cada valor: seu quadrado, seu cubo e sua raiz
quadrada. O conjunto é finalizado com o valor zero.
*/

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
