#ifndef BSTREE_H
#define BSTREE_H

    #include <stdio.h>
    #include <stdlib.h>

typedef struct node {
	int value;
	struct node *leftChild;
	struct node *rightChild;
} Node;

typedef struct bstree {
    Node *root;
}BSTree;

BSTree *createBSTree();

void insert(BSTree *t, int value);
Node * Insere(Node *node,int value);
int search(BSTree *t, int value);
void PrintInorder(Node *node);
void freeBSTree(BSTree *t);
void libera(Node *node);
int Find(Node *node, int value, int niveis);

void breadthPrint(BSTree *t);
#endif

