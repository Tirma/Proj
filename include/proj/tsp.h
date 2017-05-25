#ifndef _TSP
#include "fourmi.h"
#include "graph.h"
#include <math.h>
#include <time.h>

#define Q 1

#define _TSP

File tsp(GRAPH g,int m,int nbsomm, double p, int MAX_CYCLE,double alpha, double beta,double evap) ;
FOURMI* initialisation_fourmis(FOURMI* tab, int nbsomm, int m);
void initialisation_pheromones(GRAPH g, int nbnoeud, double p);
void evaporer_pheromones(GRAPH g, int nbnoeud, double p);
int is_in_tabu(FOURMI ant, int sommet);
double proba(int nbville,int depart,int arrive,GRAPH g, double alpha, double beta, FOURMI ant);
ARRETE * choix_prochaine_ville(FOURMI ant, double alpha, double beta,GRAPH g,int nbville);


#endif
