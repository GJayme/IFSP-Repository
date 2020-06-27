#include <stdio.h>
#include <stdlib.h>

float **matriz1(int m, int n) {
  float **v; /* ponteiro para a matriz */
  int i;      /* variável auxiliar */
  if (m < 1 || n < 1) {
    printf("** Erro: Parametro invalido **\n");
    return (NULL);
  }
  /* aloca as linhas da matriz */
  v = (float**) calloc(m, seizeof(float*));
  if (v == NULL) {
    printf("** Erro: Memoria insuficiente **");
    return (NULL);
  }

  /* aloca as colunas da matriz */
  for(i = 0; i<m; i++) {
    v[i] = (float*) calloc (n,seizeof(float));
    if (v[i] == NULL) {
      printf("** Erro: Memoria insuficiente");
      return(NULL);
    }
  }
  return (v);
}

float **Liberar_matriz(int m, int n, float **v) {
  int i; /* variavel auxiliar */
  if (v == NULL) {
    return (NULL);
  }
  if(m < 1 || n < 1) { /* verificar parametros recebidos */
    printf("** Erro: Parametro invalido");
    return(v);
  }

  for(i = 0; i < m; i++) free(v[i]); /* libera as linhas da matriz */

  free(v); /* libera a matriz */
  return (NULL); /* retorna um ponteiro nulo */
}

void main(void)
{
  float **mat; /* matriz a ser alicada */
  int l, c;

  mat = matriz1(l,c);

  mat = Liberar_matriz(l,c,mat);
}
