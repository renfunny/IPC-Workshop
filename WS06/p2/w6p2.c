/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

#define MIN_MONTHLY_INCOME 500.00
#define MAX_MONTHLY_INCOME 400000.00
#define MIN_WISH_ITEMS 1
#define MAX_WISH_ITEMS 10
#define MIN_COST 100.00
#define MIN_PRIORITY 1
#define MAX_PRIORITY 3
#define Y_FINANCE 'y'
#define N_FINANCE 'n'

int main(void)
{
    double netIncome = 0, totalCost = 0, priorityTotalCost= 0;
	int valid = 0, wishItems = 0, i, menuSelection, financialOption=0, years=0, months=0, totalMonths = 0, prioritySelection;
	double cost[MAX_WISH_ITEMS];
	int priority[MAX_WISH_ITEMS];
	char finance[MAX_WISH_ITEMS];

		printf("+--------------------------+\n");
		printf("+   Wish List Forecaster   |\n");
		printf("+--------------------------+\n\n");

	do{
		valid = 1;
		printf("Enter your monthly NET income: $");
		scanf("%lf", &netIncome);

		if(netIncome <= MIN_MONTHLY_INCOME){
			valid = 0;
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_MONTHLY_INCOME);
		} 
		if(netIncome > MAX_MONTHLY_INCOME){
			valid = 0;
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_MONTHLY_INCOME);
		}


	} while(!valid);

	printf("\n");

	do{
		valid = 1;
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &wishItems);

		if(wishItems < MIN_WISH_ITEMS || wishItems > MAX_WISH_ITEMS){
			valid = 0;
			printf("ERROR: List is restricted to between %d and %d items.\n\n", MIN_WISH_ITEMS, MAX_WISH_ITEMS);
		}

	} while (!valid);

	for(i = 0; i < wishItems; i++){
		printf("\nItem-%d Details:\n", i+1);

		do{
			valid = 1;
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			if(cost[i]<MIN_COST){
				valid = 0;
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
			}
		} while(!valid);

		do{
			valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if(priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY){
				valid = 0;
				printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
			}
		} while(!valid);

		do{
			valid = 0;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);

			if(finance[i] == Y_FINANCE || finance[i] == N_FINANCE){
				valid = 1;
			} else{
			printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while(!valid);

		totalCost += cost[i];

	}

	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for(i = 0; i < wishItems; i++){
		printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i], finance[i], cost[i]);
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", totalCost);

    do{
        valid = 1;
        printf("\n");
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &menuSelection);

        switch(menuSelection){
        case 0:
            printf("\nBest of luck in all your future endeavours!\n");
            break;
        case 1:
            totalMonths = totalCost / netIncome;
            years = totalMonths / 12;
            months = totalMonths % 12;

            valid = 0;
            financialOption = 0;
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            printf("Forecast: %d years, %d months\n", years, months+1);
            for(i=0;i<wishItems;i++){
                if(finance[i] == Y_FINANCE){
                    financialOption = 1;
                }
            }
            if(financialOption == 1){
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            break;
        case 2:
            valid = 0;
            financialOption = 0;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &prioritySelection);
            if(prioritySelection < MIN_PRIORITY || prioritySelection > MAX_PRIORITY){
                printf("ERROR: Value must be between %d and %d\n\n", MIN_PRIORITY, MAX_PRIORITY);
            } else{
                    for(i=0;i<wishItems;i++){
                        if(priority[i] == prioritySelection){
                            priorityTotalCost += cost[i];
                            if(finance[i] == Y_FINANCE){
                                financialOption = 1;
                            }
                        }
                    }
                    totalMonths = priorityTotalCost / netIncome;
                    years = totalMonths / 12;
                    months = totalMonths % 12;
                    printf("\n====================================================\n");
                    printf("Filter:   by priority (%d)\n", prioritySelection);
                    printf("Amount:   $%1.2lf\n", priorityTotalCost);
                    printf("Forecast: %d years, %d months\n", years, months+1);
                 
                    if(financialOption == 1){
                      printf("NOTE: Financing options are available on some items.\n");
                      printf("      You can likely reduce the estimated months.\n");
                     }
                     printf("====================================================\n");
                     priorityTotalCost = 0;
            }
            break;
            default:
            valid = 0;
            printf("\nERROR: Invalid menu selection.\n");
            break;

    }

    } while(!valid);

    return 0;
}