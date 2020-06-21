#include <stdio.h>
#include <stdlib.h>

// Modificar o programa de alocação dinâmica de
// matrizes dado anteriormente (slides 25 a 28) para
// que leia aloque dinamicamente duas matrizes de 3
// por 4, leia seus elementos e imprima a matriz soma.

float matA[3][4];
float **v;

v = (float **)malloc(sizeof *(float *));

if (v == NULL)
{
  printf("Memoria não alocada!");
  return (NULL);
}

for (int i = 0; i < 3; i++)
{
  printf("Digite o valor: ");
  v[i] = (float *)malloc(sizeof *(float))
}

// float **Alocar_matriz_real(int m, int n)
// {
//   float **v; /* ponteiro para a matriz */
//   int i;     /* variavel auxiliar */

//   if (m < 1 || n < 1)
//   { /* verifica parametros recebidos */
//     printf("** Erro: Parametro invalido **\n");
//     return (NULL);
//   }
//   /* aloca as linhas da matriz */
//   v = (float **)calloc(m, sizeof(float *));
//   if (v == NULL)
//   {
//     printf("** Erro: Memoria Insuficiente **");
//     return (NULL);
//   }
//   /* aloca as colunas da matriz */
//   for (i = 0; i < m; i++)
//   {
//     v[i] = (float *)calloc(n, sizeof(float));
//     if (v[i] == NULL)
//     {
//       printf("** Erro: Memoria Insuficiente **");
//       return (NULL);
//     }
//   }
//   return (v); /* retorna o ponteiro para a matriz */
// }

// float **Liberar_matriz_real(int m, int n, float **v)
// {
//   int i; /* variavel auxiliar */

//   if (v == NULL)
//   {
//     return (NULL);
//   }

//   if (m < 1 || n < 1)
//   { /* verifica parametros recebidos */
//     printf("** Erro: Parametro invalido **\n");
//     return (v);
//   }

//   for (i = 0; i < m; i++)
//   {
//     free(v[i]); /* libera as linhas da matriz */
//     free(v);    /* libera a matriz */
//     return (NULL);
//   } /* retorna um ponteiro nulo */
// }

// void main(void)
// {
//   float **mat; /* matriz a ser alocada */
//   int l, c;    /* numero de linhas e colunas da matriz */

//   /* outros comandos, inclusive inicializacao para l e c */

//   mat = Alocar_matriz_real(2, 3);

//   for (int i = 0; i < 2; i++)
//   {
//     for (int j = 0; j < 3; j++)
//     {
//       printf("%f ", mat[i][j]);
//     }
//     printf("\n");
//   }

//   /* outros comandos utilizando mat[][] normalmente */

//   mat = Liberar_matriz_real(l, c, mat);
}