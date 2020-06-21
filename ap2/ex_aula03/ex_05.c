#include <stdio.h>
#include <math.h>

int main(void)
{
  int num, numInicial, numFinal;
  long int resultado;

  numInicial = 92;
  numFinal = 1478;
  resultado = 1;

  for (num = numInicial; num <= numFinal; num++)
  {
    if (isPrimo(num) == 1)
    {
      resultado = resultado * num;
    }
  }
  printf("%li\n", resultado);
}

int isPrimo(int numTest)
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
    // printf("O número %d é primo!\n", a);
    return 1;
  }
  else
  {
    return 0;
  }
}