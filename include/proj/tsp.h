#ifndef _TSP
#include "fourmi.h"
#include "graph.h"
#include <math.h>
#include <time.h>
#define _TSP


int is_in_tabu(FOURMI ant, int sommet);
double proba(int nbville,int depart,int arrive,GRAPH g, double alpha, double beta, FOURMI ant);
ARRETE * choix_prochaine_ville(FOURMI ant, double alpha, double beta,GRAPH g,int nbville);


#endif
