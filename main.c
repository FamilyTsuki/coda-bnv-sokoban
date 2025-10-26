#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"
#include <string.h>

int main() // Fonction principale du Sokoban
{
    Sokoban *jeu = malloc(sizeof(*jeu)); // Allocation de la structure de jeu
    char choi; // variable pour stocker le choix du joueur
    char result; // variable pour stocker le résultat de scanf utiliser pour verifier les entrées utilisateur

    accueil(); // Affiche l'écran d'accueil
    initialiser_jeu(jeu); // Initialise le jeu
    system("clear"); // Nettoie le terminal (Linux/macOS)
    affiche(jeu); // Affiche l'état initial de la grille
    while (jeu->fin != 1) // boucle principale du jeu
    {
        printf("deplacement (z,s,q,d) : ");
        result = scanf("%c", &choi); // Lit le choix du joueur
        if (result != 1) // Vérifie si l'entrée est valide
        { 
            printf("Entrée invalide, veuillez saisir un caractère.\n");
            while (getchar() != '\n'); // vide le buffer
            continue; // retourne au début de la boucle
        }
        else // Si l'entrée est valide
        {
            deplassment(jeu, choi); // Effectue le déplacement
            
            for(int i = 0; i < 10; i++) 
            {
                for(int j = 0; j < 10; j++) 
                {
                    if(jeu->grille[i][j] == 3)  // Trouve la position du joueur
                    {
                        jeu->pos_x = i; // met a jour la variable position x du joueur
                        jeu->pos_y = j; // met a jour la variable position y du joueur
                    }
                }
            }
            if (jeu->fin == 1) // Vérifie si la partie est terminée
            {
                break;
            }
            system("clear"); // Nettoie le terminal à chaque tour
            affiche(jeu); // Affiche la grille après le déplacement
        }
    }
    liberer_jeu(jeu); // Libère la mémoire allouée pour le jeu
    free(jeu); // Libère la structure de jeu
    exit(0); 
}