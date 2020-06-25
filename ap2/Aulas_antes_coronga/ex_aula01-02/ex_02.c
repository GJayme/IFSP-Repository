#include <stdio.h>
#include <math.h>

float main()
{
  float a, b, c, delta, x1, x2;

  printf("Entre com o valor de a: ");
  scanf("%f", &a);

  printf("Entre com o valor de b: ");
  scanf("%f", &b);

  printf("Entre com o valor de c: ");
  scanf("%f", &c);

  delta = pow(b, 2) - (4 * a * c);
  printf("O valor de delta é %f\n", delta);

  if (delta < 0)
  {
    printf("Delta valor que zero, portanto é uma raiz de um número complexo!");
  }
  else
  {
    if (delta == 0)
    {
      x1 = -(b / (2 * a));
      x2 = x1;
      printf("A raiz 1 será: %f\n", x1);
      printf("A raiz 2 será: %f\n", x2);
    }
    else
    {
      x1 = -(b / (sqrt(delta)) / (2 * a));
      x2 = +(b / (sqrt(delta)) / (2 * a));
      printf("A raiz 1 será: %f\n", x1);
      printf("A raiz 2 será: %f\n", x2);
    }
  }
}
