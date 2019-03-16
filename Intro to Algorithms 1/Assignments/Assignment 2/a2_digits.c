/* Name: Denis Nadarevic
Date: October 20th, 2017
Description: Asks the user to enter a two-digit number and then prints the number with its digits reversed.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	/*user inputs the two-digit number, assigning the value to the inputNumber variable */
	int inputNumber, firstReverse, secondReverse;
	printf("Enter a two-digit number:\n");
	scanf("%d", &inputNumber); 
  
	firstReverse = inputNumber % 10; /*finds the second digit of the input number and assigns the value to the firstReverse variable */
	secondReverse = floor(inputNumber / 10); /*finds the first digit of the input number annd assigned the value to the secondReverse variable  */
  
	printf("The reverse of your two-digit number is %d%d.\n", firstReverse, secondReverse); /*outputs the reversed number of the user's input */
	return 0;
}