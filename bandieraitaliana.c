/* il tempo di esecuzione è theta di n, dove n sono i nodi dell'albero u. 
Infatti l'albero viene visitato postordine, permettendo così di poter scomporre il problema in due sottoalberi; sx e dx. 
Avremmo una suddivisione del tempo t(n) in t(k) + t(n-k-1) + d, dove k sono i nodi del sottoalbero sx.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bandieraitaliana.h"

struct node{
	char * colore;
	struct node * left;
	struct node * right;
};

int bandieraItaliana(Node u){
	int bianco, rosso;
	return bandieraAux(u, &bianco, &rosso);
}

int bandieraAux (Node u, int *bianco, int *rosso){
	int biancoSx=0, biancoDx=0, rossoSx=0, rossoDx=0, rissx, risdx;


	if (u == NULL){
	 	*bianco = 0; 
		*rosso = 0;
		return 0;
	}

	rissx = bandieraAux (u->left,  &biancoSx, &rossoSx);
	risdx = bandieraAux (u->right, &biancoDx, &rossoDx);

	if (rissx == 0 && risdx == 0){

		if (rossoSx == 0 || rossoDx == 0){
			if (strcmp(u->colore, "rosso") == 0){
				*rosso = 1;
			}
			else {
				*rosso = 0;
				*bianco = 0;;

			}
		}

		if (rossoSx == 1 || rossoDx == 1) {
			if (strcmp(u->colore, "bianco") == 0){
				*bianco = 1;
				*rosso = 1;
			}
			else {
				*rosso = 0;
				*bianco = 0;

			}
		}
		if ( (rossoSx == 1 || rossoDx == 1) && (biancoSx == 1 || biancoDx == 1)) {
			if (strcmp(u->colore, "verde") == 0){
				return 1 || risdx || rissx ;
			}
			else {
				*rosso = 0;
				*bianco = 0;

			}
		}
		
	}
	printf ("NODE:%s	BIANCO:%d	ROSSO:%d	RISPSX:%d	RISPDX:%d\n\n", u->colore, *bianco, *rosso, rissx, risdx);
	return (risdx || rissx);
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
