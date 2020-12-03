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

/*******************CODICE ESERCIZIO*************************/
int tBilAux (Node u, int h){
  int risSx, risDx;

  if (u == NULL){
    return 0;
  }

  risSx = tBilAux (u->left, h+1 );
  risDx = tBilAux (u->right, h+1 );

  if (risSx > h){
    return risSx;
  }
  if (risDx > h){
    return risDx;
  }
  else {
    return h;
  }

}


int tBil(Node u){
  int h=0;
  return tBilAux (u, h);
}

/************************MAIN********************************/
int main(int argc, char const *argv[]) {
  int ris;
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

  ris = tBil(a);

  printf("\n" );
  printNodePreOrder(a);
  printf("\n" );

  printf("%d\n", ris );


 return 0;
}
