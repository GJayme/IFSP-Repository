#include <stdio.h>
#include <stdlib.h>

// 2. Crie uma funcão que recebe como parâmetro um vetor de inteiros,
// faz uma cópia em uma nova área de memória e retorna o endereço
// da cópia.
int *copiaERetornaEndereco(num)
{
  int vetor[num];
  int *ponteiro;

  ponteiro = malloc(sizeof(vetor[num]));
  if (vetor == NULL)
  {
    return printf("O sistema operacional não conseguiu reservar a memória!");
  }
  else
  {
    for (int i = 0; i <= num; i++)
    {
      ponteiro[i] = vetor[i];
    }
  }
  return (int *)ponteiro;
}

int main(void)
{
  int numero;

  printf("Digite um número:\n");
  scanf("%d", &numero);
  printf("O endereço de memória do número digitado é: %p\n", &numero);
  printf("O endereço da cópia é %p:\n", copiaERetornaEndereco(numero));

  return 0;
}
