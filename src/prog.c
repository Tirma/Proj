#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/graph.h"
#include "../include/proj/tsp.h"
#include <unistd.h>
#include <string.h>
#include <SDL.h>
#include <SDL_phelma.h>
#include <SDL_ttf.h>

#define alpha 0.8
#define beta 5.6
#define rho 0.8
#define epsilon 0.00001
#define M 2 //2 fourmis par sommet
#define MAX_CYCLE 10

void display(GRAPH g, File meilleur_chemin,int nbsomm, double cout);

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
  mem = chemin;

  while(!file_vide(chemin))
    {
      arrete = chemin->arrete;
      cout += arrete.cout;
      chemin = chemin->suiv;
      printf("%d<--->",arrete.numero);
    }
  printf("%d\n",arrete.arr);
  printf("Cout : %lf",cout);
  printf("\n\n");

  display(graph,mem,nbsomm,cout);

  
  supprimer_graph(graph,nbsomm);

  fclose(fichier);
  fichier = NULL;

  free(graph);
  return EXIT_SUCCESS;
}

void display(GRAPH g, File meilleur_chemin,int nbsomm, double cout)
{
  int i = SDL_Init(SDL_INIT_VIDEO);
  if(i==-1)
    {
      printf("Erreur démarage SDL : %s\n",SDL_GetError());
      return;
    }

  
  int quit = 0;
  SDL_Surface *ecran = NULL, *Renderedtxt = NULL;
  ecran = SDL_SetVideoMode(650,650,32, SDL_SWSURFACE);
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
  
  if(TTF_Init()==-1) 
    {
      printf("TTF_Init: %s\n", TTF_GetError());
      exit(2);
    }
  
  TTF_Font* police = TTF_OpenFont("fonts/impact.ttf",18);

  if(!police) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }

  SDL_Color noir = {0,0,0,0};
  SDL_Rect position;
  
  char texte[100]= {};
  File mem = creer_file();
  for(i=0;i<nbsomm;i++)
    {
      strcpy(texte,g[i].ville);

      Renderedtxt = TTF_RenderText_Blended(police,texte, noir);

      position.x = g[i].x*650 - Renderedtxt->w/2;
      position.y = g[i].y*650 - Renderedtxt->h/2;
      
      if(position.x<0)
	{
	  position.x = 0;
	}
      if(position.y<0)
	{
	  position.y = 0;
	}
      if(position.x + Renderedtxt->w/2 + 1 >650)
	{
	  position.x = 650 - Renderedtxt->w;
	}
      if(position.y + Renderedtxt->h/2 + 1 >650)
	{
	  position.y = 650 - Renderedtxt->h;
	}

      SDL_BlitSurface(Renderedtxt,NULL,ecran,&position);

      mem = g[i].voisins;
      while(!file_vide(g[i].voisins))
	{
	  Draw_Line(ecran,
               g[i].x*650, g[i].y*650, g[g[i].voisins->arrete.arr].x*650, g[g[i].voisins->arrete.arr].y*650,
		    SDL_MapRGBA(ecran->format,0,0,0,0));
	  g[i].voisins = g[i].voisins->suiv;
	}
      g[i].voisins = mem;
    }

  

  while(!file_vide(meilleur_chemin))
    {
      Draw_Line(ecran,g[meilleur_chemin->arrete.numero].x*650,g[meilleur_chemin->arrete.numero].y*650,g[meilleur_chemin->arrete.arr].x*650,g[meilleur_chemin->arrete.arr].y*650,SDL_MapRGBA(ecran->format,255,0,0,0));
      mem = meilleur_chemin;
      meilleur_chemin = meilleur_chemin->suiv;
      free(mem);
    }

  char coutchar[50];
  sprintf(coutchar,"%lf", cout); 

  strcpy(texte,"Cout : ");
  strcat(texte,coutchar);
  Renderedtxt = TTF_RenderText_Blended(police,texte, noir);
  position.x = 650/2 - Renderedtxt->w/2;
  position.y = Renderedtxt->h;
  SDL_BlitSurface(Renderedtxt,NULL,ecran,&position);
  
  SDL_Flip(ecran);
  
  while(!quit)
  {
    if(SDL_QuitRequested())
      quit = 1;    
  }

  TTF_CloseFont(police);
  SDL_FreeSurface(ecran);
  SDL_FreeSurface(Renderedtxt);
  TTF_Quit();
  SDL_Quit();
}
