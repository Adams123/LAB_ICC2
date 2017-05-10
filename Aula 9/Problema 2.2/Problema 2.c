#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
            printf("Maior\n");
        if(j + 1 < heap->tam) {
            printf("Tambem maior\n");
            if(strcmp(heap->processos[j]->palavra, heap->processos[j+1]->palavra)<0)
                j++;
        }
        if(strcmp(heap->processos[j]->palavra,heap->processos[i]->palavra)>0) {
            PROCESS *aux;
            printf("%d %d\n", i, j);
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

        while(i > 0 && strcmp(heap->processos[(i - 1) / 2]->palavra,processo->palavra)<0) {
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

void mostrarHeap(HEAP *heap) {
    int i;

    printf("conteudo da fila de prioridades: \n");

    for(i = 0; i < heap->tam; i++) {
        printf("%d: %s\n", i, heap->processos[i]->palavra);
    }

    printf("-------\n");
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
        add(heap,processo);
    }

    minHeap(heap);
    mostrarHeap(heap);
    while(heap->tam>0)
    {
        processo=removeHeap(heap);
        printf("%s\n", processo->palavra);
    }
    free(processo);
    free(heap);
    return 0;
}
