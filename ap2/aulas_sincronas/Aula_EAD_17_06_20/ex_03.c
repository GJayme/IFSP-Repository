#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *p1;
  int *p2;

  p1 = malloc(sizeof(int));
  p2 = malloc(sizeof(int));
  free(p2);
  p2 = p1;
  free(p2);
}