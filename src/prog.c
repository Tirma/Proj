#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/graph.h"
#include "../include/proj/tsp.h"
#include <unistd.h>
#include <string.h>

#define alpha 1
#define beta 2
#define rho 0.5
#define epsilon 0.00001
#define M 4
#define MAX_CYCLE 10

int main(int argc, char* argv[])
{
  
  if(argc!=2)
    {
      printf("\n\nsyntaxe : exec nom_fichier\n\n");
      return EXIT_FAILURE;
    }
  char name[100];
  strcpy(name,argv[1]);

  
  int nbsomm, nbarr;
  char pwd[500];
  char ficname[500] = "fichier/";
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
  
  affiche_graph(graph,nbsomm);

  File chemin = creer_file();
  chemin = tsp(graph,M,nbsomm,epsilon,MAX_CYCLE,alpha,beta,rho);
  ARRETE arrete;
  printf("\n\n");
  while(!file_vide(chemin))
    {
      arrete = defiler(chemin);
      printf("%d %d ",arrete.numero,arrete.arr);
    }
  printf("\n\n");
    
  supprimer_graph(graph,nbsomm);

  fclose(fichier);
  fichier = NULL;

  free(graph);
  return EXIT_SUCCESS;
}
