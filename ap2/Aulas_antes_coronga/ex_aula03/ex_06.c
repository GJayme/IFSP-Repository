#include <stdio.h>
#include <math.h>

int main(void)
{
  int num1, num2;

  printf("Digite o primeiro número: ");
  scanf("%d", &num1);

  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  while (calcMedia(num1, num2) != 0)
  {
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    calcMedia(num1, num2);
  }
}

int calcMedia(int n1, int n2)
{
  int media;
  media = ((n1 + n2) / 2);

  printf("%d\n", media);

  return media;
}