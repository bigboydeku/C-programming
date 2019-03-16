#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main(void)
{
	float radius, height, volume;
	float total;
	printf("Enter radius and height (r,h): ");
	scanf("%f,%f", &radius, &height);
	
	if ( radius >= height )
	{
		printf("Radius must be smaller than height.");
	}
	
	else if ( radius < 2 )
	{
	    	printf("Radius can't be smaller than 2.");
	}
	else
	{
	    total = pow(radius,2);
	    volume = M_PI * total * height;
	    printf("The volume is %.2f.", volume);
	}
}