//
// Float issues, casting, rounding, working in cents...
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*  Canadian Coin Denominations
    Coin    $val    Cents
    ------- ------- -----------
    Toonie  $2.00   200
    Loonie  $1.00   100
    Quarter $0.25    25
    Dime    $0.10    10
    Nickel  $0.05     5
    Penny   $0.01     1
*/

int main(void)
{
    const double TAX = 0.13;
    double price = 17.97;
    int qty = 8;

    // Rounding... for handling inaccurate floating-point values!
    // Method-1:
    //int subTotal = ((price * qty) * 100) + 0.5;
    // Method-2:
    int subTotal = ((price * qty) + 0.005) * 100;

    double subTotalWrong = price * qty;
    int coins, remaining;

    printf("Product price     : $%.2lf\n", price);
    printf("Number of products: %d\n", qty);
    printf("Subtotal          : %d\n", subTotal);
    // 3 ways to get the same result: make just 1 of the operands
    //                                a double type (cast) and all
    //                                will become double!
    printf("Subtotal          : $%.2lf\n", (double)subTotal / 100);
    printf("Subtotal          : $%.4lf\n", subTotal / 100.0);
    //printf("Subtotal          : $%.4lf\n", subTotal / (double)100);

    // Quarters:
    coins = subTotal / 25;
    //remaining = subTotal - (coins * 25); // NO!!! bad!! Horse!
    remaining = subTotal % 25; // Use Modulus operator %!!!
    printf("Quarters: %d (Remaining: %d)\n", coins, remaining);
    printf("Quarters: %d (Remaining: $%.2lf)\n", coins, remaining/100.0);

    return 0;
}