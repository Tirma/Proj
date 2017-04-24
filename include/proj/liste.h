#ifndef _LISTE
#define _LISTE

#include "NOEUD.h"

struct ELEMENT {
  ARRETE arrete;  
  struct ELEMENT *suiv;
};

typedef struct ELEMENT ELEMENT;

typedef ELEMENT* Liste;

Liste creer_liste();
int liste_vide(Liste liste);
void visualiser_liste(Liste liste);
Liste ajout_tete(NOEUD noeud, Liste liste);
Liste supprimer_tete(Liste liste);
Liste ajout_queue(NOEUD noeud_add, Liste liste );
Liste supprimen(int n, Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);

#endif
