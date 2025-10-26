#include <stdio.h>
#include "sokoban.h"
// 0 case vide 1 caisse 2 objectif 3 joueur 4 mur
void accueil(void) // Affiche l'écran d'accueil
{
    printf("\n==============================\n");
    printf("      Bienvenue dans Sokoban !\n");
    printf("==============================\n");
    printf("objectif : pousser la caisse (X) sur l'objectif (.)\n");
    printf("un readme est disponible pour plus d'informations.\n");
    printf("\nUtilisez z (haut), s (bas), q (gauche), d (droite) pour déplacer le joueur.\n");
    printf("Appuyez sur Entrée pour commencer...\n");
    getchar(); // Attend que l'utilisateur appuie sur Entrée (trouver sur redit)
}

void affiche(Sokoban *jeu) // fonction qui affiche la map
{
    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        for (int j = 0; j < TAILLE_GRILLE; j++)
        {
            char carac; // variable pour stocker le caractere a afficher
            if (jeu->grille[i][j] == 1) // si la case contient une caisse
                {
                carac = 'X';
            }
            else if (jeu->grille[i][j] == 2) // si la case contient l'objectif
                {
                carac = '.';
            }
            else if (jeu->grille[i][j] == 3) // si la case contient le joueur
                {
                carac = 'O';
            }
            else if (jeu->grille[i][j] == 4) // si la case contient un mur
                {
                carac = '#';
            }
            else // si la case est vide
                {
                carac = ' ';
            }
            printf(" %c ", carac); // affiche le caractere avec des espaces autour
        }
        printf("\n"); // saut de ligne apres chaque ligne de la map
    }
    printf("\n" ); // saut de ligne apres l'affichage
}
