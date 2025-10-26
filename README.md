# Projet Sokoban en C

## Description
Une implémentation du célèbre jeu de réflexion Sokoban en C, jouable dans le terminal. Le but du jeu est de pousser une caisse jusqu'à un emplacement marqué tout en évitant de la bloquer contre les murs.

## Caractéristiques
- Plateau de jeu 10x10
- Génération aléatoire des positions initiales (joueur, caisse, objectif)
- Système de détection de victoire et de défaite
- Sauvegarde de l'état final dans un fichier
- Interface en mode texte dans le terminal

## Prérequis
- Compilateur GCC
- Terminal supportant l'affichage texte
- Système d'exploitation : Windows/Linux/MacOS

## Installation

1. Clonez le repository :
```bash
git clone https://github.com/FamilyTsuki/coda-bnv-sokoban.git
cd coda-bnv-sokoban
```

2. Compilez le jeu :
```bash
gcc -Wall -Wextra *.c -o sokoban
```

## Comment jouer

1. Lancez le jeu :
```bash
./sokoban
```

2. Contrôles :
- `z` : Déplacer vers le haut
- `s` : Déplacer vers le bas
- `q` : Déplacer vers la gauche
- `d` : Déplacer vers la droite

3. Symboles du jeu :
- `o` : Joueur
- `X` : Caisse
- `.` : Objectif
- `#` : Mur
- ` ` : Case vide

## Règles du jeu
1. Vous contrôlez un personnage qui peut se déplacer dans les quatre directions
2. Le but est de pousser la caisse jusqu'à l'emplacement marqué
3. Vous ne pouvez que pousser la caisse, pas la tirer
4. La partie est gagnée quand la caisse arrive sur l'objectif
5. La partie est perdue si la caisse est bloquée (contre un mur ou dans un coin)

## Structure du projet
- `main.c` : Programme principal
- `sokoban.h` : Définitions et prototypes
- `init.c` : Initialisation du jeu et de la grille
- `dep.c` : Gestion des déplacements
- `affichage.c` : Affichage du plateau
- `victoire.c` : Gestion de la victoire
- `defaite.c` : Gestion de la défaite
- `verifi_defait.c` : Vérification des conditions de défaite
- `end.txt` : Fichier de sauvegarde de l'état final

## Sauvegarde
- L'état final de chaque partie (victoire ou défaite) est automatiquement sauvegardé dans le fichier `end.txt`
- Le fichier est écrasé à chaque nouvelle fin de partie

## Contribution
1. Fork le projet
2. Créez une nouvelle branche (`git checkout -b feature/amelioration`)
3. Committez vos changements (`git commit -am 'Ajout d'une nouvelle fonctionnalité'`)
4. Push vers la branche (`git push origin feature/amelioration`)
5. Créez une Pull Request

## License
Ce projet est sous licence CC BY-NC-SA 4.0

## Auteur
FamilyTsuki

## Remerciements
- Merci d'avoir pris le temp de lire :P
- Projet réalisé dans le cadre du cours de programmation CODA BNV 2025
- Inspiré du jeu original Sokoban créé par Hiroyuki Imabayashi
