#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pnt
{
    int x, y;
} ponto;

typedef struct vrtc
{
    ponto p;
    struct vrtc* prox;
} vertice;

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
    while(v!=NULL)
    {
        printf("%d %d ", v->p.x, v->p.y);
        v=v->prox;
    }
    printf("\n");
}

void remover(figura *f, int vet)
{
    if(vet > f->N)
    {
        printf("Nao achou\n");
        return;
    }

    int count=1;
    vertice *v;
    v=(vertice*)malloc(sizeof(vertice));
    v=f->p_inicio;
    vertice *aux;
    aux=(vertice*)malloc(sizeof(vertice));

    if(vet == 1)
    {
        f->p_inicio = v->prox;
        free(v);
        imprime(f);
        return;
    }
    while(count < vet)
    {
        count++;
        aux=v;
        v=v->prox;
    }

    aux->prox = v->prox;
    free(v);
    imprime(f);
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
    else  //inserindo depois
    {
        vertice *aux;
        aux = f->p_inicio;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=v;
    }
}

ponto* carrega(int N)
{

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

int busca(int pos, figura *f, vertice* v)
{
    if(f->p_inicio == NULL) return 0;  //lista vazia

    int cont=1;
    vertice *aux;
    aux=(vertice*)malloc(sizeof(vertice));
    aux=f->p_inicio;

    if(pos==1)  //primeiro da lista
    {
        *v=*aux;
        return 1;
    }

    while(aux!=NULL && cont < pos)  //percorre a lista
    {
        aux=aux->prox;
        cont++;
    }

    if(aux==NULL || cont > pos) return 0; //chegou no fim e não achou
    else
    {
        *v=*aux;
        return 1;
    }
}

void imprime_vertice(vertice *v)
{
    printf("%d %d\n", v->p.x, v->p.y);
}

float distancia(ponto a, ponto b)
{
    return (sqrt((pow((b.x - a.x),2)) + pow((b.y - a.y),2)));
}

void distancia_todos(vertice *v, figura *f, float *vet_dist)
{
    if(f->p_inicio == NULL) return;  //lista vazia

    vertice *aux;
    aux=(vertice*)malloc(sizeof(vertice));
    aux=f->p_inicio;



    while(aux!=NULL)  //percorre a lista
    {
        printf("%.2f ", distancia(v->p, aux->p));
        aux=aux->prox;
    }
    printf("\n");
}

int main()
{
    int N=0, i=0, a, b;
    char opt;
    ponto *vetor;
    figura *f;
    vertice *v1;
    float *vet_dist;
    v1=(vertice*)malloc(sizeof(vertice));
    f=(figura*)malloc(sizeof(figura));
    f->p_inicio = NULL;
    scanf("%d", &N);
    f->N = N;
    vetor = carrega(N);
    vet_dist=(float*)malloc(sizeof(float)*N);
    for(i=0; i<N; i++)
        insere(vetor[i], f);

    while(1)
    {

        opt=getchar();

        switch(opt)
        {
        case 'i':
            scanf("%d %d", &a, &b);
            vetor[0].x=a;
            vetor[0].y=b;
            insere(vetor[0], f);
            f->N++;
            imprime(f);
            break;
        case 'r':
            scanf("%d", &a);
            remover(f, a);
            break;
        case 'b':
            scanf("%d", &a);
            if(busca(a, f, v1))
                imprime_vertice(v1);
            else
                printf("Nao achou\n");
            break;
        case 'e':
            limpa(f);
            break;
        case 's':
            free(v1);
            limpa(f);
            free(vetor);
            free(vet_dist);
            free(f);
            return 0;
            break;
        }
    }
}
