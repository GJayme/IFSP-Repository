#include <stdio.h>

// 1- Elabore um programa para ler o nome e o sobrenome
// de dez pessoas, imprimindo-os no seguinte formato:
// sobrenome, nome.

int main(void)
{
  char nome[50];
  char sobrenome[50];
  int numMax, numInicio;
  numMax = 10;
  numInicio = 0;

  while (numInicio < numMax)
  {
    printf("Digite o nome: ");
    gets(nome);

    printf("Digite seu sobrenome: ");
    gets(sobrenome);

    printf("Olá %s, %s\n", sobrenome, nome);
    numInicio++;
  }
}