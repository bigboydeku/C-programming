/* 
Name: Denis Nadarevic
Date: October 18th, 2017
Description: Computes the volume of a cylinder, with rules 
*/

#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main(void)
{
	int radius=5;
	float height, volume;


	while (1) /*Determines the volume, checking to see if input follows rules*/
	{
		printf("Enter height(0 to exit program): "); /*User inputs height value */
		scanf("%f", &height); /*Assigns value to height variable */
		
		if (height == 0) break; /*checks input to see if height is zero. If true, loop breaks. */
		
		else if ( height > radius ) /* checks to see if height is greater than radius; computes volume. */
		{
			volume = M_PI * pow(radius,2) * height;
			printf("The volume is %.2f.\n", volume); /*Computes final volume value. */
		}
		
		else
		{
			printf("Height has to be bigger than radius.\n");
		}
	}
	printf("Thank you for using my software.\n"); /* If height is zero, prints ending statement. */
	return 0;
}