/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Renato Cordova
Student ID#: 153325238
Email      : rcordova3@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int count, i;
    char typeOfIteration;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &typeOfIteration, &count);

        if (typeOfIteration == 'Q' && count == 0) {
            printf("\n+--------------------+\n");
            printf("Loop application ENDED\n");
            printf("+--------------------+\n");
            break;
        } else if (typeOfIteration == 'Q'){
            printf("ERROR: To quit, the number of iterations should be 0!\n");
        }
        else {
            switch (typeOfIteration) {
            case 'D':
            {
                if (count >= 3 && count <= 20) {
                    printf("DO-WHILE: ");
                    do {
                        count--;
                        printf("D");
                    } while (count > 0);
                    printf("\n");
                }
                else {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
                break;
            }
            case 'W':
            {
                if (count >= 3 && count <= 20) {
                    printf("WHILE   : ");
                    while (count > 0) {
                        count--;
                        printf("W");
                    }
                    printf("\n");
                }
                else {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
                break;
            }
            case 'F':
            {
                if (count >= 3 && count <= 20) {
                    printf("FOR     : ");
                    for (i = count; i > 0; i--) {
                        printf("F");
                    }
                    printf("\n");
                }
                else {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                }
                break;
            }
            default:
                printf("ERROR: Invalid entered value(s)!\n");

            }

        }
    } while (1);
    
    return 0;
}