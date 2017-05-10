#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
    double value;
    int copies;
} COPIES;

COPIES *aloca(int n)
{
    int i;
    COPIES *V;
    V=(COPIES*)malloc(sizeof(COPIES)*n);
    for(i=0; i<n; i++)
    {
        V[i].key=n-i;
        V[i].value=0;
        V[i].copies=0;
    }
    return V;
}

COPIES *aloca_zero(int n)
{
    int i;
    COPIES *V;
    V=(COPIES*)malloc(sizeof(COPIES)*n);
    for(i=0; i<n; i++)
    {
        V[i].key=0;
        V[i].value=0;
        V[i].copies=0;
    }
    return V;
}


void merge(COPIES *vet, int esq_i, int esq_f, int dir_i, int dir_f)
{

    int tam_esq = esq_f-esq_i;
    int tam_dir = dir_f-dir_i;

    COPIES *esquerdo, *direito;
    esquerdo = aloca_zero(tam_esq);
    direito = aloca_zero(tam_dir);

    int r=0,i=0,l=0;
    //copiando metade da esquerda
    for(i=esq_i; i<esq_f; i++,l++)
    {
        esquerdo[l].key=vet[i].key;
        esquerdo[l].value=vet[i].value;
        esquerdo[l].copies=++vet[i].copies;
    }

    //copiando metade da direita
    for(i=dir_i; i<dir_f; i++,r++)
    {
        direito[r].key=vet[i].key;
        direito[r].value=vet[i].value;
        direito[r].copies=++vet[i].copies;
    }

    for(i=esq_i, r=0, l=0; l<tam_esq && r<tam_dir; i++)
    {
        if(esquerdo[l].key < direito[r].key)
        {
            vet[i].key = esquerdo[l].key;
            vet[i].copies = esquerdo[l].copies;
            vet[i].value= esquerdo[l++].value;
        }
        else
        {
            vet[i].key = direito[r].key;
            vet[i].copies = direito[r].copies;
            vet[i].value= direito[r++].value;
        }
    }

    for( ; l<tam_esq; l++,i++)
    {
        vet[i].key=esquerdo[l].key;
        vet[i].value=esquerdo[l].value;
        vet[i].copies=esquerdo[l].copies;
    }
    for( ; r<tam_dir; r++,i++)
    {
        vet[i].key=direito[r].key;
        vet[i].value=direito[r].value;
        vet[i].copies=direito[r].copies;
    }

}

void mergesort(COPIES *vet,int init,int end)
{
    if (end-init<=1)
        return;

    int esq_i = init;
    int esq_f = (init+end)/2;
    int dir_i = esq_f;
    int dir_f = end;

    mergesort(vet,esq_i,esq_f);
    mergesort(vet,dir_i,dir_f);

    merge(vet,esq_i,esq_f,dir_i,dir_f);
}

int main()
{
    int qnt;
    COPIES *cp;
    while(scanf("%d", &qnt)!=EOF)
    {
        cp = aloca(qnt);

        mergesort(cp,0,qnt);
        int i;
        for(i=0; i<qnt; i++)
            printf("%d\t%d\n", cp[i].key, cp[i].copies);

        free(cp);
    }


    return 0;
}
