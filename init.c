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
    
  
    int initial[TAILLE_GRILLE][TAILLE_GRILLE] = {  // Initialisation de la grille
        {4,4,4,4,4,4,4,4,4,4},
        {4,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,4},
        {4,0,0,1,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,0,0,4},
        {4,0,0,0,0,0,0,2,0,4},
        {4,4,4,4,4,4,4,4,4,4}
    };
    
    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        for (int j = 0; j < TAILLE_GRILLE; j++) 
        {
            jeu->grille[i][j] = initial[i][j]; // Copie de la grille initiale pour que chaque partie commence de la même façon
        }
    }
    
 // Initialisation des autres variables
    jeu->pos_x = 3; // position initiale du joueur en x
    jeu->pos_y = 3; // position initiale du joueur en y
    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        for (int j = 0; j < TAILLE_GRILLE; j++) 
        {
            if (jeu->grille[i][j] == 2)  // Trouve la position de l'objectif
            {
                jeu->pos_victoire_x = i; // position x de l'objectif
                jeu->pos_victoire_y = j; // position y de l'objectif
            }
        }
    }
    
    jeu->fin = 0; // fin de partie initialisée à 0 pour indiquer que la partie est en cours si la variable vaux 1 la partie est terminé
    
    jeu->grille[jeu->pos_x][jeu->pos_y] = 3; // place le joueur sur la grille
}

