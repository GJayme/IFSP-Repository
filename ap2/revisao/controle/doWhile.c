#include <stdio.h>
#include <stdlib.h>

int main() {
  int a;

  printf("Digite um número:\n");

  do
  {
    scanf("%d", &a);
    if(a!=0)
    {
      printf("%d\n", a+1);
    }
  } while(a != 0);

  printf("Fim\n");

  return 0;
}