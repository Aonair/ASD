#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct node{
  int key;
  struct node * p;
  struct node * left;
  struct node * right;
} * Node;

typedef struct node{
  int key;
  int prof;
  struct nodeProf * p;
  struct nodeProf * left;
  struct nodeProf * right;
} * NodeProf;


NodeProf alberoConProf(Node u){

}



int main(int argc, char const *argv[]) {

 Node u, g, f, m, l, h, v, i, j, w;
 int res=0;
 u = (Node)malloc(sizeof(struct node));
 g = (Node)malloc(sizeof(struct node));
 f = (Node)malloc(sizeof(struct node));
 l = (Node)malloc(sizeof(struct node));
 h = (Node)malloc(sizeof(struct node));
 v = (Node)malloc(sizeof(struct node));
 m = (Node)malloc(sizeof(struct node));
 i = (Node)malloc(sizeof(struct node));
 j = (Node)malloc(sizeof(struct node));
 w = (Node)malloc(sizeof(struct node));
 u->colore = "bianco";
 u->left = g;
 u->right = l;

 g->colore = "verde";
 g->left = f;
 g->right = NULL;

 l->colore = "rosso";
 l->left = h;
 l->right = v;

 f->colore = "bianco";
 f->left = m;
 f->right = NULL;

 m->colore = "rosso";
 m->left = NULL;
 m->right = NULL;

 h->colore = "bianco";
 h->left = NULL;
 h->right = NULL;

 v->colore = "verde";
 v->left = NULL;
 v->right = i;

 i->colore = "bianco";
 i->left = NULL;
 i->right = j;

 j->colore = "rosso";
 j->left = NULL;
 j->right = w;

 w->colore = "verde";
 w->left = NULL;
 w->right = NULL;

  res = bandieraItaliana(u);
/*
Node a,b,c,d,e;
 int res=0;
 a = (Node)malloc(sizeof(struct node));
 b = (Node)malloc(sizeof(struct node));
 c = (Node)malloc(sizeof(struct node));
 d = (Node)malloc(sizeof(struct node));
 e = (Node)malloc(sizeof(struct node));


 a->colore = "bianco";
 a->left = b;
 a->right = c;

 b->colore = "verde";
 b->left = NULL;
 b->right = d;

 c->colore = "verde";
 c->left = NULL;
 c->right = NULL;

 d->colore = "bianco";
 d->left = e;
 d->right = NULL;

 e->colore = "rosso";
 e->left = NULL;
 e->right = NULL;

 res = bandieraItaliana(a);
 */

 printf("Risultato: %d\n", res);
 return 0;
}
