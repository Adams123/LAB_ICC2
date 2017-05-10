#include "avl.h"

int main()
{
    node *t;

    t = NULL;
    
    int in;
    int max;
    scanf("%d", &max);
    int i;
    for(i=0;i<max;i++)
    {
    	scanf("%d", &in);
    	t=insere(in, t);
    }

    while(scanf("%d", &in)!=EOF)
    {
    	node *aux = busca(in, t);
    	if(aux == NULL) printf("NAO ACHOU\n");
    	else printf("ACHOU %d\n", aux->height);
    }


    clear(t);

    return 0;
}
