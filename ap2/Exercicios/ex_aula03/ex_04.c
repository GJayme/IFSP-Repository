#include <stdio.h>
#include <math.h>

/*
4 - Aprimore o programa 3, para que ele imprima os 20 primeiros
números primos.
*/

int main(void)
{
  int cont, num, num1;
  cont = 0;
  num = 0;
  num = 1;

  printf("Digite um número para saber se os 20 próximos números são primos: ");
  scanf("%d", &num);

  while (cont <= 20)
  {
    num1 = num;
    if (isPrimo(num1) == 1)
    {
      cont++;
    }
    num++;
  }

  return 0;
}

isPrimo(int numTest)
{
  int div, a;

  div = 1;
  a = 0;

  a = numTest;
  for (numTest = numTest - 1; numTest > 1; numTest--)
  {
    if (a % numTest == 0)
    {
      div = 0;
      break;
    }
  }
  if (div != 0)
  {
    printf("O número %d é primo!\n", a);
    return 1;
  }
  else
  {
    return 0;
  }
}