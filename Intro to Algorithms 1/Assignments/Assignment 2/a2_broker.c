/* Name: Denis Nadarevic
Date: October 20th, 2017
Description: Calculates the commission given to a broker and their rival 
*/
#include <stdio.h>


int main(void)
{
	float shares, commission, value, rivalCommission, price;
  
/* assigns the user's input of the number of shares and price per share */
	printf("Enter the number of shares: ");
	scanf("%f", &shares);
	printf("Enter the price per share: ");
	scanf("%f", &price);
  
	value = shares * price; /* Calculates the value of the trade*/

/*Determines what amount of commission to give to the original broker*/
	if (value < 2500.00f)
		commission = 30.00f + .017 * value;
	else if (value < 6250.00f)
		commission = 56.00f + 0.0066 * value;
	else if (value < 20000.00f)
		commission = 76.00f + 0.0034 * value;
	else if (value < 50000.00f)
		commission = 100.00f + 0.0022 * value;
	else if (value < 500000.00f)
		commission = 155.00f + 0.0011 * value;
	else
		commission = 255.00f + 0.0009 * value;

/*Checks to see if the value goes below $39*/
	if (value < 39.00f)
		commission = 39.00f; 
  
	printf("Original broker's commission: $%.2f\n", commission);
/*Using conditional operators, it determines the amount of commission that the rival broker receives*/
	shares < 2000.00f?  (rivalCommission = 33.00f + 0.03 * shares) : (rivalCommission = 33.00f + 0.02 * shares);

	printf("Rival broker's commission: $%.2f\n\n", rivalCommission);
	return 0;
}