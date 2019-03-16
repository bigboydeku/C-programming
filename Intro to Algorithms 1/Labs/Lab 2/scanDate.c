#include <stdio.h>

int main(void)
{
	int month, day, year;
	printf("Enter a date (dd-mm-yyyy): ");
	scanf("%d-%d-%d", &day, &month, &year);
	printf("This is the %dth day in the %dth month of %d.\n", day, month, year);
	return 0;
}