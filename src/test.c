#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/graph.h"
#include "../include/proj/fourmi.h"
#include "../include/proj/tsp.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
  
  
  char name[100]="test";
  
  int nbsomm, nbarr;
  char pwd[500];
  char ficname[500] = "fichier/";
  
  FOURMI ant;
  ant.solution = creer_file();
    
  getcwd(pwd, sizeof(pwd));
  FILE* fichier =NULL;
  strcat(ficname,name);
  fichier = fopen(ficname,"r");
  if(!fichier)
    {
      printf("Erreur ouverture fichier %s/fichier/%s",pwd,ficname);
      return EXIT_FAILURE;
    }

  fscanf(fichier,"%d %d\n", &nbsomm,&nbarr);

  GRAPH graph=NULL;
  graph = creer_graph(nbsomm);
  graph = initialiser_graph(fichier,graph,nbsomm,nbarr);
  if(!graph)
    {
      printf("Graph creation error\n");
      return EXIT_FAILURE;
    }
  


  graph[0].voisins->arrete.pheromones = 0.5;
  graph[0].voisins->suiv->arrete.pheromones = 0.2;
  graph[0].voisins->suiv->suiv->arrete.pheromones = 0.3;
  affiche_graph(graph,nbsomm);
  

  ant.solution = enfiler(&(graph[0].voisins->suiv->arrete),ant.solution);
  ant.ville_depart = 2;
  ant.ville_courante = 0;

  printf("\nTEST proba :Grenoble %lf StEtienne %lf Lyon %lf Chambery %lf\nDOIT VALOIR 0 0.402486 0 0.597514\nSi c'est le cas proba fonctionne probablement\n\n",proba(4,0,0,graph,0.2,0.3,ant),proba(4,0,1,graph,0.2,0.3,ant),proba(4,0,2,graph,0.2,0.3,ant),proba(4,0,3,graph,0.2,0.3,ant));

  int i= 0;
  int arr;
  double ste=0;
  double chambe = 0;
  double lyon = 0;
  double grenob = 0;

  srand(time(NULL));
  
  for(i=0;i<10000;i++)
    {
      arr = choix_prochaine_ville(ant,0.2,0.3,graph,4)->arr;
      switch(arr)
	{
	case 0:
	  {grenob++;break;}
	case 1:
	  {ste++;break;}
	case 2:
	  {lyon++;break;}
	case 3:
	  {chambe ++;break;}
	}
    }
  grenob /= 10000;
  ste /= 10000;
  lyon /= 10000;
  chambe /=10000;
  printf("choix : Grenoble %lf StEtienne %lf Lyon %lf Chambery %lf\n10000 essais effectues\n\n",grenob, ste,lyon,chambe);

  
  
  supprimer_graph(graph,nbsomm);

  fclose(fichier);
  fichier = NULL;

  free(graph);
  return EXIT_SUCCESS;
}
