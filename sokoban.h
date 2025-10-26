#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__


#define TAILLE_GRILLE 10 // crée la constante TAILLE_GRILLE avec la valeur 10

struct s_sokoban {
    int** grille;       // Grille de jeu (0=vide, 1=caisse, 2=objectif, 3=joueur, 4=mur)
    int pos_x;          // Position X du joueur
    int pos_y;          // Position Y du joueur
    int pos_victoire_x; // Position X de l'objectif
    int pos_victoire_y; // Position Y de l'objectif
    int fin;           // État de fin de partie (0=en cours, 1=terminé)
};

typedef struct s_sokoban Sokoban;

// Fonctions de jeu (methodes touver sur redit)
void initialiser_jeu(Sokoban *jeu);  // Initialise la grille et les positions
void liberer_jeu(Sokoban *jeu);      // Libère la mémoire allouée
void affiche(Sokoban *jeu);          // Affiche l'état actuel de la grille
void deplassment(Sokoban *jeu, char choi);  // Gère le déplacement du joueur (z,q,s,d)
int verifier_defaite(Sokoban *jeu);   // Vérifie si une caisse est bloquée
void defaite(Sokoban *jeu);           // Gère la défaite (sauvegarde et message)
void victoir(Sokoban *jeu);           // Gère la victoire (sauvegarde et message)

void accueil(); // Affiche l'écran d'accueil

#endif 
