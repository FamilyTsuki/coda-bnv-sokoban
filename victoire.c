#include <stdio.h>
#include "sokoban.h"

void victoir(Sokoban *jeu) // Gère la victoire
{
    
    jeu->fin = 1; // Marque la fin de la partie
    affichagee(jeu);
    
    printf("Vous avez gagner !\n"); // message de victoire

    FILE *fp = fopen("end.txt", "w+");// Sauvegarde de la grille dans 'defaite.txt' (meme format que la sauvegarde de victoire)

    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        for (int j = 0; j < TAILLE_GRILLE; j++) 
        {
            char carac; // variable pour stocker le caractere a sauvegarder
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
            fprintf(fp, " %c ", carac); // écrit le caractere avec des espaces autour dans le fichier
        }
        fprintf(fp, "\n"); // saut de ligne apres chaque ligne de la map
    }
    fprintf(fp, "\n"); // saut de ligne apres l'enregistrement de la map
    fclose(fp); // Ferme le fichier 'end.txt'
}
