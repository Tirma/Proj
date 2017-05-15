#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/liste.h"
#include "../include/proj/graph.h"


GRAPH creer_graph(int taille){
  GRAPH graph = calloc(taille, sizeof(NOEUD));
  return graph;
}

void supprimer_graph(GRAPH graph, int taille){
  int i;
  for(i=0;i<taille;i++)
    {
      supprimer_liste(graph[i].voisins);
    }
}


/* Affiche un graph*/
void affiche_graph(GRAPH g, int taille){
  int i=1;
  while(i!=taille)
    {
      printf("%d %s %d %d",g[i])
    }
}



NOEUD ajout_noeud( int numero, char[100] ville, int x, int y){
    NOEUD  elt = NULL;
    elt = calloc(1, sizeof(*elt));
    if(elt == NULL)
    {
        printf("Erreur calloc\n");
        return(null);
    }
    elt.numero = numero;
    elt.ville = ville;
    elt.x=x;
    elt.y=y;
    elt.voisin = creer_liste();
    
    return elt;	
}

GRAPH ajout_arrete(GRAPH graph,int noeud1, int noeud2, double cout, double pheromones){
  ARRETE arrete = calloc(1,sizeof(ARRETE));
  if(!arrete)
    {
      printf("Erreur calloc\n");
      return(graph);
    }

  arrete.numero = noeud1;
  arrete.arr = noeud2;
  arrete.cout = cout;
  arrete.pheromones = pheromones;
  graph[noeud1].voisins = ajout_tete(arrete,graph[noeud1].voisins);
  return graph;
}


