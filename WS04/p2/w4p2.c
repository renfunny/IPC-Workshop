/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Renato Cordova
Student ID#: 153325238
Email      : rcordova3@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages, pick, repeat = 1;
    //repear is 1, so this program will run unless it is changed to 0 by the user
    while (repeat) {
        //This sets everything to below 0 values so the next while loop can be executed
        apples = -1, oranges = -1, pears = -1, tomatoes = -1, cabbages = -1;
        printf("Grocery Shopping\n");
        printf("================\n");

        while (apples < 0) {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples >= 0) {
                printf("\n");
                break;
            }
            else { printf("ERROR: Value must be 0 or more.\n"); }
        }
        while (oranges < 0) {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges >= 0) {
                printf("\n");
                break;
            }
            else { printf("ERROR: Value must be 0 or more.\n"); }
        }
        while (pears < 0) {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears >= 0) {
                printf("\n");
                break;
            }
            else { printf("ERROR: Value must be 0 or more.\n"); }
        }
        while (tomatoes < 0) {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes >= 0) {
                printf("\n");
                break;
            }
            else { printf("ERROR: Value must be 0 or more.\n"); }
        }
        while (cabbages < 0) {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages >= 0) {
                printf("\n");
                break;
            }
            else { printf("ERROR: Value must be 0 or more.\n"); }
        }

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        while (apples > 0) {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > apples) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            }
            else if (pick < apples) {
                apples -= pick;
                printf("Looks like we still need some APPLES...\n");
            }
            else {
                apples -= pick;
                printf("Great, that's the apples done!\n\n");
            }

        }
        while (oranges > 0) {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > oranges) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            }
            else if (pick < oranges) {
                oranges -= pick;
                printf("Looks like we still need some ORANGES...\n");
            }
            else {
                oranges -= pick;
                printf("Great, that's the oranges done!\n\n");
            }

        }
        while (pears > 0) {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > pears) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            }
            else if (pick < pears) {
                pears -= pick;
                printf("Looks like we still need some PEARS...\n");
            }
            else {
                pears -= pick;
                printf("Great, that's the pears done!\n\n");
            }

        }
        while (tomatoes > 0) {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > tomatoes) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            }
            else if (pick < tomatoes) {
                tomatoes -= pick;
                printf("Looks like we still need some TOMATOES...\n");
            }
            else {
                tomatoes -= pick;
                printf("Great, that's the tomatoes done!\n\n");
            }

        }
        while (cabbages > 0) {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > cabbages) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            }
            else if (pick < cabbages) {
                cabbages -= pick;
                printf("Looks like we still need some CABBAGES...\n");
            }
            else {
                cabbages -= pick;
                printf("Great, that's the cabbages done!\n\n");
            }

        }
        printf("All the items are picked!\n\n");
        //If 0 is picked the parent while loop will end
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &repeat);
        printf("\n");
    }
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}