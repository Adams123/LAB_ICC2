#include "BSTree.h"

BSTree *createBSTree()
{
    BSTree *tree;
    tree=(BSTree*)malloc(sizeof(BSTree));
    tree->root=NULL;
    return tree;
}

void insert(BSTree *t, int value)
{
    t->root=Insere(t->root, value);
}

Node * Insere(Node *node,int value)
{
        if(node==NULL)
        {
                Node *temp;
                temp = (Node *)malloc(sizeof(Node));
                temp -> value = value;
                temp -> leftChild = temp -> rightChild = NULL;
                return temp;
        }

        if(value >(node->value))
        {
                node->rightChild = Insere(node->rightChild,value);
        }
        else if(value < (node->value))
        {
                node->leftChild= Insere(node->leftChild,value);
        }
        return node;

}

int search(BSTree *t, int value){
    return (Find(t->root, value, 0));
}

int Find(Node *node, int value, int niveis)
{
        if(node==NULL) //chegou no fim e não achou nada
                return -1;
        if(value > node->value) //pesquisa para a direita
                return Find(node->rightChild,value, niveis+1);
        else if(value < node->value)//Pesquisa para a esquerda
                return Find(node->leftChild,value, niveis+1);
        else //encontrou
                return niveis;
}

void freeBSTree(BSTree *t)
{
    libera(t->root);
}

void libera(Node *node){

    if(node == NULL)
        return;

    libera(node->leftChild);
    libera(node->rightChild);

    free(node);

}
