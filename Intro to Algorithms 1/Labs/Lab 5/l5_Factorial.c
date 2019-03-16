/*
Name: Denis Nadarevic
Date: October 25th, 2017
Description: Computes the factorial of the user's inputted number.
*/
#include <stdio.h>

int main(void)
{
  int userInput, factorial = 1;
  /*Loops continuously, asking the user for a positive integer and output the factorial*/
  
  while(1)
  {
	printf("Enter a positive integer (or -ve integer to exit): ");
	scanf("%d", &userInput);
	/*If input is a negative integer, loop below breaks and outputs the final printf statement*/
	/*Checks to see if user's input is a positive integer or zero*/
    if (userInput < 0) {
      break;
    }
	while(userInput >= 0)
	{
		factorial = 1; 
		/*Computes the factorial*/
		for(int i = userInput; i > 1; i--) {
			factorial *= i; 
  	}
    /*Outputs the factorial of the user's input*/
  	printf(" factorial of %d is %d\n", userInput, factorial);
  	break;
	}
  }
printf("Thank you for using my software :)\n");
return 0;
}