#ifndef _FILE
#include "graph.h"
#include "liste.h"
#define _FILE

typedef Liste File;



File creer_file(void); //Créer une file vide
int file_vide(File f); //Teste si la file est vide
//void visualiser_file(File f);
File enfiler(ARRETE* , File f); //Ajoute un element à la file par la queue
ARRETE* defiler(File* f); //Renvoie la carte en tete de file ET la supprime de la file

#endif
