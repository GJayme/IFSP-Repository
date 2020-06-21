#include <stdio.h>

int main()
{
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  if (num > 0)
  {
    printf("O número é positivo!");
  }
  else
  {
    if (num == 0)
    {
      printf("O número é igual a zero!");
    }
    else
    {
      printf("O número é negativo!");
    }
  }
}