#ifndef _FILE
#include "carte.h"
#include "liste.h"
#define _FILE

typedef Liste File;

#endif

File creer_file(void); //Créer une file vide
int file_vide(File f); //Teste si la file est vide
void visualiser_file(File f);
File enfiler(CARTE , File f); //Ajoute une carte à la file par la queue
CARTE defiler(File* f); //Renvoie la carte en tete de file ET la supprime de la file
