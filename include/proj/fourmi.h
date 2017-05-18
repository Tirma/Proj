#ifndef _FOURMI
#include "file.h"
#define _FOURMI

struct FOURMI {
  FILE* solution;
  int ville_depart;
  int ville_arrivee;
};

typedef struct FOURMI FOURMI;

#endif
