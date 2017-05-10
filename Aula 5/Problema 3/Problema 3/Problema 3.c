#include <stdlib.h>
#include <stdio.h>
typedef struct bloco
{
    int valor;
    int flag;
    struct bloco *prox;
} no;

typedef struct
{
    no *inicio, *fim;
} Lista;

void cria(Lista *L)  //função que seta os poteiros de um nó(criação da lista)
{
    L->inicio=NULL;
    L->fim=NULL;
}

void finaliza(Lista *L)  //finaliza a lista
{
    no *p;
    p=L->inicio;
    while (p!=NULL)
    {
        L->inicio=L->inicio->prox;
        free(p);
        p=L->inicio;
    }
    L->fim=NULL;
}


void inserir(Lista *L, int x)  //o insere ordenado
{
    no *p;
    no *aux;
    no *anterior;

    anterior = L->inicio;
    aux = L->inicio;
    p=(no*) malloc(sizeof(no));
    p->valor = x;
    p->prox=NULL;
    if (L->inicio==NULL)
    {
        L->inicio=p;
        L->fim = p;
    }
    else
    {
        while(aux != NULL && aux->valor < p->valor)
        {
            anterior = aux;
            aux = aux->prox;
        }
        if(L->inicio == anterior && anterior->valor > p->valor)
        {
            p->prox = anterior;
            L->inicio = p;
        }
        else
        {
            if(aux == NULL && L->inicio != anterior)
            {
                p->prox = anterior->prox;
                anterior->prox = p;
                L->fim = p;
            }
            else
            {
                p->prox = anterior->prox;
                anterior->prox = p;
            }
        }
    }
}

int tamanho(Lista *L)  //retorna o tamanho da lista
{
    no *p;
    int contador=0;

    p=L->inicio;
    while (p!=NULL)
    {
        contador++;
        p=p->prox;
    }
    return(contador);
}

void imprimir(Lista *L)  //imprimi a lista de adjacência
{
    no *p;

    p=L->inicio;
    while (p!=NULL)
    {
        printf("%d ",p->valor);
        p=p->prox;
    }
    printf("\n");
}

Lista *merge(Lista *L1, Lista *L2)
{
    no *p1, *p2;
    p1=L1->inicio;
    p2=L2->inicio;
    Lista *L3;
    L3 = (Lista*)malloc(sizeof(Lista));
    cria(L3);
    while(p1 != NULL || p2 != NULL)
    {
        if(p1->valor <= p2->valor)
        {
            inserir(L3, p1->valor);
            p1 = p1->prox;
            if(p1==NULL) break;
        }
        else
        {
            inserir(L3, p2->valor);
            p2 = p2->prox;
            if(p2==NULL) break;
        }
    }

    if(p1 == NULL)//caso acabou lista 1;
    {
        while(p2 != NULL)
        {
            inserir(L3, p2->valor);
            p2 = p2->prox;
            if(p2==NULL) break;
        }
    }
    else if(p2 == NULL)//caso acabou lista 1;
    {
        while(p1 != NULL)
        {
            inserir(L3, p1->valor);
            p1 = p1->prox;
            if(p1==NULL) break;
        }
    }
    return L3;
}

int main()
{
    Lista *L1 = (Lista *)malloc(sizeof(Lista));
    Lista *L2 = (Lista *)malloc(sizeof(Lista));
    Lista *L3 = (Lista *)malloc(sizeof(Lista));
    int N=-1, B=-1, i, in;
    while(scanf("%d %d", &N, &B) != EOF)
    {
        cria(L1);
        cria(L2);
        cria(L3);

        for(i=0; i<N; i++)
        {
            scanf("%d", &in);
            inserir(L1,in);
        }
        for(i=0; i<B; i++)
        {
            scanf("%d", &in);
            inserir(L2,in);
        }
        imprimir(L1);
        imprimir(L2);
        L3 = merge(L1, L2);
        imprimir(L3);
        finaliza(L1);
        finaliza(L2);
        finaliza(L3);
    }
    return 0;
}
