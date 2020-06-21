#include <stdio.h>

int main()
{
  int num;

  printf("Digite um número de 1 a 7 para verificar se dia útil ou não: ");
  scanf("%d", &num);

  if (num == 1 || num == 7)
  {
    printf("Dia %d é domingo, portando final de semana.", num);
  }
  else if (num == 2)
  {
    printf("Dia %d é segunda-feira, portando dia útil.", num);
  }
  else if (num == 3)
  {
    printf("Dia %d é terça-feira, portando dia útil.", num);
  }
  else if (num == 4)
  {
    printf("Dia %d é quarta-feira, portando dia útil.", num);
  }
  else if (num == 5)
  {
    printf("Dia %d é quinta-feira, portando dia útil.", num);
  }
  else if (num == 6)
  {
    printf("Dia %d é sabado, portando final de semana.", num);
  }
}