/**
 * \file game.c
 * \brief Jeux du plus moins
 * \author Léo Magadoux
 * \version 0.1
 * \date 20 mars 2023
 *
 * Fonctions nécessaires au jeux du plus moins
 *
 */

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"

/**
 * \brief Symbole affiché quand l'utilisateur gagne.
 */
static void game_print_win(void) {

    printf("\n");
    printf("         _nnnn_                      \n");
    printf("        dGGGGMMb     ,\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n");
    printf("       @p~qp~~qMb    | C'est gagné! |\n");
    printf("       M|@||@) M|   _;..............'\n");
    printf("       @,----.JM| -');\n");
    printf("      JS^\\__/  qKL\n");
    printf("     dZP        qKRb\n");
    printf("    dZP          qKKb\n");
    printf("   fZP            SMMb\n");
    printf("   HZM            MMMM\n");
    printf("   FqM            MMMM\n");
    printf(" __| \".        |\\dS\"qML\n");
    printf(" |    `.       | `' \\Zq\n");
    printf("_)      \\.___.,|     .'\n");
    printf("\\____   )MMMMMM|   .'\n");
    printf("     `-'       `--' hjm\n");
    printf("\n");

}

/**
 * \brief Affiche les différentes valeurs données par l'utilisateur.
 *
 * \param choices Pointeur sur le tableaux des valeurs de l'utilisateur.
 * \param num_choices Nombre de choix
 */
static void game_print_choices(uint32_t * choices, uint32_t num_choices) {
    printf("\nVos choix : ");
    for(uint32_t i = 0; i < num_choices; i++) {
        printf("%u ", choices[i]);
    }
}

/**
 * \brief Fonction qui génère un nombre aléatoire en fonction de la difficulté.
 *
 * \param difficulty Difficulté du nombre
 * \return uint32_t le nombre aléatoire
 */
static uint32_t game_generate_random_number(int8_t difficulty) {
    uint32_t random_number;

    srand(time(NULL));

    switch (difficulty) {
        case 1:
            random_number = (uint32_t) rand() % DIFFICULTY_EASY_MAX_NUMBER;
        break;
        case 2:
            random_number = (uint32_t) rand() % DIFFICULTY_AVERAGE_MAX_NUMBER;
        break;
        case 3:
            random_number = (uint32_t) rand() % DIFFICULTY_HARD_MAX_NUMBER;
        break;
    }

    return random_number;
}

void game_start(int8_t difficulty) {
    bool win = false;
    uint32_t choice;
    uint32_t counter = 0;
    uint32_t number_to_find;
    uint32_t* choices = NULL; // Tab pointer to store all values enter by user
    uint32_t num_choices = 0; // Number of value stored

    // Get the random number
    number_to_find = game_generate_random_number(difficulty);

    // Tant que l'utilisateur n'a pas gagné
    while(!win) {
        counter++;

        printf("\nVotre numéro : ");

        scanf("%u", &choice);

        // Ajouter le choix de l'utilisateur au tableau dynamique
        num_choices++;
        choices = (uint32_t*) realloc(choices, num_choices * sizeof(uint32_t));
        choices[num_choices-1] = choice;

        // On donne la réponse en fonction du nombre choisi par l'utilisateur
        if(choice < number_to_find) {
            printf("\nC'est plus\n");
        } else if (choice > number_to_find) {
            printf("\nC'est moins\n");
        } else {
            game_print_win();
            game_print_choices(choices, num_choices);
            printf("\nNombre de coups : %u\n", counter);
            win = true;
        }

    }
	free(choices);
}
