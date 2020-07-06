#include <stdio.h>
#include <stdlib.h>

int main(void)
/*
  Escreva um programa em C que solicite ao usuário
  um número n e então lê um vetor de n notas e
  calcula a média aritmética.
  - Usar alocação dinâmica do vetor;
  - Liberar a memória ao final;
  - Não limitar o uso da memória.
*/
{
  int num = 0;

  // Pegando num
  printf("Digite um número: ");
  scanf("%d", &num);

  // Alocando memoria do vetor
  float *notas;
  notas = malloc(sizeof(float) * num);
  if (notas == NULL)
  {
    printf("Memoria insuficiente!");
    return (NULL);
  }

  // Inputando as notas
  for (int i = 0; i < num; i++)
  {
    printf("Digite a nota %d: ", i + 1);
    scanf("%f", &notas[i]);
  }

  // Calculando a média
  float soma = 0;
  float media = 0;
  for (int i = 0; i < num; i++)
  {
    soma += notas[i];
  }

  media = soma/num;

  free(notas);
  printf("A media da turma é %f\n", media);

  return 0;
}