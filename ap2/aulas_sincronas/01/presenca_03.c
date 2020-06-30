#include <stdio.h>
#include <stdlib.h>

// 3. Crie uma função que recebe o endereço de dois inteiros (X e Y) e
// troca eles de lugar, ou seja, X passa a ter o valor de Y e Y passa a
// ter o valor de X.

int trocaDeLugar(num1, num2)
{
  int *ponteiro1;
  int *ponteiro2;

  ponteiro1 = malloc(sizeof(num1));
  ponteiro2 = malloc(sizeof(num2));

  *ponteiro1 = num1;
  *ponteiro2 = num2;

  printf("O enderço %p tem valor de: %d\n", ponteiro1, *ponteiro1);
  printf("O enderço %p tem valor de: %d\n", ponteiro2, *ponteiro2);

  ponteiro1 = &num2;
  ponteiro2 = &num1;

  printf("Trocando o valor: endereço %p valor %d\n", ponteiro1, *ponteiro1);
  printf("Trocando o valor: endereço %p valor %d\n", ponteiro2, *ponteiro2);

  return 0;
}

int main()
{
  int num1;
  int num2;

  printf("Digite um número:\n");
  scanf("%d", &num1);

  printf("Digite um número:\n");
  scanf("%d", &num2);

  trocaDeLugar(num1, num2);

  return 0;
}