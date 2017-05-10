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

void imprime(figura *f)
{
    vertice *v;
    v=(vertice*)malloc(sizeof(vertice));
       v=f->p_inicio;
    while(v!=NULL){
        printf("%d %d ", v->p.x, v->p.y);
        v=v->prox;
    }
    printf("\n");
}

void insere (ponto k, figura* f)
{
    vertice *v;
    v=(vertice*)malloc(sizeof(vertice));
    v->p = k;            //prepara o vertice para inserção
    v->prox = NULL;

    if(f->p_inicio==NULL) //primeira inserção
    {
        f->p_inicio = v;
    }
    else{ //inserindo depois
        vertice *aux;
        aux = f->p_inicio;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=v;
    }
}

void translada (ponto *p, int dx, int dy)
{
    p->x += dx;
    p->y += dy;
}

void translada_figura (figura* f, int dx, int dy)
{
    f->Dx = dx;
    f->Dy = dy;
    vertice *aux;
    aux = f->p_inicio;

    while(aux!=NULL){
        translada(&aux->p, dx, dy);
        aux=aux->prox;
    }
}

ponto* carrega(int N){

    ponto *vetor;
    int i=0;
    vetor = (ponto*)malloc(sizeof(ponto)*N);
    for(i=0; i<N; i++)
        scanf("%d %d", &vetor[i].x, &vetor[i].y);

    return vetor;
}

void limpa(figura *f)
{
    vertice *v;
    v = (vertice*)malloc(sizeof(vertice));
    vertice *v2;
    
    v=f->p_inicio;
    while(v!=NULL)
    {
        v2=v->prox;
        free(v);
        v=v2;
    }
    f->p_inicio=NULL;
}
int main()
{
    int N=0, i=0, dx, dy;
    ponto *vetor;
    figura *f;
        f=(figura*)malloc(sizeof(figura));
        f->p_inicio = NULL;
        
        scanf("%d", &N);

        
        f->N = N;
        vetor = carrega(N);

        scanf("%d %d", &dx, &dy);
        for(i=0;i<N;i++)
            insere(vetor[i], f);

        translada_figura(f, dx, dy);

        imprime(f);
        limpa(f);
        free(vetor);
        free(f);
    return 0;
}

