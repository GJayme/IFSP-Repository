#include <stdio.h>
#include <stdlib.h>

int main(void)
/*Escreva um programa em C que solicite ao usuário
um número n e então lê um vetor de n notas e
calcula a média aritmética.
- Usar alocação dinâmica do vetor;
- Liberar a memória ao final;
- Não limitar o uso da memória.
*/
{
  int n = 0;

  //get n
  printf("Digite um núme: ");
  scanf("%d", &n);

  // alocar vetor
  float *vet;
  vet = calloc(n, sizeof(float));
  if (vet == NULL)
  {
    printf("Memoria insuficiente!");
    return (NULL);
  }

  //get grades
  for (int i = 0; i < n; i++)
  {
    printf("Digite a nota %d: ", i + 1);
    scanf("%f", &vet[i]);
  }

  // calc med
  float soma = 0;
  for (int i = 0; i < n; i++)
  {
    soma += vet[i];
  }

  // free vetor
  free(vet);
  printf("A media da turma é %.2f", soma / n);

  return 0;
}