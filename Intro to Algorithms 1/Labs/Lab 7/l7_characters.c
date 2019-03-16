/*
Name: Denis Nadarevic
Date Due: November 15th, 2017
Description: Outputs n number of lines of numbers and letters in a pattern; based off of the user's input (n) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  int userInput, n, randNum, i, great, above = 0;
  srand(time(NULL));
  printf("Enter a number between 9 and 35: "); /*Asks user to input a number between 2 and 9*/
  scanf("%d", &userInput);
  printf("\n");
 for(n = userInput; n > 0 ; --n) { /*Loops this block of code n times, equal to the number inputted by the user*/
   randNum = ((rand() % 8) + 2); /*Assign the randNum variable with a random number between 2 and 9*/
   if (randNum <= 4){ /*Checks to see the randNum variable is below or equal to 4*/
     printf("%d: ", randNum);
     for (i = randNum - 1 ; i > 0 ; --i ) { /*prints the numbers for all Rk less than or equal to 4*/
        if(n > 9){
            printf("%c", 'z' - (35 - n)); /*Prints out letters if n is greater than 9*/
        }
        else{
            printf("%d", n); /*if input is less than or equal to 9, this prints*/
        }
        
       }
       printf("\n");
   }
   else { /* If the randNum variable has a number greater than 4, this code runs*/
     printf("%d:", randNum); 
     for (above = randNum; above > 0 ; --above ) { /*prints the spaces needed*/
       printf(" ");
     }
     for (great = 10 - randNum ; great > 0 ; --great ) { /*prints the numbers needed*/
        if(n > 9){
            printf("%c", 'z' - (35 - n)); /*Prints out letters if n is greater than 9*/
        }
        else{
            printf("%d", n); /*if input is less than or equal to 9, this prints*/
        }
     }
     printf("\n");
     }
   }
   return 0;
 }