#include <stdlib.h>
#include <stdio.h>

#define heapSize 2000

typedef struct {
    int prioridade; //prioridade do processo
    int quantidade;  //quantidade de vezes executado
    char id[21]; //nome
} PROCESS;

typedef struct {
    PROCESS *processos[heapSize];
    int tam;
    int (*compare)(PROCESS *, PROCESS *);
} HEAP;

typedef struct {
    int inicio, fim, total;
    PROCESS **processo;
    int tam;
} QUEUE;

void desce(int i, HEAP *heap) {
    int j;

    j = 2 * i + 1;

    if(j < heap->tam) {
        if(j + 1 < heap->tam) {
            if(heap->processos[j]->prioridade > heap->processos[j+1]->prioridade)
                j++;
        }
        if(heap->processos[j]->prioridade < heap->processos[i]->prioridade) {
            PROCESS *aux;
            aux = heap->processos[i];
            heap->processos[i] = heap->processos[j];
            heap->processos[j] = aux;
            desce(j, heap);
        }
    }
}

void minHeap(HEAP *heap) {
    int i;

    for(i = heap->tam / 2; i >= 0; i--) {
        desce(i, heap);
    }
}

void add(HEAP *heap, PROCESS *processo) {
    int i;

    if(heap->tam > heapSize) {
        return;
    } else {
        i = heap->tam;

        while(i > 0 && heap->processos[(i - 1) / 2]->prioridade > processo->prioridade) {
            heap->processos[i] = heap->processos[(i - 1) / 2];
            i = (i - 1) / 2;
        }

        heap->processos[i] = processo;
        heap->tam++;
    }
}

PROCESS *removeHeap(HEAP *heap) {
    PROCESS *processo;

    if(heap->tam != 0) {
        heap->tam--;
        processo = heap->processos[0];
        heap->processos[0] = heap->processos[heap->tam];
        desce(0, heap);
    }

    return processo;
}

void init(QUEUE *queue, int tam) {
    queue->inicio = 0;
    queue->fim = 0;
    queue->total = 0;

    queue->tam = tam;
    queue->processo = (PROCESS**) malloc(tam * sizeof(PROCESS));
}



void insere_fila(QUEUE *queue, PROCESS *processo) {
    if(queue->total != queue->tam) {
        queue->total++;
        queue->processo[queue->fim] = processo;

        if(queue->fim == queue->tam - 1) {
            queue->fim = 0;
        } else {
            queue->fim++;
        }
     }
}

PROCESS *remove_fila(QUEUE *queue) {
    PROCESS *processo;

    if(queue->total!=0) {
        queue->total--;
        processo = queue->processo[queue->inicio];

        if (queue->inicio == queue->tam - 1) {
            queue->inicio = 0;
        } else {
            queue->inicio++;
        }
    }

    return processo;
}

void processa(QUEUE *queue, HEAP *heap, PROCESS *processo)
{
    while(heap->tam>0 || queue->total!=0) { //heap ainda nao esvaziou e fila nao esvaziou
        if(queue->total != queue->tam && heap->tam>0) { //fila nao estourou e heap nao esvaziou
            processo = removeHeap(heap); //remove processo do topo da heap
            insere_fila(queue, processo); //e insere na fila de prioridades

            printf("Executando: %s %d\n", processo->id, processo->prioridade);
        } else {
            processo = remove_fila(queue); //remove da fila de prioridades
            processo->quantidade--;

            if(processo->quantidade > 0) {
                if(heap->tam>0) {
                    if(heap->processos[0]->prioridade < 20) {
                        processo->prioridade = heap->processos[0]->prioridade + 1;
                    } else {
                        processo->prioridade = 20;
                    }
                }

                add(heap, processo);

                printf("Saiu: %s %d\n", processo->id, processo->prioridade);
            } else {
                printf("Executou: %s %d\n", processo->id, processo->prioridade);

                free(processo);
            }
        }
    } 
}


int main() {
    HEAP *heap;
    QUEUE *queue;
    queue=(QUEUE*)malloc(sizeof(QUEUE));
    heap=(HEAP*)malloc(sizeof(HEAP));
    int n;
    PROCESS *processo = (PROCESS *) malloc(sizeof(PROCESS));

    heap->tam=0;

    scanf("%d", &n);
    init(queue, n);

    while(scanf("%d %d %s", &processo->prioridade, &processo->quantidade, processo->id) != EOF) {
        add(heap, processo);
        processo = (PROCESS *) malloc(sizeof(PROCESS));
    }
    
    processa(queue, heap, processo);

    free(heap);
    free(queue);
    return 0;
}
