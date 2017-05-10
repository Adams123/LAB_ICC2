#include <stdio.h>
#include <stdlib.h>

typedef struct pnt
{
    int x, y;
} ponto;

typedef struct vrtc vertice;
struct vrtc
{
    ponto p;
    vertice* prox;
};

typedef struct fig
{
    int N;
    int Dy, Dx;
    vertice* p_inicio;
} figura;

void translada (ponto *p, int dx, int dy)
{
    p->x += dx;
    p->y += dy;
}

void translada_figura (ponto p_vet[], int N, int dx, int dy)
{
    int i=0;
    for(i=0; i<N; i++)
        translada(&p_vet[i],dx,dy);
}

ponto* carrega(int N){

    ponto *vetor;
    int i=0;
    vetor = (ponto*)malloc(sizeof(ponto)*N);
    for(i=0; i<N; i++)
        scanf("%d %d", &vetor[i].x, &vetor[i].y);

    return vetor;
}
int main()
{
    int N=0, i=0, dx, dy;
    ponto *vetor;
    
    while(1){
        scanf("%d", &N);
        if(N==0) break;
        vetor = carrega(N);

        scanf("%d %d", &dx, &dy);

        translada_figura(vetor, N, dx, dy);

        for(i=0; i<N; i++)
            printf("%d %d ", vetor[i].x, vetor[i].y);
        free(vetor);
    }
    return 0;
}
