#include <stdio.h>
#include "../include/proj/liste.h"
#include "../include/proj/file.h"
#include <stdlib.h>

File creer_file()
{
  return creer_liste();
}

int file_vide(File f)
{
  return liste_vide(f);
}

 void visualiser_file(File f) 
 { 
   if(file_vide(f)) 
     { 
       printf("File vide\n"); 
       return; 
     } 
   File adresse = f; 
   do{
     f=f->suiv; 
   }while(f!=adresse); 
 } 

File enfiler(ARRETE* c, File f)
{
  f = ajout_queue(*c,f);
  return f;
}


//La fonction défiler sert ici à supprimer la liste
int defiler(File f)
{
  File mem;
  while(!file_vide(f))
    {
      mem = f;
      f = f->suiv;
      free(mem);
    }
  return EXIT_SUCCESS;
}
