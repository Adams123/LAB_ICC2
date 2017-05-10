#include "NodeQueue.h"

NodeQueue *createNodeQueue()
{
    NodeQueue *queue=(NodeQueue*)malloc(sizeof(NodeQueue));
    queue->head=NULL;
    queue->tail=NULL;
    return queue;
}

void insertNodeQueue(NodeQueue *q, Node *value){
   Element *newElement;
   newElement = (Element*) malloc(sizeof(Element));
   newElement->value = value;
   newElement->prox = NULL;
   if (q->head == NULL) {//inserindo primeiro
       q->head = newElement;
       q->tail = newElement;
   } else { //inserindo no fim
        q->tail->prox= newElement;
        q->tail = newElement;
   }
}

int emptyNodeQueue(NodeQueue *q)
{
    return (q->head == NULL ? 1:0);
}

Node *frontNodeQueue(NodeQueue *q)
{
    return q->head->value;
}

void popNodeQueue(NodeQueue *q)
{
   Element *aux;
   if (q->head == NULL)
        return;
   else {
        aux = q->head;
        q->head = q->head->prox;
        free(aux);
   }
}

void freeNodeQueue(NodeQueue *q)
{
    if(q->head==NULL) return;
    else{
        limpa(q->head);
    }
}
void limpa(Element *elem)
{
    if(elem==NULL) return;
    else limpa(elem->prox);
    free(elem);
}
