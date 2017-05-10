#include <stdlib.h>
#include <stdio.h>

int heapSize;

typedef struct {
    int prioridade; //prioridade do processo
    char palavra[101];  //quantidade de letras
} PROCESS;

typedef struct {
    PROCESS **processos;
    int tam;
    int (*compare)(PROCESS *, PROCESS *);
} HEAP;


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

int main() {
    HEAP *heap;
    heap=(HEAP*)malloc(sizeof(HEAP));
    heap->tam=0;

    PROCESS *processo = (PROCESS *) malloc(sizeof(PROCESS));

    scanf("%d", &heapSize);

    int i;
    heap->processos=(PROCESS**)malloc(sizeof(PROCESS)*heapSize);
    for(i=0;i<heapSize;i++){
        scanf("%s", processo->palavra);
        processo->prioridade=1;
        add(heap,processo);
    }
    minHeap(heap);
    while(heap->tam>0)
    {
        processo=removeHeap(heap);
        printf("%s\n", processo->palavra);
    }
    free(processo);
    free(heap);
    return 0;
}
