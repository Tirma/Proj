#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/tsp.h"


 File tsp() 
 { 
   File meilleur_chemin = creer_liste(); 
   float cout_meilleur_chemin = +INFINITY;
 } 
 
 
 
 
/* ---- FONCTIONS PHEROMONES ---- */

void evaporer_feromones(GRAPH g, int nbnoeud, double p)
{
	NOEUD * noeud_courant;
	Liste voisins_courants;
	Liste tete_voisin;
	int i,j; 
	for(i=0;i<nbnoeud;i++)
	{
		noeud_courant = graph[i];
		L_voisins_courants = noeud_courant->voisins;
		tete_voisin = noeud_courant->voisins;
		
		while(!Liste_vide(L_voisins_courants))
		{
			L_voins_courant->pheromones = p * L_voins_courant->pheromones;
			L_voisins_courants=L_voisins_courants->suiv;
		}
		noeud_courant->voisin = tete_voisin->voisin;
	}
}





/* ---- FONCTIONS CHEMIN ----*/

double proba(int nbville,int depart,int arrive,GRAPH g, double alpha, double beta, FOURMI ant)
{
  
  int i = 0;
  Liste mem = g[depart].voisins;
  double prob = 0;
  if(arrive==depart)
    return 0;
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
      if(!liste_vide(mem))
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
	      
	      if(!liste_vide(mem))
		sum += pow(mem->arrete.pheromones,alpha)*pow((1/mem->arrete.cout),beta);
	    }
	}
      prob*=1/sum ;
  return prob; //banane
   }
  
}

ARRETE * choix_prochaine_ville(FOURMI ant, double alpha, double beta,GRAPH g,int nbville)
{
  
  int j = ant.ville_courante;
  double tirage = rand()/(double)RAND_MAX;
  double proba_cumul = 0;
  double fx = 0;
  int k;
  Liste arretes = creer_liste();
  for(k=0;k<nbville;k++)
    {
      fx +=proba(nbville,j,k,g,alpha,beta,ant);
      if(fx>=tirage && k!= j)
	{
	  arretes = g[j].voisins;
	  while(arretes->arrete.arr != k)
	    {
	      arretes = arretes->suiv;
	    }
	  return(&(arretes->arrete));
	}
    }
  return NULL;
}


int is_in_tabu(FOURMI ant, int sommet)
{
  int isin = 0;
  File mem = ant.solution;
  while(!(file_vide(ant.solution)))
    {
      if(!file_vide(ant.solution) && (ant.solution->arrete.numero == sommet || ant.solution->arrete.arr == sommet))
	{
	  isin = 1;
	  break;
	}
      ant.solution = ant.solution->suiv;
    }
  ant.solution = mem;
  return isin;
}



