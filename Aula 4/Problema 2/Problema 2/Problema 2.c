#include <stdio.h>
#include <stdlib.h>

#define TAM 103

typedef struct Sequencia
{
    char *s;
    int tam;
} sequencia;

int distancia(char *seq)
{
    int cont = 0, i, j;

    for (i=0; seq[i]; i++)
    {
        for (j=i+1; seq[j]; j++)
            if (seq[i]>seq[j])
                cont++;
    }
    return cont;
}

void bubble(sequencia *v,int N)
{
    int i, j, k=N-1;
    sequencia aux;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < k; j++)
        {
            if(v[j].tam > v[j+1].tam)
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1]=aux;
            }
        }
        k--;
    }
}

int main ()
{
    int testes, i, n, m;
    scanf ("%d", &testes);
    int linhabranca = 0;
    sequencia *seq;
    seq=(sequencia*)malloc(sizeof(sequencia)*TAM);
    while ( testes>0 )
    {
        scanf ("%d %d", &n, &m);

        for (i=0; i<m; i++)
        {
            seq[i].s=(char*)malloc(sizeof(char)*(n+1));
            scanf("%s", seq[i].s);
            seq[i].tam = distancia(seq[i].s);
        }

        bubble(seq,m);

        if (linhabranca)printf("\n");
        linhabranca = 1;

        for (i=0; i<m; i++)
            printf("%s\n", seq[i].s);

        testes--;
    }
    free(seq);
    return 0;
}
