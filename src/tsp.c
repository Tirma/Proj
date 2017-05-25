#include <stdio.h>
#include <stdlib.h>
#include "../include/proj/tsp.h"



File tsp(GRAPH g,int m,int nbsomm, double p, int MAX_CYCLE,double alpha, double beta, double evap) 
 { 
   File meilleur_chemin = creer_file(); 
   double cout_meilleur_chemin = +INFINITY;
   double cout=0;
   File memory=creer_file();
   
   FOURMI* tab_fourmi = calloc(m*nbsomm,sizeof(FOURMI));
   initialisation_pheromones(g,nbsomm,p);
   ARRETE* arrete=NULL;
   int i,j,k;

   for(i=0;i<MAX_CYCLE;i++)
     {
       printf("Cycle %d sur %d\n",i+1,MAX_CYCLE);
       tab_fourmi=initialisation_fourmis(tab_fourmi,nbsomm,m);
       for(j=0;j<nbsomm*m;j++)
	 {
	   cout = 0;
	   while(choix_prochaine_ville(tab_fourmi[j],alpha,beta,g,nbsomm))
	     {
	       arrete=choix_prochaine_ville(tab_fourmi[j],alpha,beta,g,nbsomm);
	       tab_fourmi[j].solution = enfiler(arrete,tab_fourmi[j].solution);
	       tab_fourmi[j].ville_courante = arrete->arr; 
	       cout+=arrete->cout;
	       if(cout>cout_meilleur_chemin)
		 break;
	     }
	   if(cout_meilleur_chemin>cout)
	     {
	       meilleur_chemin = tab_fourmi[j].solution;
	     }
	 }
       evaporer_pheromones(g,nbsomm,p);
       for(k=0;k<nbsomm*m;k++)
	 {
	   evaporer_pheromones(g,nbsomm,evap);
	   memory = tab_fourmi[k].solution;
	   while(!file_vide(tab_fourmi[k].solution))
	     {
	       tab_fourmi[k].solution->arrete.pheromones += Q;
	       tab_fourmi[k].solution = tab_fourmi[k].solution->suiv;
	     }
	   defiler(tab_fourmi[k].solution);
	   tab_fourmi[k].solution =creer_file();
        }
     }
   free(tab_fourmi);   
   return meilleur_chemin;
 } 

FOURMI* initialisation_fourmis(FOURMI* tab, int nbsomm, int m)
{
  int i,j;
  for(i=0;i<nbsomm;i++)
    {
      for(j=0;j<m;j++)
	{
	  tab[i].ville_courante = i;
	  tab[i].ville_depart = i;
	  tab[i].solution = creer_file();
	}
    }
  return tab;
}

 
/* ---- FONCTIONS PHEROMONES ---- */


void initialisation_pheromones(GRAPH g, int nbnoeud, double p)
{
	NOEUD noeud_courant;
	Liste voisins_courants;
	Liste tete_voisin;
	int i; 
	for(i=0;i<nbnoeud;i++)
	{
		noeud_courant = g[i];
		voisins_courants = noeud_courant.voisins;
		tete_voisin = noeud_courant.voisins;
		
		while(!liste_vide(voisins_courants))
		{
			voisins_courants->arrete.pheromones = p;
			voisins_courants=voisins_courants->suiv;
		}
		noeud_courant.voisins = tete_voisin;
	}
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


void evaporer_pheromones(GRAPH g, int nbnoeud, double p)
{
	NOEUD noeud_courant;
	Liste voisins_courants;
	Liste tete_voisin;
	int i; 
	for(i=0;i<nbnoeud;i++)
	{
		noeud_courant = g[i];
		voisins_courants = noeud_courant.voisins;
		tete_voisin = noeud_courant.voisins;
		
		while(!liste_vide(voisins_courants))
		{
			voisins_courants->arrete.pheromones = p * voisins_courants->arrete.pheromones;
			voisins_courants=voisins_courants->suiv;
		}
		noeud_courant.voisins = tete_voisin;
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


