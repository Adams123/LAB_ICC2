#include <stdio.h>
#include <stdlib.h>
void ordena( int *v, int tam)
{
    int i, j, aux, k=tam-1;
    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < k; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1]=aux;
            }
        }
        k--;
    }
}

int main()
{
    int A, D, flag=0, i, input;
    int *v1, *v2;
    while(1)
    {
        scanf("%d %d", &A, &D);
        if(A==0 && D ==0) return 0;
        if(A <= 11 && A >=2 && D <=11 && D >= 2)
        {
            v1=(int*)malloc(sizeof(int)*A);
            v2=(int*)malloc(sizeof(int)*D);
            flag=1;
        }

        if(flag==1)
        {
            for(i=0; i<A; i++)
            {
                scanf("%d", &input);
                v1[i]=input;
            }
            for(i=0; i<D; i++)
            {
                scanf("%d", &input);
                v2[i]=input;
            }
            ordena(v1, A);
            ordena(v2, D);
            if(v1[0]<v2[1]) printf("Y");
            else printf("N");
        }
        flag = 0;
    }
}
