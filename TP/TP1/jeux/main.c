/**
 * \file main.c
 * \brief Jeux du plus moins
 * \author Léo Magadoux
 * \version 0.1
 * \date 20 mars 2023
 *
 * Jeux du plus moins
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "menu.h"
#include "game.h"

int main (void) {
    uint8_t difficulty;
    uint8_t startAgain;
    bool boolStartGameAgain = true;

    // On lance le jeu temps que l'utilisateur veut continuer
    while (boolStartGameAgain) {
        // L'utilisateur choisit la difficulté
        menu_print_difficulty();
        scanf("%hhu", &difficulty);

        // Lancement du jeu
        game_start(difficulty);

        // On demande à l'utilisateur si il veut rejouer
        menu_print_play_again();
        scanf("%hhu", &startAgain);

        if(startAgain == 2) {
            boolStartGameAgain = false;
        }
    }

    return 0;
}
