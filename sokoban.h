#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__


#define TAILLE_GRILLE 10 // crée la constante TAILLE_GRILLE avec la valeur 10

struct s_sokoban {
    /* Grille de jeu représentée par un tableau 2D
     * Les valeurs possibles sont :
     * 0 : Case vide
     * 1 : Caisse
     * 2 : Objectif (destination de la caisse)
     * 3 : Joueur
     * 4 : Mur
     */
    int** grille;

    /* Position actuelle du joueur
     * pos_x : Ligne (0 à TAILLE_GRILLE-1)
     * pos_y : Colonne (0 à TAILLE_GRILLE-1)
     */
    int pos_x;
    int pos_y;

    /* Position de l'objectif où la caisse doit être poussée
     * pos_victoire_x : Ligne de l'objectif
     * pos_victoire_y : Colonne de l'objectif
     */
    int pos_victoire_x;
    int pos_victoire_y;

    /* État de la partie
     * 0 : Partie en cours
     * 1 : Partie terminée (victoire ou défaite)
     */
    int fin;
};

typedef struct s_sokoban Sokoban;

// Fonctions de jeu (methodes touver sur redit)
void initialiser_jeu(Sokoban *jeu);  // Initialise la grille et les positions
void liberer_jeu(Sokoban *jeu);      // Libère la mémoire allouée
void affiche(Sokoban *jeu);          // Affiche l'état actuel de la grille
void deplacement(Sokoban *jeu, char choix);  // Gère le déplacement du joueur (z,q,s,d)
int verifier_defaite(Sokoban *jeu);   // Vérifie si une caisse est bloquée
void defaite(Sokoban *jeu);           // Gère la défaite (sauvegarde et message)
void victoire(Sokoban *jeu);           // Gère la victoire (sauvegarde et message)

void accueil(); // Affiche l'écran d'accueil

#endif 
