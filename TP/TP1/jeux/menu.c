/**
 * \file menu.c
 * \brief Menu affiché pour le jeux du plus moins
 * \author Léo Magadoux
 * \version 0.1
 * \date 20 mars 2023
 *
 * Les menus qui serviront à notre jeu
 *
 */

#include <stdio.h>

#include "main.h"

void menu_print_difficulty (void) {

    printf("######### Jeu du plus/moins #########\n\n");
    printf("Choisissez votre difficulté : \n");
    printf("    - 1 . Facile    (1-%d)\n",      DIFFICULTY_EASY_MAX_NUMBER);
    printf("    - 2 . Moyen     (1-%d)\n",      DIFFICULTY_AVERAGE_MAX_NUMBER);
    printf("    - 3 . Difficile (1-%d)\n",      DIFFICULTY_HARD_MAX_NUMBER);

    printf("\nVotre choix:");
}

void menu_print_play_again (void) {

    printf("\n");
    printf("######### Voulez-vous rejouer ? #########\n\n");
    printf("Choisissez : \n");
    printf("    - 1 . Oui\n");
    printf("    - 2 . Non\n");

    printf("\nVotre choix:");
}
