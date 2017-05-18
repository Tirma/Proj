#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/tsp.h"


/* File tsp() */
/* { */
/*   File meilleur_chemin = creer_liste(); */
/*   float cout_meilleur_chemin = +INFINITY; */
/* } */

int is_in_tabu(FOURMI ant, int sommet)
{
  int isin = 0;
  File mem = ant.solution;
  while(!(file_vide(ant.solution)))
    {
      if(ant.solution->arrete.numero == sommet || ant.solution->arrete.arr == sommet)
	{
	  isin = 1;
	  break;
	}
      ant.solution = ant.solution->suiv;
    }
  ant.solution = mem;
  return isin;
}

double proba(int nbville,int depart,int arrive,GRAPH g, double alpha, double beta, FOURMI ant)
{
  
  int i = 0;
  Liste mem = g[depart].voisins;
  double prob = 0;
  
  if(is_in_tabu(ant,arrive))
    {
      return 0;
    } 
  
  else
    {
      while(!liste_vide(mem) && mem->arrete.arr != arrive )
	{
	  mem = mem->suiv;
	}
      prob = pow(mem->arrete.pheromones,alpha)*pow((1/mem->arrete.cout),beta);
      double sum=0;
      for(i=0;i<nbville;i++)
	{
	  mem = g[depart].voisins;
	  if(!is_in_tabu(ant,i))
	    {
	      while(!liste_vide(mem) && mem->arrete.arr != i )
		{
		  mem = mem->suiv;
		}
	      
	      sum += pow(mem->arrete.pheromones,alpha)*pow((1/mem->arrete.cout),beta);
	    }
	}
      prob*=1/sum ;
  return prob;
   }
  
}

void choix_prochaine_ville(FOURMI ant, double alpha, double beta,GRAPH g,int nbville)
{
  srand(time(NULL));
  double tirage = rand()/RAND_MAX;
}
