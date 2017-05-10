#include "NodeQueue.h"

int main()
{
    int in;
    BSTree *tree = createBSTree();
    while(scanf("%d", &in)!=EOF)
        insert(tree,in);

    NodeQueue *queue;
    queue=createNodeQueue();
    insertNodeQueue(queue,tree->root);
    Element *elem = (Element*)malloc(sizeof(Element));
    int leftFlag, rightFlag;
    while(!emptyNodeQueue(queue)){
        elem->value=frontNodeQueue(queue);

        if(elem->value->leftChild==NULL) leftFlag=0;
        else leftFlag=1;
        if(elem->value->rightChild==NULL) rightFlag=0;
        else rightFlag=1;

        if(leftFlag && rightFlag)
        printf("%d eh pai de %d e %d\n", elem->value->value, elem->value->leftChild->value, elem->value->rightChild->value);
        else if(leftFlag)
        printf("%d eh pai de %d\n", elem->value->value, elem->value->leftChild->value);
        else if(rightFlag)
        printf("%d eh pai de %d\n", elem->value->value, elem->value->rightChild->value);
        else
            printf("%d nao possui filhos\n", elem->value->value);
        if(elem->value->leftChild!=NULL)
            insertNodeQueue(queue,elem->value->leftChild);
        if(elem->value->rightChild!=NULL)
            insertNodeQueue(queue,elem->value->rightChild);
        popNodeQueue(queue);
    }

    freeNodeQueue(queue);
    freeBSTree(tree);
    return 0;
}
