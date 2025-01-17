/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_PATH 70
#define MIN_PATH 10
#define MAX_MOVES 15
#define MIN_MOVES 3

struct PlayerInfo {
    int numLives;
    char characterSymbol;
    int numTreasure;
    int positions[MAX_PATH];
};

struct GameInfo {
    int maxNumMoves;
    int pathLength;
    int bombs[MAX_PATH];
    int treasure[MAX_PATH];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;
    int valid = 0, i, nextMove = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.characterSymbol);

    do {
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.numLives);

        if (player.numLives < MIN_LIVES || player.numLives > MAX_LIVES) {
            valid = 0;
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
    } while (!valid);

    player.numTreasure = 0;

    for (i = 0; i < MAX_PATH; i++) {
        player.positions[i] = 0;
    }

    printf("Player configuration set-up is complete\n");
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        valid = 1;
        printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH, MAX_PATH);
        scanf("%d", &game.pathLength);

        if (game.pathLength < MIN_PATH || game.pathLength > MAX_PATH || game.pathLength % 5 != 0) {
            valid = 0;
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH, MAX_PATH);
        }
    } while (!valid);

    do {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxNumMoves);

        if (game.maxNumMoves < MIN_MOVES || game.maxNumMoves > MAX_MOVES) {
            valid = 0;
            printf("    Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
        }
    } while (!valid);

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }

    printf("BOMB placement set\n");
    printf("\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");

    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.characterSymbol);
    printf("   Lives      : %d\n", player.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasure[i]);
    }
    printf("\n");
    printf("\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    do {

        if (nextMove != 0) {
            printf(" ");
            for (i = 0; i < nextMove; i++) {      
                printf(" ");
                }
            printf("%c", player.characterSymbol);
        }
        printf("\n");

        printf("  ");
        for (i = 1; i <= game.pathLength; i++) {
            if (player.positions[i - 1] == 0) {
                printf("-");
            }
            else if (game.bombs[i - 1] == 1 && game.treasure[i - 1] == 1) {
                printf("&");
            }
            else if (game.bombs[i - 1] == 1) {
                printf("!");
            }
            else if (game.treasure[i - 1] == 1) {
                printf("$");
            }
            else {
                printf(".");
            }
        }
        printf("\n");

        printf("  ");
        for (i = 1; i <= game.pathLength; i++) {
            if (i % 10 == 0 ) {
                printf("%d", i / 10);
            }
            else {
                printf("|");
            }
        }
        printf("\n");

        printf("  ");
        for (i = 1; i <= game.pathLength; i++) {
            if (i > 9) {
                printf("%d", i % 10);
            }
            else {
                printf("%d", i);
            }
        }
        printf("\n");

        printf("+---------------------------------------------------+\n"); 
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numLives, player.numTreasure, game.maxNumMoves);
        printf("+---------------------------------------------------+\n");

            do {
                valid = 1;
                printf("Next Move [1-%d]: ", game.pathLength);
                scanf("%d", &nextMove);

                if (nextMove < 1 || nextMove > game.pathLength) {
                    valid = 0;
                    printf("  Out of Range!!!\n");
                }
            } while (!valid);

        if (player.positions[nextMove - 1] == 1) {
            printf("\n===============> Dope! You've been here before!\n\n");
        } 
        else if (game.bombs[nextMove - 1] == 1 && game.treasure[nextMove-1] == 1) {
            game.maxNumMoves--;
            player.numTreasure++;
            player.numLives--;
            printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
        }
        else if (game.bombs[nextMove - 1] == 1) {
            game.maxNumMoves--;
            player.numLives--;
            printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
        }
        else if (game.treasure[nextMove - 1] == 1) {
            game.maxNumMoves--;
            player.numTreasure++;
            printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
        }
        else {
            game.maxNumMoves--;
            printf("\n===============> [.] ...Nothing found here... [.]\n\n");
        }
        player.positions[nextMove - 1] = 1;

        if (player.numLives == 0) {
            printf("No more LIVES remaining!\n\n");
    }
        if (game.maxNumMoves == 0) {
            printf("No more MOVES remaining!\n\n");

        }
    } while (player.numLives != 0 && game.maxNumMoves != 0);

    printf(" ");
    for (i = 0; i < nextMove; i++) {
        printf(" ");
    }
    printf("%c", player.characterSymbol);
    printf("\n");

    printf("  ");
    for (i = 1; i <= game.pathLength; i++) {
        if (player.positions[i - 1] == 0) {
            printf("-");
        }
        else if (game.bombs[i - 1] == 1 && game.treasure[i - 1] == 1) {
            printf("&");
        }
        else if (game.bombs[i - 1] == 1) {
            printf("!");
        }
        else if (game.treasure[i - 1] == 1) {
            printf("$");
        }
        else {
            printf(".");
        }
    }
    printf("\n");

    printf("  ");
    for (i = 1; i <= game.pathLength; i++) {
        if (i % 10 == 0) {
            printf("%d", i / 10);
        }
        else {
            printf("|");
        }
    }
    printf("\n");

    printf("  ");
    for (i = 1; i <= game.pathLength; i++) {
        if (i > 9) {
            printf("%d", i % 10);
        }
        else {
            printf("%d", i);
        }
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numLives, player.numTreasure, game.maxNumMoves);
    printf("+---------------------------------------------------+\n\n");

    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}