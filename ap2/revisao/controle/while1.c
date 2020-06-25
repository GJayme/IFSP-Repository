#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a; 

  printf("Digite um número: \n");
  scanf("%d", &a);
  while(a != 0)
  {
    printf("%d\n", a+1);
    scanf("%d", &a);
  }
  printf("Fim\n");

  return 0;
}