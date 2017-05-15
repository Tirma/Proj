#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

Liste creer_liste()
{
    return NULL;
}

int liste_vide(Liste liste)
{
    if(liste==NULL)
        return 1;
    return 0;
}

void visualiser_liste(Liste liste)
{
    if(!liste_vide(liste))
    {
      printf("-> %d %d %lf %lf\n",
	     liste->arrete->numero,
	     liste->arrete->arr,
	     liste->arrete->cout,
	     liste->arrete->pheromones);
        visualiser_liste(liste->suiv);
    }
}

Liste ajout_tete(ARRETE arrete, Liste liste)
{
    Liste elt = NULL;
    elt = calloc(1, sizeof(*elt));
    if(elt == NULL)
    {
        printf("Erreur calloc\n");
        return(liste);
    }
    elt->arrete = arrete;
    elt->suiv = liste;
    return elt;
}

Liste supprimer_tete(Liste liste)
{
    if(!(liste_vide(liste)))
    {
        Liste suiv;
        suiv = liste->suiv;
        free(liste);
        return suiv;
        
    }
    else 
    {
        return liste;
    }
}
Liste ajout_queue(ARRETE arrete_add, Liste liste )
{
    Liste tete = liste;
    Liste elt = NULL;
    elt = calloc(1,sizeof(*elt));
    elt->arrete = arrete_add;
    elt->suiv = NULL;
    if(liste_vide(liste))
    	return elt;
    while(!liste_vide(liste->suiv))
    {
        liste = liste->suiv;
    }
    liste->suiv = elt;
    return tete;
}

Liste supprimen(int n, Liste l)
{
    Liste tete = l;
    while(!liste_vide(l) && n>2)
    {
        l = l->suiv;
        n--;
    }
    if((l->suiv))
    {Liste suiv = l->suiv->suiv;
    free(l->suiv);
    l->suiv = suiv;
    }
    return tete;
}

Liste concat(Liste l1, Liste l2)
{
    Liste concat = creer_liste();
    Liste concat_2 = creer_liste();
    
    concat_2=copie(l2);
    concat=copie(l1);
    
    Liste tete = concat;
    if(liste_vide(concat))
    	return concat_2;
    while(!liste_vide(concat->suiv))
    {
        concat = concat->suiv;
    }
    concat->suiv = concat_2;
    return tete;
}

Liste copie(Liste l)
{
    Liste cop = creer_liste();
    while(!(liste_vide(l)))
    {
        cop = ajout_queue(l->carte,cop);
        l = l->suiv;
    }
    return cop;
}

Liste supprimer_liste(Liste l){
  while(!liste_vide(l))
    {
      supprimer_tete(l);
    }
};
