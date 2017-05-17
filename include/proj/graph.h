#ifndef _GRAPH
#include "liste.h"
#define _GRAPH



/* struct ARRETE { */
/*   int numero; //numero de depart */
/*   int arr; //numero d arrive */
/*   double cout; */
/*   double pheromones; */
/* }; */
/* typedef struct ARRETE ARRETE; */
/* struct ELEMENT { */
/*   ARRETE arrete;   */
/*   struct ELEMENT *suiv; */
/* }; */

/* typedef struct ELEMENT ELEMENT; */

/* typedef ELEMENT* Liste; */


struct NOEUD {
  int numero;
  char ville[100];
  double x;
  double y;
  Liste voisins;
};

typedef struct NOEUD* GRAPH;
typedef struct NOEUD NOEUD;


NOEUD* creer_noeud();
ARRETE* creer_arrete();
void affiche_graph(GRAPH g,int taille);
GRAPH creer_graph(int taille);
void ajout_noeud(GRAPH g,int numero, char ville[100], double x, double y,int i);
GRAPH ajout_arrete(GRAPH graph,int noeud1, int noeud2, double cout, double pheromones);
void supprimer_graph(GRAPH graph, int taille);
GRAPH initialiser_graph(FILE* fichier,GRAPH graph, int nbsomm,int nbarr);
#endif
