void liberer_jeu(Sokoban *jeu) // Libere la mémoire allouée pour le jeu
{
    for (int i = 0; i < TAILLE_GRILLE; i++) 
    {
        free(jeu->grille[i]); // Libère chaque ligne de la grille
    }

    free(jeu->grille); // Libère le tableau de pointeurs
}