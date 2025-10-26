#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"
#include <string.h>
#include <time.h>

int main() 
{
    /* Initialisation du générateur de nombres aléatoires pour les positions initiales
     * Utilise l'heure actuelle comme graine pour avoir des positions différentes
     * à chaque lancement du jeu
     */
    srand(time(NULL));

    /* Allocation dynamique de la structure principale du jeu
     * Cette structure contient :
     * - La grille de jeu
     * - Les positions du joueur (pos_x, pos_y)
     * - La position de l'objectif (pos_victoire_x, pos_victoire_y)
     * - L'état de fin de partie (fin)
     */
    Sokoban *jeu = malloc(sizeof(*jeu));

    /* Variables de contrôle pour la saisie utilisateur
     * choi : stocke le caractère de déplacement (z,q,s,d)
     * result : utilisée pour vérifier si la saisie est valide
     */
    char choi;
    char result;

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
            deplacement(jeu, choi); // Effectue le déplacement
            
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