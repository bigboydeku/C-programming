
/*
Name: Denis Nadarevic
Date: November 2nd, 2017
Description: Computes the reverse of a number inputted by the user 
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
  int userInput, reverse, rem, i;
  /*Constantly runs the code, asking the user for a number*/
  printf("Enter a number: ");
  scanf("%d", &userInput);
  /*Checks to see if the user's input is less than 100 and greater than 0; if so, program outputs the following statement  */
  if (userInput <= 99 && userInput > 0)
  {
    printf("No need to reverse the number.\n");
    return 0;
  }
  /*Checks to see if the user's input is negative; if so, program says that the input is invalid*/
  else if(userInput < 0)
  {
    printf("Invalid input.\n");
    return 0;
  }
  else {
    i = userInput;
    reverse = 0;
    rem = 0;
    /* Computes the reverse until the i variable is reduced to 0; Once completed, program prints out the reverse-34543 */
    do {
      rem = i % 10;
      reverse = reverse*10 + rem;
      i /= 10;
    } while ( i > 0);
    printf("The reverse is: %d\n", reverse);
  }
  return 0;
}

