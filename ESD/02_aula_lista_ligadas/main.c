#include "stdio.h"
#include "stdlib.h"

/*
 * Struct do Nó
 */
struct No {
    int info;
    struct No *prox;
};

typedef struct No No;

/*
 * Inserir elemento na Lista encadeada
 */
void insere(No *p, int k){
    No *novo;
    novo = malloc(sizeof(No));
    novo->info = k;
    novo->prox = p->prox;
    p->prox = novo;
}

/*
 * imprimir lista
 */
void imprime(No *ini) {
    No *p;
    p = ini;
    while (p){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void imprimeRecursivo(No *p){
    if(p){
        printf("%d ", p->info);
        imprimeRecursivo(p->prox);
    }
    printf("\n");
}

/*
 * Buscar elemento
 */
No *busca(No *ini, int k){
    No *p = ini;
    while (p && p->info != k){
        p = p->prox;
    }
    return p;
}

No *buscaRecursivo(No *p, int k){
    if (!p || p->info == k) {
        return p;
    }
    return buscaRecursivo(p->prox, k);
}

/*
 * Remover elemnto: Recebe um ponteiro p de um nó de uma
 *  lista ligada com a cabeça remove o nó que vem depois
 *  do nó apontado por p. Só faz sentido de p != NULL
 */
void removeElemento(No *p){
    No *q;
    q = p->prox;
    p->prox = q->prox;
    free(q);
}

int main() {
    struct No {
        int info;
        struct No *prox;
    };

    typedef struct No No;

    /*
     * Criar nó cabeça
     */
    No *ini;
    ini = malloc(sizeof(No));
    ini->prox = NULL;

    insere(ini, 5);
    insere(ini, 6);
    insere(ini, 9);

    imprime(ini);

    removeElemento(ini);

    imprime(ini);

    return 0;
}