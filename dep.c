#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

void deplacement(Sokoban *jeu, char choi) // Gère le déplacement du joueur
{
    if (choi == 'z') // le joueur veut aller en haut
    {
        if (jeu->grille[jeu->pos_x-1][jeu->pos_y] == 0)  // case viser est vide
        {
            jeu->grille[jeu->pos_x-1][jeu->pos_y] = 3; // deplace le joueur
            jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
            jeu->pos_x--; // met a jour la variable position x du joueur
        }
        else if (jeu->grille[jeu->pos_x-1][jeu->pos_y] == 1) // case visée contient une caisse
        {
            if (jeu->pos_x-2 >= 0 && (jeu->grille[jeu->pos_x-2][jeu->pos_y] == 0 || jeu->grille[jeu->pos_x-2][jeu->pos_y] == 2)) // case derriere la caisse est vide ou un objectif
            {
                jeu->grille[jeu->pos_x-2][jeu->pos_y] = 1; // deplace la caisse
                jeu->grille[jeu->pos_x-1][jeu->pos_y] = 3; // deplace le joueur
                jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
                jeu->pos_x--; // met a jour la variable position x du joueur
            }
        }
    }
    else if (choi == 's') // le joueur veut aller en bas
    {
        if (jeu->grille[jeu->pos_x+1][jeu->pos_y] == 0) // case viser est vide
        {
            jeu->grille[jeu->pos_x+1][jeu->pos_y] = 3;// deplace le joueur
            jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
            jeu->pos_x++; // met a jour la variable position x du joueur
        }
        else if (jeu->grille[jeu->pos_x+1][jeu->pos_y] == 1) // case visée contient une caisse
        {
            if (jeu->pos_x+2 < TAILLE_GRILLE && (jeu->grille[jeu->pos_x+2][jeu->pos_y] == 0 || jeu->grille[jeu->pos_x+2][jeu->pos_y] == 2)) // case derriere la caisse est vide ou un objectif
            {
                jeu->grille[jeu->pos_x+2][jeu->pos_y] = 1; // deplace la caisse
                jeu->grille[jeu->pos_x+1][jeu->pos_y] = 3; // deplace le joueur
                jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
                jeu->pos_x++; // met a jour la variable position x du joueur
            }
        }
    }
    else if (choi == 'q') // le joueur veut aller a gauche
    {
        if (jeu->grille[jeu->pos_x][jeu->pos_y-1] == 0) // case viser est vide
        {
            jeu->grille[jeu->pos_x][jeu->pos_y-1] = 3; // deplace le joueur
            jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
            jeu->pos_y--;
        }
        else if (jeu->grille[jeu->pos_x][jeu->pos_y-1] == 1) // case visée contient une caisse
        {
            if (jeu->pos_y-2 >= 0 && (jeu->grille[jeu->pos_x][jeu->pos_y-2] == 0 || jeu->grille[jeu->pos_x][jeu->pos_y-2] == 2)) // case derriere la caisse est vide ou un objectif
            {
                jeu->grille[jeu->pos_x][jeu->pos_y-2] = 1; // deplace la caisse
                jeu->grille[jeu->pos_x][jeu->pos_y-1] = 3; // deplace le joueur
                jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
                jeu->pos_y--; // met a jour la variable position y du joueur
            }
        }
    }
    else if (choi == 'd') // le joueur veut aller a droite
    {
        if (jeu->grille[jeu->pos_x][jeu->pos_y+1] == 0) // case viser est vide
        {
            jeu->grille[jeu->pos_x][jeu->pos_y+1] = 3; // deplace le joueur
            jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
            jeu->pos_y++; // met a jour la variable position y du joueur
        }
        else if (jeu->grille[jeu->pos_x][jeu->pos_y+1] == 1) // case visée contient une caisse
        {
            if (jeu->pos_y+2 < TAILLE_GRILLE && (jeu->grille[jeu->pos_x][jeu->pos_y+2] == 0 || jeu->grille[jeu->pos_x][jeu->pos_y+2] == 2)) // case derriere la caisse est vide ou un objectif
            {
                jeu->grille[jeu->pos_x][jeu->pos_y+2] = 1; // deplace la caisse
                jeu->grille[jeu->pos_x][jeu->pos_y+1] = 3; // deplace le joueur
                jeu->grille[jeu->pos_x][jeu->pos_y] = 0; // vide l'ancienne position du joueur
                jeu->pos_y++; // met a jour la variable position y du joueur
            }
        }
    }
    else // commande invalide
    {
        printf("Commande invalide. Utilisez 'z', 's', 'q' ou 'd'. \n");
    }

    
    int perdu = verifier_defaite(jeu); // Après chaque déplacement (ou tentative), vérifier si la partie est perdue
    if (perdu > 0) // si une caisse est bloquée
    {
        defaite(jeu); // Gère la défaite
    }
    if(jeu->grille[jeu->pos_victoire_x][jeu->pos_victoire_y] == 1) // Vérifie la condition de victoire
        {
            victoire(jeu); // Gère la victoire
        }

}




