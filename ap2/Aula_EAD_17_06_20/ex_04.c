#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int **matriz;
  matriz = malloc(sizeof(int *) * 5);
  for (int i = 0; i < 5; i++)
  {
    matriz[i] = malloc(sizeof(int) * 5);
  }
  matriz[0][0] = 10;
  printf("%d", matriz[0][0]);
}