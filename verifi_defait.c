#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

int verifier_defaite(Sokoban *jeu) // verifie que la caisse n'est pas softlockée
{
    int block = 0; // nombre de blockage
    for (int i = 1; i < TAILLE_GRILLE-1; i++) {
        for (int j = 1; j < TAILLE_GRILLE-1; j++) {
            if (jeu->grille[i][j] != 1) // si la case ne contient pas une caisse
            {
                continue; // passe a la case suivante
            }

            if (i == jeu->pos_victoire_x && j == jeu->pos_victoire_y) // si la caisse est sur l'objectif (utille si il y a plus de une caisse)
            {
                continue; // passe a la case suivante
            }

            // Vérifie les coins (blocage absolu)
            if ((jeu->grille[i-1][j] == 4 && jeu->grille[i][j-1] == 4) || // Haut-Gauche
                (jeu->grille[i-1][j] == 4 && jeu->grille[i][j+1] == 4) || // Haut-Droite
                (jeu->grille[i+1][j] == 4 && jeu->grille[i][j-1] == 4) || // Bas-Gauche
                (jeu->grille[i+1][j] == 4 && jeu->grille[i][j+1] == 4))   // Bas-Droite
            {
                block++; // Incrémente le compteur de blocages
            }
            // Vérifie si la caisse est contre un mur avec l'objectif de l'autre côté
            else if (
                // Si caisse contre mur gauche et objectif à droite
                (jeu->grille[i][j-1] == 4 && j < jeu->pos_victoire_y) ||
                // Si caisse contre mur droit et objectif à gauche
                (jeu->grille[i][j+1] == 4 && j > jeu->pos_victoire_y) ||
                // Si caisse contre mur haut et objectif en bas
                (jeu->grille[i-1][j] == 4 && i < jeu->pos_victoire_x) ||
                // Si caisse contre mur bas et objectif en haut
                (jeu->grille[i+1][j] == 4 && i > jeu->pos_victoire_x)
            ) {
                block++; // Incrémente le compteur de blocages
            }
        }       
    }
    return block; // Retourne le nombre de blocages trouvés
}
