#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"
#include <string.h>

void initialiser_jeu(Sokoban *jeu) // Initialise les variables du jeu et la grille
{
    jeu->grille = (int**)malloc(TAILLE_GRILLE * sizeof(int*)); // Allocation de la grille
    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        jeu->grille[i] = (int*)malloc(TAILLE_GRILLE * sizeof(int)); // Allocation de chaque ligne
    }

    // Initialisation de la grille vide avec murs
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            if (i == 0 || i == TAILLE_GRILLE-1 || j == 0 || j == TAILLE_GRILLE-1)
                jeu->grille[i][j] = 4; // mur
            else
                jeu->grille[i][j] = 0; // vide
        }
    }

    // Génération des positions aléatoires différentes et valides
    int caisse_x; 
    int caisse_y; 
    int joueur_x; 
    int joueur_y; 
    int objectif_x; 
    int objectif_y;
    int position_valide;
    while (1 == 1) // boucle jusqu'à obtenir des positions valides
    {
        caisse_x = rand() % (TAILLE_GRILLE-2) + 1; // Position aléatoire entre 1 et TAILLE_GRILLE-2
        caisse_y = rand() % (TAILLE_GRILLE-2) + 1;
        joueur_x = rand() % (TAILLE_GRILLE-2) + 1;
        joueur_y = rand() % (TAILLE_GRILLE-2) + 1;
        objectif_x = rand() % (TAILLE_GRILLE-2) + 1;
        objectif_y = rand() % (TAILLE_GRILLE-2) + 1;
        position_valide = 1; // suppose que la position est valide
        if ((caisse_x == joueur_x && caisse_y == joueur_y) || // vérifie que les positions sont différentes
            (caisse_x == objectif_x && caisse_y == objectif_y) ||
            (joueur_x == objectif_x && joueur_y == objectif_y)) 
            {
                position_valide = 0; // positions non valides
            }
        if ((jeu->grille[caisse_x-1][caisse_y] == 4 && jeu->grille[caisse_x][caisse_y-1] == 4) || // verifie que la caisse n'est pas bloquée dans un coin
            (jeu->grille[caisse_x-1][caisse_y] == 4 && jeu->grille[caisse_x][caisse_y+1] == 4) ||
            (jeu->grille[caisse_x+1][caisse_y] == 4 && jeu->grille[caisse_x][caisse_y-1] == 4) ||
            (jeu->grille[caisse_x+1][caisse_y] == 4 && jeu->grille[caisse_x][caisse_y+1] == 4)) 
            {
                position_valide = 0;
            }
        if (caisse_x == 1 || caisse_x == TAILLE_GRILLE-2 || caisse_y == 1 || caisse_y == TAILLE_GRILLE-2) // évite de placer la caisse sur les bords
        {
            position_valide = 0;
        }
        if (position_valide == 1) // si les positions sont valides, on sort de la boucle
        {
            break; // sort de la boucle
        }
    }

    // Placement des éléments
    jeu->grille[caisse_x][caisse_y] = 1; // caisse
    jeu->grille[joueur_x][joueur_y] = 3; // joueur
    jeu->grille[objectif_x][objectif_y] = 2; // objectif

    jeu->pos_x = joueur_x;
    jeu->pos_y = joueur_y;
    jeu->pos_victoire_x = objectif_x;
    jeu->pos_victoire_y = objectif_y;
    jeu->fin = 0;
}

void liberer_jeu(Sokoban *jeu) 
{
    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        free(jeu->grille[i]);
    }
    free(jeu->grille);
}




