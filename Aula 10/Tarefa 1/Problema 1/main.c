#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qnt;
    scanf("%d", &qnt);
    BSTree *tree = createBSTree();
    int i;
    int elem;
    for(i=0;i<qnt;i++){
        scanf("%d", &elem);
        insert(tree,elem);
    }

    int out;
    while(scanf("%d", &out)!=EOF){
        out=search(tree,out);
        if(out==-1) printf("NAO ACHOU\n");
        else printf("ACHOU %d\n", out);
    }
    freeBSTree(tree);
    return 0;
}
