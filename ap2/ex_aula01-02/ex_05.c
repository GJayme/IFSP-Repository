#include <stdio.h>

int main()
{
  float x, y, z;

  printf("Digite o valor do lado x: ");
  scanf("%f", &x);

  printf("Digite o valor do lado y: ");
  scanf("%f", &y);

  printf("Digite o valor do lado z: ");
  scanf("%f", &z);

  if ((x < y + z) && (y < x + z) && (z < x + y))
  {
    if (((x == y) && (x == z)) || ((y == x) && (y == z)) || ((z == x) && (z == y)))
    {
      printf("É um triangulo Equilatero!");
    }
    else if ((x == y) || (x == z) || (y == x) || (y == z) || (z == x) || (z == y))
    {
      printf("É um triangulo Isósceles!");
    }
    else
    {
      printf("É um triângulo Escaleno!");
    }
  }
  else
  {
    printf("Não é um triângulo!");
  }
}
