#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/proj/liste.h"
#include "../include/proj/graph.h"


NOEUD* creer_noeud()
{
  return NULL;
}

ARRETE* creer_arrete()
{
  return NULL;
}

GRAPH creer_graph(int taille){
  GRAPH graph = calloc(taille, sizeof(NOEUD));
  return graph;
}

void supprimer_graph(GRAPH graph, int taille){
  int i;
  for(i=0;i<taille;i++)
    {
      if(!liste_vide(graph[i].voisins))
	supprimer_liste(graph[i].voisins);
    }
}


/* Affiche un graph*/
void affiche_graph(GRAPH g, int taille){
  int i=0;
  while(i<taille)
    {
      printf("noeud %d %s %lf %lf\n",g[i].numero, g[i].ville, g[i].x,g[i].y);
      visualiser_liste(g[i].voisins);
      i++;
    }
}



void ajout_noeud(GRAPH graph, int numero, char ville[100], double x, double y,int i){
  graph[i].numero = numero;
  strcpy(graph[i].ville,ville);
  graph[i].x=x;
  graph[i].y=y;
  graph[i].voisins = creer_liste();
}

GRAPH ajout_arrete(GRAPH graph,int noeud1, int noeud2, double cout, double pheromones){
   
  ARRETE arrete;
  
  arrete.numero = noeud1;
  arrete.arr = noeud2;
  arrete.cout = cout;
  arrete.pheromones = pheromones;
  graph[noeud1].voisins = ajout_tete(arrete,graph[noeud1].voisins);
  arrete.numero = noeud2;
  arrete.arr=noeud1;
  graph[noeud2].voisins = ajout_tete(arrete,graph[noeud2].voisins);
  return graph;
}



GRAPH initialiser_graph(FILE* fichier,GRAPH graph, int nbsomm,int nbarr)
{


  char pwd[500];  
  fgets(pwd,500,fichier);
  graph=creer_graph(nbsomm);
  int i=0;
  int numero;
  double x,y;
  char ville[100];
  int j;
  while(i<nbsomm)
    {
      fscanf(fichier,"%d %la %la ",&numero,&x,&y);
      fgets(ville,99,fichier);
      j=0;
      while(ville[j]!='\n')
	{j++;}
      ville[j]='\0';
      ajout_noeud(graph,numero,ville,x,y,i);
      i++;
    }
  fgets(pwd,500,fichier);

  i = 0;
  int depart,arrive;
  double cout;
  while(i<nbarr)
    {
      fscanf(fichier,"%d %d %la ",&depart,&arrive,&cout);
      ajout_arrete(graph,depart,arrive,cout,0);
      i++;
    }
  return graph;
}
