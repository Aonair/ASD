#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*******************STRUTTURA NODI*****************************/
typedef struct nodeProf{
  int key;
  int prof;
  struct nodeProf * p;
  struct nodeProf * left;
  struct nodeProf * right;
} * NodeProf;

/*******************FUNZIONI DI STAMPA*************************/


/****************CREAZIONE ALBERO CON PROF*******************/


/*******************CODICE ESERCIZIO*************************/
NodeProf minimoAntenatoComume(NodeProf u, NodeProf v){
  NodeProf x = u;
  NodeProf y = v;

  while (x!=NULL && y!=NULL) {

    if ( (x->p->key == y->p->key) && (x!=y) ){
      return x->p;
    }

    if ( (x->p->key == y->p->key) && (x==y) ){
      return y;
    }

    if (x->prof > y->prof){
      x = x->p;
    }
    else {
      y = y->p;
    }

  }

  return NULL;

}


int main(int argc, char const *argv[]) {
  NodeProf ris, create;
  NodeProf a, b, c, d, e, f, g, h;
  a = (NodeProf)malloc(sizeof(struct nodeProf));
  b = (NodeProf)malloc(sizeof(struct nodeProf));
  c = (NodeProf)malloc(sizeof(struct nodeProf));
  d = (NodeProf)malloc(sizeof(struct nodeProf));
  e = (NodeProf)malloc(sizeof(struct nodeProf));
  f = (NodeProf)malloc(sizeof(struct nodeProf));
  g = (NodeProf)malloc(sizeof(struct nodeProf));
  h = (NodeProf)malloc(sizeof(struct nodeProf));

  a->key = 8;
  a->prof= 0;
  a->p = NULL;
  a->left = b;
  a->right = c;

  b->key = 4;
  b->prof= 1;
  b->p = a;
  b->left = d;
  b->right = e;

  c->key = 7;
  c->prof=1;
  c->p = a;
  c->left = f;
  c->right = NULL;

  d->key = 2;
  d->prof=2;
  d->p = b;
  d->left = NULL;
  d->right = g;

  e->key = 3;
  e->prof=2;
  e->p = b;
  e->left = NULL;
  e->right = NULL;

  f->key = 6;
  f->prof=2;
  f->p = c;
  f->left = NULL;
  f->right = h;

  g->key = 1;
  g->prof=3;
  g->p = d;
  g->left = NULL;
  g->right = NULL;

  h->key = 5;
  h->prof=3;
  h->p = f;
  h->left = NULL;
  h->right = NULL;

  ris = minimoAntenatoComume (f, h);

  printf("\n" );
  printf("%d\n", ris->key );

 return 0;
}
