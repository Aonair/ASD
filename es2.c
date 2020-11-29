#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*******************STRUTTURA NODI*****************************/
typedef struct node{
  int key;
  struct node * p;
  struct node * left;
  struct node * right;
} * Node;

typedef struct nodeProf{
  int key;
  int prof;
  struct nodeProf * p;
  struct nodeProf * left;
  struct nodeProf * right;
} * NodeProf;

/*******************FUNZIONI DI STAMPA*************************/
void printNodePreOrder (Node u){
  if (u == NULL)
    return;
  printf(" %d ", u->key);
  printNodePreOrder (u->left);
  printNodePreOrder (u->right);
}

void printNodeProfPreOrder (NodeProf a){
  if (a == NULL)
    return;
  printf(" %d:%d ", a->key, a->prof);
  printNodePreOrder (a->left);
  printNodePreOrder (a->right);
}

/*******************CODICE ESERCIZIO*************************/
NodeProf alberoConProfAux(Node u, int grado, NodeProf p){
  NodeProf a;

  if (u == NULL){
    return NULL;
  }

  a = (NodeProf)malloc(sizeof(struct nodeProf));
  a->key = u->key;
  a->prof = grado;
  a->p = p;
  a->left = alberoConProfAux (u->left, a->prof+1, a);
  a->right = alberoConProfAux (u->right, a->prof+1, a);

  return a;

}

NodeProf alberoConProf(Node u){
  int grado=0;
  NodeProf p = NULL;
  return alberoConProfAux (u, grado, p);
}


int main(int argc, char const *argv[]) {
  NodeProf ris;
  Node a, b, c, d, e, f, g, h;
  a = (Node)malloc(sizeof(struct node));
  b = (Node)malloc(sizeof(struct node));
  c = (Node)malloc(sizeof(struct node));
  d = (Node)malloc(sizeof(struct node));
  e = (Node)malloc(sizeof(struct node));
  f = (Node)malloc(sizeof(struct node));
  g = (Node)malloc(sizeof(struct node));
  h = (Node)malloc(sizeof(struct node));

  a->key = 8;
  a->p = NULL;
  a->left = b;
  a->right = c;

  b->key = 4;
  b->p = a;
  b->left = d;
  b->right = e;

  c->key = 7;
  c->p = a;
  c->left = f;
  c->right = NULL;

  d->key = 2;
  d->p = b;
  d->left = NULL;
  d->right = g;

  e->key = 3;
  e->p = b;
  e->left = NULL;
  e->right = NULL;

  f->key = 6;
  f->p = c;
  f->left = NULL;
  f->right = h;

  g->key = 1;
  g->p = d;
  g->left = NULL;
  g->right = NULL;

  h->key = 5;
  h->p = f;
  h->left = NULL;
  h->right = NULL;

  ris = alberoConProf(a);

  printf("\n" );
  printNodePreOrder(a);
  printf("\n" );
  printNodeProfPreOrder(ris);
  printf("\n" );

 return 0;
}
