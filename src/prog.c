#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/graph.h"
#include <unistd.h>
#include <string.h>

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
  supprimer_graph(graph,nbsomm);

  fclose(fichier);
  fichier = NULL;

  free(graph);
  return EXIT_SUCCESS;
}
