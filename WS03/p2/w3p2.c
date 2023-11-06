/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    int coffeeWeight1, coffeeWeight2, coffeeWeight3, dailyServings;
    char coffeeType1, coffeeType2, coffeeType3, creamSuggested1, creamSuggested2, creamSuggested3, coffeeStrength, withCream;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich):");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight1);
    printf("Best served with cream ([Y]es,[N]o):");
    scanf(" %c", &creamSuggested1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich):");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight2);
    printf("Best served with cream ([Y]es,[N]o):");
    scanf(" %c", &creamSuggested2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich):");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight3);
    printf("Best served with cream ([Y]es,[N]o):");
    scanf(" %c", &creamSuggested3);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffeeType1 == 'l' || coffeeType1 == 'L', coffeeType1 == 'm' || coffeeType1 == 'M', coffeeType1 == 'r' || coffeeType1 == 'R', coffeeWeight1, coffeeWeight1 / GRAMS_IN_LBS, creamSuggested1 == 'y' || creamSuggested1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffeeType2 == 'l' || coffeeType2 == 'L', coffeeType2 == 'm' || coffeeType2 == 'M', coffeeType2 == 'r' || coffeeType2 == 'R', coffeeWeight2, coffeeWeight2 / GRAMS_IN_LBS, creamSuggested2 == 'y' || creamSuggested2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffeeType3 == 'l' || coffeeType3 == 'L', coffeeType3 == 'm' || coffeeType3 == 'M', coffeeType3 == 'r' || coffeeType3 == 'R', coffeeWeight3, coffeeWeight3 / GRAMS_IN_LBS, creamSuggested3 == 'y' || creamSuggested3 == 'Y');
    
    printf("\nEnter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich):");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o):");
    scanf(" %c", &withCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", coffeeStrength == 'l' || coffeeStrength == 'L', dailyServings >= 1 && dailyServings <= 4, withCream == 'y' || withCream == 'Y');
    printf(" 2|       %d         |      %d      |   %d   |\n", coffeeStrength == 'r' || coffeeStrength == 'R', dailyServings >= 5 && dailyServings <= 9, withCream == 'n' || withCream == 'N');
    printf(" 3|       %d         |      %d      |   %d   |\n", coffeeStrength == 'm' || coffeeStrength == 'M', dailyServings >= 10, withCream == 'n' || withCream == 'N');


    printf("\nEnter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich):");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o):");
    scanf(" %c", &withCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServings);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", coffeeStrength == 'l' || coffeeStrength == 'L', dailyServings >= 1 && dailyServings <= 4, withCream == 'y' || withCream == 'Y');
    printf(" 2|       %d         |      %d      |   %d   |\n", coffeeStrength == 'r' || coffeeStrength == 'R', dailyServings >= 5 && dailyServings <= 9, withCream == 'n' || withCream == 'N' );
    printf(" 3|       %d         |      %d      |   %d   |\n\n", coffeeStrength == 'm' || coffeeStrength == 'M', dailyServings >= 10, withCream == 'n' || withCream == 'N');

    printf("Hope you found a product that suits your likes!\n");
    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/
