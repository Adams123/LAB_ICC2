#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "BSTree.h"

typedef struct element{
    struct element *prox;
    struct node *value;
}Element;

typedef struct nodequeue {
    Element *head;
    Element *tail;
}NodeQueue;

NodeQueue *createNodeQueue(); //

void insertNodeQueue(NodeQueue *, Node *); //

int emptyNodeQueue(NodeQueue *); //

Node *frontNodeQueue(NodeQueue *); //
void popNodeQueue(NodeQueue *); //

void freeNodeQueue(NodeQueue *); //
void limpa(Element *elem);

#endif
