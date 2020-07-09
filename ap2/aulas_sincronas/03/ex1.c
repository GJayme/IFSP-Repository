#include <stdio.h>
#include <stdlib.h>

/*
  ●Implementar os códigos de ordenação disponíveis nos slides.
  ●Você não deve copiar e colar e também não deve ficar com o slide aberto na hora de implementar. 
    Você deve ler o código, entender, e tentar implementar sem olhar para o código do slide.
  ●Fazer um programa principal de teste que experimente todas as funções.
*/

// ----------------------------------------- FUNÇÕES AUXILIARES -----------------------------------------
// Função printa Array
void printaArray(int vetor[], int tamanhoVetor)
{
  for (int i = 0; i < tamanhoVetor; i++)
  {
    printf("%d - ", vetor[i]);
  }
  printf("\n");
}

// ----------------------------------------- ORDENAÇÃO POR SELEÇÃO -----------------------------------------
// Função para trocar de lugar:
void trocaLugar(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
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

int ordenacaoSelecao(int vetor[], int n)
{
  int menor;
  for (int i = 0; i < n; i++)
  {
    menor = menorElemento(vetor, n, i);
    trocaLugar(&vetor[i], &vetor[menor]);
  }
}

// ----------------------------------------- ORDENAÇÃO POR INSERÇÃO -----------------------------------------
int posicaoElemento(int vetor[], int ultimoElemento, int elemento)
{
  for (int i = 0; i <= ultimoElemento && vetor[i] <= elemento; i++)
  {
    return i;
  }
}

void deslocaSubvetor(int vetor[], int primeiroElemento, int ultimoElemento)
{
  for (int i = ultimoElemento; i >= primeiroElemento; i--)
  {
    vetor[i + 1] = vetor[i];
  }
}

int ordenacaoInsercao(int vetor[], int tamanhoVetor)
{
  int posicao, elemento;
  for (int i = 1; i < tamanhoVetor; i++)
  {
    elemento = vetor[i];
    posicao = posicaoElemento(vetor, i - 1, elemento);
    deslocaSubvetor(vetor, posicao, i - 1);
    vetor[posicao] = elemento;
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

  int numeros2[10] = {2, 6, 9, 11, 22, 4, 5, 0, 1, 3};
  int numeroElementos2 = sizeof(numeros2) / sizeof(numeros2[0]);

  printf("Lista sem ordenação: \n");
  printaArray(numeros2, numeroElementos2);

  ordenacaoInsercao(numeros2, numeroElementos2);
  printf("Lista ordenada (Insert-Sort)\n");
  printaArray(numeros2, numeroElementos2);

  return 0;
}