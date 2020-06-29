#include <stdio.h>

float main()
{
  float x, y, z;

  printf("Digite o valor do lado x: ");
  scanf("%f", &x);

  printf("Digite o valor do lado y: ");
  scanf("%f", &y);

  printf("Digite o valor do lado z: ");
  scanf("%f", &z);

  if (x < y && x < z)
  {
    if (y < z)
    {
      printf("A ordem do menor para o maior é: ");
      printf("%f\n", x);
      printf("%f\n", y);
      printf("%f\n", z);
    }
    else
    {
      printf("A ordem do menor para o maior é: ");
      printf("%f\n", x);
      printf("%f\n", z);
      printf("%f\n", y);
    }
  }
  else if (y < x && y < z)
  {
    if (x < z)
    {
      printf("A ordem do menor para o maior é: ");
      printf("%f\n", y);
      printf("%f\n", x);
      printf("%f\n", z);
    }
    else
    {
      printf("A ordem do menor para o maior é: ");
      printf("%f\n", y);
      printf("%f\n", z);
      printf("%f\n", x);
    }
  }
  else
  {
    if (x < y)
    {
      printf("A ordem do menor para o maior é: ");
      printf("%f\n", z);
      printf("%f\n", x);
      printf("%f\n", y);
    }
    else
    {
      printf("A ordem do menor para o maior é: ");
      printf("%f\n", z);
      printf("%f\n", y);
      printf("%f\n", x);
    }
  }
}