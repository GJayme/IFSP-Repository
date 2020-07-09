#include <stdio.h>
#include <stdlib.h>

/*
  ●Implementar os códigos de ordenação disponíveis nos slides.
  ●Você não deve copiar e colar e também não deve ficar com o slide aberto na hora de implementar. 
    Você deve ler o código, entender, e tentar implementar sem olhar para o código do slide.
  ●Fazer um programa principal de teste que experimente todas as funções.
*/

// Função para trocar de lugar:
void trocaLugar(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

// Função printa Array
void printaArray(int vetor[], int tamanhoVetor)
{
  for (int i = 0; i < tamanhoVetor; i++)
  {
    printf("%d - ", vetor[i]);
  }
  printf("\n");
}

// Função retorna menor elemento:
int menorElemento(int vetor[], int tamanhoVetor, int primeiro)
{
  int menor;
  menor = primeiro;
  for (int i = primeiro + 1; i < tamanhoVetor; i++)
  {
    if (vetor[i] < vetor[menor])
    {
      menor = i;
    }
  }
  return menor;
}

// Ordenação por seleção:
int ordenacaoSelecao(int vetor[], int n)
{
  int menor;
  for (int i = 0; i < n; i++)
  {
    menor = menorElemento(vetor, n, i);
    trocaLugar(&vetor[i], &vetor[menor]);
  }
}

int main()
{
  int numeros[10] = {2, 6, 9, 11, 22, 4, 5, 0, 1, 3};
  int numeroElementos = sizeof(numeros) / sizeof(numeros[0]);

  printf("Lista sem ordenação: \n");
  printaArray(numeros, numeroElementos);

  ordenacaoSelecao(numeros, numeroElementos);
  printf("Lista ordenada (Selection-Sort)\n");
  printaArray(numeros, numeroElementos);

  return 0;
}