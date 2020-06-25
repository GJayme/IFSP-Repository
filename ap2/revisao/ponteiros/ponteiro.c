#include <stdio.h>
#include <stdlib.h>

//função que soma 10 ao valor recebido
void somaComVariavel(int x) //quando a função for void ela não retorna nada
{
  x = x +10;
  printf("Valor de x apos a soma = %d\n", x);
  return;
}

void somaComPonteiro(int *x) //quando a função for void ela não retorna nada
{
  *x = *x +10;
  printf("Valor de x apos a soma = %d\n", *x);
  return;
}

int main(void) 
{
  int numero;
  printf("Digite um número: \n");
  scanf("%d", &numero);

  printf("O número escolhido foi: %d\n", numero);
  printf("-----------------------------------------\n");

  
  //chamada da função com variavel:
  somaComVariavel(numero);
  printf("Agora o número vale: %d\n", numero);

  printf("-----------------------------------------\n");

  //chamada da função com ponteiro:
  somaComPonteiro(&numero);
  printf("Agora o número vale: %d\n", numero);
  return 0;
}