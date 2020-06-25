#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Hello word! \n");
  int i;
  int x = 5;
  int *p1;
  int *p2;

  p1 = &x;
  p2 = malloc(sizeof(int));

  if (p2 != NULL)
  {
    *p2 = 10;
    printf("%d - %f\n", *p1, *p2);
  }
  else
  {
    printf("O sistema operacional não conseguiu reservar a memória!");
  }

  for (i = 0; i < 100; i++)
  {
    p2 = malloc(sizeof(int));
    *p2 = 10;
    printf("%d - ", i + *p2);
  }

  free(p2);
  p2 = NULL;

  return 0;
}