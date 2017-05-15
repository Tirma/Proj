#include <stdio.h>
#include <stdlib.h>
#include "../include/graph.h"
#include "../include/liste.h"

GRAPH creer_graph(int taille){
  GRAPH graph = calloc(taille, sizeof(NOEUD));
  return graph;
}

void supprimer_graph(GRAPH graph, int taille){
  int i;
  for(i=0;i<taille;i++)
    {
      supprimer_liste(graph[i]->voisins);
    }
  free graph;}
