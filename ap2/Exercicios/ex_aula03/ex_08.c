#include <stdio.h>

/*
8 - Chico tem 1,50 metro e cresce 2 centímetros por ano,
enquanto Zé tem 1,10 metro e cresce 3 centímetros por ano.
Construa um programa que calcule e imprima quantos anos
serão necessários para que Zé seja maior que Chico.
*/

int main(void)
{
  int altura1, altura2, cresc1, cresc2, anos;

  altura1 = 150;
  altura2 = 110;
  cresc1 = 2;
  cresc2 = 3;
  anos = 0;

  while (altura1 != altura2)
  {
    altura1 += 2;
    altura2 += 3;

    anos += 1;
  }
  anos += 1;

  printf("Irá demorar %d, anos.\n", anos);
}