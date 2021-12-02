# Headline H1
## Headline H2
### Headline H3
#### Headline H4 
##### Headline H5
# Project Rubiks Cube 3*3
Rubiks cube 3*3 réalisée en C par Léo Beauchet et Dorian Drancourt
## table of content
1.Installation
2.Project description
3.How to use
### Installation
-Installer SDL2(https://www.libsdl.org/download-2.0.php)
-Insaller SDL2_ttf(https://www.libsdl.org/projects/SDL_ttf/)
Pour compiler le projet utilisez la commande make dans un shell puis make clean pour supprimer les fichiers inutile.
#### Project description
Le projet contient les fichiers suivants:
-rubiksCube.h Header qui définie le type rubiks cube et liste les fonctions de rotation du cube
-solveur.h Header qui liste les fonctions de résolutions du cube
-guiRubiksCube.h Header qui définie le nécessaire pour le cube
-listMovement.h Header qui définie la structure listMovement ainsi que ses fonctions

-solveur.c implémente les fonctions de résolution du cube
-guiRubiksCube.c implémente les fonctions de l'interface graphique du cube
-listMovement.c implémente les fonction de listMovement.h appendMov qui ajoute un mouvement a la liste
afficheMov qui affiche tous les mouvements de la liste et une fonction pour libérer la liste
-main.c programme principal
-faceRotations.c implémente toutes les fonctions de rotation du cube

-font.otf fichier de police utilisée par l'interface graphique

Pour représenter le rubiks cube on a choisi de le représenter par une structure contenant 6 champs de typeFace(D,U,L,R,F,B) qui
sont des tableaux 3*3  de couleur qui est une énumération représentant les couleurs des faces.
                                   BBB
                                   BBB
                                   BBB
                                LLLUUURRR
                                LLLUUURRR
                                LLLUUURRR
                                   FFF
                                   FFF
                                   FFF
                                   DDD
                                   DDD
                                   DDD
La fonctions principale de résolution du rubiks cube utilise la méhode débutante de résolution du rubiks cube qui utilise les 
fonctions suivantes:
    -Resoudre la croix du haut
    -Resoudre les coins du haut
    -Resoudre la deuxieme couche
    -Placer la croix du bas
    -Orienter la croix du bas
    -Placer les coins du bas
    -Orienter les coins du bas
Les mouvements sont stocké dans une liste doublement chainée chaque maillon a un suivant et un précédent,la structure
est représentée par un pointeur de maillon qui est le début de la liste chaine et un poiteur de maillon qui représente
la fin de la liste chainée,la liste chainée est triée par ordre antéchronologique des mouvements.

Le fichier principal main contient une fonction qui mélange le cube en utilisant un tableau de pointeur de 
fonction de mouvement en utilisant une boucle de n mouvements on demande un nombre aléation qui est un index dans
le tableau de pointeur de fonction et on fait appel à cette fonction qui réalise un mouvement.

Une fonction initCube() qui renvoye un cube résolue.
Une fonction writeCube(Cube *cube,FILE *f) qui recoit un pointeur de fichier et qui écrit le cube dans le fichier.
La fonction main() qui initialise un cube,ouvre le fichier ou on enregistre le cube et qui contient la boucle principal
qui affiche le menu,demande à l'utilisateur l'action et l'effectue.

Le fichier guiRubiksCube.c qui implémente l'interface graphique du cube utilise la librairie
SDL qui permet d'affiche le rubik's cube en 2D grace à son patron contient les fonctions suivante:
-initgui() qui permet d'initaliser l'interface
-DrawCube() qui affiche le cube et affiche les mouvements precedents et suivants
-next() et prev() qui font les mouvement suivant ou précédent
##### How to use
le programme principal contient 5 options:
- afficher le cube  : l'affiche dans le terminal
- sauvegarder le cube : le sauvegarde dans rubiksCube.txt
- resoudre le cube : qui affiche les mouvements pour résoudre le cube et ouvre une interface graphique
qui en utilisant la touche Y réalise le mouvement suivant et Z pour revenir en arrière
- melanger le cube
- quitter
Entrez simplement dans le terminal le numero correspondant à l'action voulue.