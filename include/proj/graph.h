#ifndef _GRAPH
#define _GRAPH

#include "liste.h"

struct NOEUD {
  int numero;
  char[100] ville;
  int x;
  int y;
  Liste voisins;
};

typedef struct NOEUD* GRAPH;
typedef struct NOEUD NOEUD;

struct ARRETE {
  int numero;
  double arr;
  double cout;
  double pheromones;
}

typedef struct ARRETE ARRETE;

GRAPH creer_graph(void);
int graph_vide(GRAPH graph);
GRAPH ajout_noeud(GRAPH graph, int numero, char[100] ville, int x, int y);
GRAPH ajout_arrete(GRAPH noeud1, GRAPH noeud2, double arr, double cout, double pheromones);
void supprimer_graph(GRAPH graph);
void afficher_graph(GRAPH graph);


#endif
