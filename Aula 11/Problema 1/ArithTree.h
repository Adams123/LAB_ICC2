#ifndef ArithTree_H
#define ArithTree_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    char op;
    double val;
    int flag; //1 para valor normal, 0 para operador
    struct Node *left, *right;
} node;

typedef struct arithTree
{
    node *root;
} ArithTree;

ArithTree *createArithTree();

void buildArithTree(ArithTree *t, const char *equation);

void printInOrder(ArithTree *t);
double solveArithTree(ArithTree *t);

void clearArithTree(ArithTree *t);
void freeArithTree(ArithTree *t);

void inorder(node *n);
node *insere(node *root, const char *equation);
double resolve(node *no);
void libera(node *no);
#endif
