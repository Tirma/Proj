#ifndef _GRAPH
#define _GRAPH

#include "liste.h"

struct ARRETE {
  int numero; //numero de depart
  int arr; //numero d arrive
  double cout;
  double pheromones;
};
typedef struct ARRETE ARRETE;
struct ELEMENT {
  ARRETE arrete;  
  struct ELEMENT *suiv;
};

typedef struct ELEMENT ELEMENT;

typedef ELEMENT* Liste;


struct NOEUD {
  int numero;
  char ville[100];
  int x;
  int y;
  Liste voisins;
};

typedef struct NOEUD* GRAPH;
typedef struct NOEUD NOEUD;



void affiche_graph(GRAPH g,int taille);
GRAPH creer_graph(int taille);
NOEUD ajout_noeud(int numero, char ville[100], int x, int y);
GRAPH ajout_arrete(GRAPH graph,int noeud1, int noeud2, double cout, double pheromones);
void supprimer_graph(GRAPH graph, int taille);
void afficher_graph(GRAPH graph);


#endif
