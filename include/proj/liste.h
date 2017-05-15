#ifndef _LISTE
#define _LISTE

#include "graph.h"



Liste creer_liste();
int liste_vide(Liste liste);
void visualiser_liste(Liste liste);
Liste ajout_tete(ARRETE arrete, Liste liste);
Liste supprimer_tete(Liste liste);
Liste ajout_queue(ARRETE arrete_add, Liste liste );
Liste supprimen(int n, Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);
Liste supprimer_liste(Liste l);

#endif
