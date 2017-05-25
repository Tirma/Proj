#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/graph.h"
#include "../include/proj/tsp.h"
#include <unistd.h>
#include <string.h>
#include <SDL.h>
#include <SDL_phelma.h>

#define alpha 0.8
#define beta 5.6
#define rho 0.8
#define epsilon 0.00001
#define M 2 //2 fourmis par sommet
#define MAX_CYCLE 10

void display(GRAPH g, File meilleur_chemin);

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
      printf("Erreur ouverture fichier %s/%s",pwd,ficname);
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
  File mem = creer_file();
  chemin = tsp(graph,M,nbsomm,epsilon,MAX_CYCLE,alpha,beta,rho);
  ARRETE arrete;
  printf("\n\nChemin le plus court reliant tous les sommets :\n");
  double cout = 0;
  while(!file_vide(chemin))
    {
      arrete = chemin->arrete;
      mem = chemin;
      cout += arrete.cout;
      chemin = chemin->suiv;
      free(mem);
      printf("%d<--->",arrete.numero);
    }
  printf("%d\n",arrete.arr);
  printf("Cout : %lf",cout);
  printf("\n\n");


  display(graph,chemin);
  
  supprimer_graph(graph,nbsomm);

  fclose(fichier);
  fichier = NULL;

  free(graph);
  return EXIT_SUCCESS;
}

void display(GRAPH g, File meilleur_chemin)
{
  int i = SDL_Init(SDL_INIT_VIDEO);
  if(i==-1)
    {
      printf("Erreur démarage SDL : %s\n",SDL_GetError());
      return;
    }

  

  SDL_Event* event;
  int quit = 0;
  SDL_Surface *ecran = NULL;
  ecran = SDL_SetVideoMode(650,650,32, SDL_SWSURFACE);
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  SDL_Flip(ecran);

  
  
  while(!quit)
  {
    if(SDL_QuitRequested())
      quit = 1;
  }
  
  SDL_Quit();
}
