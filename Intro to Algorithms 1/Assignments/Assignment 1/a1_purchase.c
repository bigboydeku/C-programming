#include <stdio.h>

int main(void)
{
	int itemNumber, month, day, year;
	float unitPrice;
	
	printf("Enter item number:\n");
	scanf("%d", &itemNumber);
	
	printf("Enter unit price:\n");
	scanf("%f", &unitPrice);
	
	printf("Enter purchase date:\n");
	scanf("%d/%d/%d", &month, &day, &year);
	
	printf("\nItem Number\t\tUnit Price\t\tPurchase Date\n");
	printf("%d\t\t\t$ %3.2f\t\t\t%.2d/%.2d/%d\n\n", itemNumber, unitPrice, month, day, year);
	
	return 0;
}