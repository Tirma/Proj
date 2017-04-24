1#include <stdio.h>
#include "liste.h"
#include "file.h"
#include <stdlib.h>

File creer_file()
{
  return creer_liste();
}

int file_vide(File f)
{
  return liste_vide(f);
}

/* void visualiser_file(File f) */
/* { */
/*   if(file_vide(f)) */
/*     { */
/*       printf("File vide\n"); */
/*       return; */
/*     } */
/*   File adresse = f; */
/*   do */
/*   { */
/*     affiche(&(f->suiv->carte)); */
/*     f=f->suiv; */
/*   }while(f!=adresse); */
/* } */

File enfiler(ARRETE* c, File f)
{
  File elt = creer_file();
  elt=calloc(1,sizeof(File));
  elt->arrete = c;
  if(!file_vide(f))
  {
      elt->suiv = f->suiv;
      f->suiv = elt;
      f = elt;
  }
  else
    {  elt->suiv = elt; f=elt;}
  
  return f;
}

ARRETE* defiler(File * f)
{
  ARRETE c=(*f)->suiv->arrete;
  if((*f)->suiv == *f)
    {
      free(*f);
      *f = creer_file();
      return c;
    }
  File suiv = (*f)->suiv->suiv;
  File tofree = (*f)->suiv;
  (*f)->suiv = suiv;
  free(tofree);
  return c;
}
