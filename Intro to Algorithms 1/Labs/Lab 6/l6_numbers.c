/*
Name: Denis Nadarevic
Date: November 4th 2017
Description: Takes in one integer n between 2 and 9 as input from the user and prints n lines
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int userInput, n, randNum, i, great, above;
  time_t t;
  printf("Enter a number between 2 and 9: "); /*Asks user to input a number between 2 and 9*/
  scanf("%d", &userInput);
  
  /*starts random number generator*/
  srand((unsigned) time(&t));
 
 n = userInput;
 for(; n > 0 ; --n) { /*Loops this block of code n times, equal to the number inputted by the user*/
   randNum = rand() % 8 + 2; /*Assign the randNum variable with a random number between 2 and 9*/
   if (randNum <= 4){ /*Checks to see the randNum variable is below or equal to 4*/
     printf("%d: ", randNum);
     for (i = randNum - 1 ; i > 0 ; --i ) { /*prints the numbers for all Rk less than or equal to 4*/
        printf("%d", userInput);
       }
       printf("\n");
   }
   else { /* If the randNum variable has a number greater than 4, this code runs*/
     printf("%d:", randNum); 
     for (above = randNum; above > 0 ; --above ) { /*prints the spaces needed*/
       printf(" ");
     }
     for (great = 10 - randNum ; great > 0 ; --great ) { /*prints the numbers needed*/
       printf("%d", userInput);
     }
     printf("\n");
     }
     --userInput;
   }
   return 0;
 }