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

typedef struct ElementoLista
{
    ponto *pt;
    struct ElementoLista *seguinte;
} Elemento;

typedef struct ListaDetectada
{
    Elemento *inicio;
    int tamanho;
} Pilha;


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

void remover(figura *f, int vet)
{
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


//------------------------PILHA---------------------
void inicializacao (Pilha *monte)
{
    monte->inicio = NULL;
    monte->tamanho = 0;
}

void push (Pilha * monte, ponto dado)
{
    Elemento *novo_elemento;
    novo_elemento = (Elemento *) malloc (sizeof (Elemento));
    novo_elemento->pt =(ponto*)malloc(sizeof(ponto));

    novo_elemento->pt->x = dado.x;
    novo_elemento->pt->y = dado.y;

    novo_elemento->seguinte= monte->inicio;

    monte-> inicio = novo_elemento;
    monte->tamanho++;
}

void pop (Pilha * monte)
{
    Elemento *aux;
    if (monte->tamanho == 0) return;
    aux = monte->inicio;
    monte->inicio = monte->inicio->seguinte;
    free(aux->pt);
    free(aux);
    monte->tamanho--;
}

void exibe (Pilha * monte)
{
    Elemento *corrente;
    int i;
    corrente = monte->inicio;

    for(i=0; i<monte->tamanho; ++i)
    {
        printf("%d %d ", corrente->pt->x, corrente->pt->y);
        corrente = corrente->seguinte;
    }
    printf("\n");
}

void limpa_pilha(Pilha * monte)
{
    int i;
    while(monte->tamanho>0)
        pop(monte);
    monte->inicio=NULL;
}


int main()
{
    int N=0, i=0;
    ponto *vetor;
//    figura *f;
    Pilha *monte;
    monte = (Pilha*)malloc(sizeof(Pilha));
    inicializacao(monte);
//    f=(figura*)malloc(sizeof(figura));
//    f->p_inicio = NULL;
    while(1)
    {
        scanf("%d", &N);
        if(N==0) break;
//            f->N = N;
        vetor = carrega(N);
        for(i=0; i<N; i++)
        {
//                insere(vetor[i], f);
            push(monte, vetor[i]);
        }
        exibe(monte);
//            limpa(f);
        limpa_pilha(monte);
    }
//    limpa(f);
    free(vetor);
//    free(f);
    return 0;
}



