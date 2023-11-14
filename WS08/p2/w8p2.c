/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num) {
	int val;
	int flag = 0;

	do {
		flag = 1;
		scanf("%d", &val);
		if (val <= 0) {
			flag = 0;
			printf("ERROR: Enter a positive value: ");
		}
	} while (!flag);

	if (num != NULL) {
		*num = val;
	}
	return val;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num) {
	double val;
	int flag = 0;

	do {
		flag = 1;
		scanf("%lf", &val);
		if (val <= 0) {
			flag = 0;
			printf("ERROR: Enter a positive value: ");
		}
	} while (!flag);

	if (num != NULL) {
		*num = val;
	}
	return val;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", SUGGESTED_SERVING);

	return;
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num) {
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequence_num);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&food.sku);

	printf("PRICE         : $");
	getDoublePositive(&food.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);

	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	return;
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs, double *kg){
	double val = (*lbs) / COVERSION_FACTOR;

	if (kg != NULL) {
		*kg = val;
	}

	return val;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs, int *g) {
	int val = convertLbsKg(lbs, NULL) * 1000;
	

	if (g != NULL) {
		*g = val;
	}

	return val;

}


// 10. convert lbs: kg and g
void convertLbs(const double *lbs, double *kg, int *g) {

	*kg = convertLbsKg(lbs, NULL);
	*g = convertLbsG(lbs, NULL);

}


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrams, double* numOfServings) {
	double val = (double)totalGrams / servingSize;

	if (numOfServings != NULL) {
		*numOfServings = val;
	}

	return val;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double price, const double numOfServings, double* costPerServing) {
	double val = (double)price / numOfServings;

	if (costPerServing != NULL) {
		*costPerServing = val;
	}

	return val;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* numOfCalories, double* costPerCal) {
	double val = (double)*price / *numOfCalories;

	if (costPerCal != NULL) {
		*costPerCal = val;
	}

	return val;
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo *catFood) {
	struct ReportData report;
	double totalCal = 0;

	report.sku = catFood->sku;
	report.price = catFood->price;
	report.calories = catFood->calories;
	report.weightLb = catFood->weight;

	convertLbsKg(&report.weightLb, &report.weightKg);
	convertLbsG(&report.weightLb, &report.weightG);

	calculateServings(SUGGESTED_SERVING, report.weightG, &report.numServings);
	calculateCostPerServing(report.price, report.numServings, &report.costPerServing);
	totalCal = report.numServings * report.calories;
	calculateCostPerCal(&report.price, &totalCal, &report.costCalPerServing);

	return report;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", SUGGESTED_SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int cheapest) {
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.sku, data.price, data.weightLb, data.weightKg, data.weightG, data.calories, data.numServings, data.costPerServing, data.costCalPerServing);
	
	if (cheapest == 0) {
		printf("\n");
	}
	else {
		printf(" ***\n");
	}
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestItem) {
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheapestItem.sku, cheapestItem.price);
	printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	openingMessage(MAX_NUM_PRODUCTS);

	struct CatFoodInfo cats[MAX_NUM_PRODUCTS] = { {0} };
	struct ReportData items[MAX_NUM_PRODUCTS] = { {0} };
	int i;
	int cheapest[MAX_NUM_PRODUCTS] = { 0 };
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		cats[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		displayCatFoodData(cats[i].sku, &cats[i].price, cats[i].calories, &cats[i].weight);
	}

	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		items[i] = calculateReportData(&cats[i]);
	}
	printf("\n");

	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		if (items[i].costCalPerServing < items[i+1].costCalPerServing) {
			cheapest[0] = 0;
			cheapest[1] = 0;
			cheapest[2] = 0;
			cheapest[i] = 1;
		}
	}

	displayReportHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		displayReportData(items[i], cheapest[i]);
	}
	
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		if (cheapest[i] == 1) {
			displayFinalAnalysis(cats[i]);
		}
	}
}
