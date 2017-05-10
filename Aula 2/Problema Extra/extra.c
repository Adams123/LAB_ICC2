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

void limpa_seguinte(vertice *v)
{
    vertice *v2;
    while(v!=NULL)
    {
        v2=v->prox;
        free(v);
        v=v2;
    }
}

void remover(figura *f, int vet){
    int count=1;
    vertice *v;
    v=(vertice*)malloc(sizeof(vertice));
       v=f->p_inicio;
    while(count < vet)
    {
        count++;
        v=v->prox;
    }
    printf("%d %d\n", v->p.x, v->p.y);
    limpa_seguinte(v);
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
    int N=0, i=0;
    ponto *vetor;
    figura *f;
        f=(figura*)malloc(sizeof(figura));
        f->p_inicio = NULL;
        
        scanf("%d", &N);

        
        f->N = N;
        vetor = carrega(N);

        for(i=0;i<N;i++)
            insere(vetor[i], f);
        int target;
        scanf("%d", &target);
        remover(f,target);
        limpa(f);
        free(vetor);
        free(f);
    return 0;
}

