# Proj

## Compilation :
  make

## Effacer le programme :
 make clean

## Dépendances : 
  clang

## Utilisation :
  ./exec nom_du_fiichier.extension
  
  Le programme exec calcule le plus court chemin reliant tout les sommets par la méthode TSP et l'affiche ainsi que son coût sur une fenêtre graphique et le terminal.
  
  ./test
  
  Le programme test, teste les fonction de lecture/création du graphe, d'évaporation et d'initialisation des phéromones, de calcul des probabilités et de choix des prochaines villes.
  
Le fichier du graphe doit se trouver dans le répertoire "fichiers" du projet.
Le programme ne vérifie pas la validité du graphe et ne fonctionne qu'avec un graphe complet.

## Librairies utilisées :
  - stdio
  - stdlib
  - math
  - string
  - SDL
  - SDL_ttf
  - SDL_draw
  
