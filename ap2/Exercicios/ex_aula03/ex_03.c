#include <stdio.h>
#include <math.h>

/*
3 - Escreva um programa que leia um número inteiro e indique se
o mesmo é primo ou não.
*/

int main(void)
{
  int num;
  num = 0;

  printf("Digite um número para saber se ele é primo: ");
  scanf("%d", &num);

  isPrimo(num);
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
  }

  else
  {
    printf("O número %d não é primo!\n", a);
  }

  return isPrimo;
}