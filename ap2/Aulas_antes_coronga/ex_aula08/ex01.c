#include <stdio.h>

// Escreva um programa em C que solicita ao usuário
// um número n e então lê um vetor de n notas e
// calcula a média aritmética.

// Usar alocação dinâmica do vetor
// Liberar a memória ao final
// Não limitar o uso de memória

int main(void)
{
  int numNotas;
  printf("Digite o número de notas para descobrir a média: ");
  scanf("%d", &numNotas);

  float *vetNotas = (float *)malloc(numNotas * sizeof(float));
  if (vetNotas == NULL)
  {
    printf("Memória insuficiente! \n");
    exit(1);
  }

  float soma = 0;
  float media = 0;

  for (int i = 0; i < numNotas; i++)
  {
    printf("Digite o valor da nota: ");
    scanf("%f", &vetNotas[i]);

    soma = vetNotas[i] + soma;
  }

  media = soma / numNotas;

  printf("A média de %d notas foi de %f", numNotas, media);
}