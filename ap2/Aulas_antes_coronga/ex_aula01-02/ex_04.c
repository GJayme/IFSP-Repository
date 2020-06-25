#include <stdio.h>

int main()
{
  int num, result;

  printf("Digite um número para saber se é par ou impar: ");
  scanf("%d", &num);

  result = num % 2;

  if (num != 0)
  {
    if (result == 1 || result == -1)
    {
      printf("O número é impar, pois o resto da divisar / 2 é = a %d.", result);
    }
    else
    {
      printf("O número é par, pois o resto da divisar / 2 é = a %d.", result);
    }
  }
  else
  {
    printf("O número digitado foi zero!");
  }
}
