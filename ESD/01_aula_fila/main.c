#include <stdio.h>
#include <stdlib.h>

struct QUEUE {
    int queueCapacity;
    float *data;
    int first;
    int last;
    int numItems;
};

void createQueue(struct QUEUE *q, int capacity) {
    q->queueCapacity = capacity;
    q->data = (float*) malloc(q->queueCapacity * sizeof(float ));
    q->first = 0;
    q->last = 0;
    q->numItems = 0;
}

void insertNumber(struct QUEUE *q, int number) {
    if (q->last == q->numItems -1) {
        q->last = -1;
    }
    q->last++;
    q->data[q->last] = number; //incrementa ultimo e insere
    q->numItems++; //um novo item add
}

int removeNumber(struct QUEUE *q) {
    int temp = q->data[q->first++]; //pega o valor e incrementa o primeiro
    if(q->first == q->numItems) {
        q->first = 0;
    }
    q->numItems--;
    return temp;
}

int isEmpty(struct QUEUE *q) {
    return (q->numItems==0); //retorna verdadeiro se a fila estiver vazia
}

int isFull(struct  QUEUE *q) {
    return (q->numItems == q->queueCapacity); //retorna verdadeiro se a fila estiver cheia
}

void showQueue(struct QUEUE *q) {
    int count, i;
    for (count=0, i = q->first; count < q->numItems; count++) {
        printf("%.2f\n", q->data[i++]);
        if(i == q->queueCapacity){
            i = 0;
        }
    }
    printf("\n\n");
}


int main() {
    struct QUEUE simpleQUEUE;
    createQueue(&simpleQUEUE, 10);

    isFull(&simpleQUEUE);
    showQueue(&simpleQUEUE);

    insertNumber(&simpleQUEUE,2);
    showQueue(&simpleQUEUE);

    insertNumber(&simpleQUEUE,3);
    showQueue(&simpleQUEUE);

    insertNumber(&simpleQUEUE,4);
    showQueue(&simpleQUEUE);

    showQueue(&simpleQUEUE);

    return 0;
}
