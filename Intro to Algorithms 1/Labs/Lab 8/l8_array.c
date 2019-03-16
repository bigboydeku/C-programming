/*
Name: Denis Nadarevic
Date Due: November 22nd, 2017
Description: prints out a chart of numbers and characters
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int userInput, n, randNum, i, great, above, half_width_count;
  int width, height;
  time_t t;
  
  srand((unsigned) time(&t));
  
  do {
    printf("Enter width [10,20]:");
    scanf("%d", &width);
    printf("Enter height [3,61]:");
    scanf("%d", &height);
  } while ((20 < width || width  < 10) || (61 < height || height < 3));
  
  n = 1;

  for(; n <= height; ++n) { /*Loops this block of code n times, equal to the number inputted by the user*/
    randNum = rand() % (width-2) + 2; /*Assign the randNum variable with a random number between 2 and w-1*/
    if(randNum == width/2) /*if randum number is half the width increment the counter */
      ++half_width_count;
    /*(n-1) makes sure we add 0 to 1 at first, +39*(n>=10) skips ahead to a then -58 *(n/36) ensures we go back a couple ascii letters to A*/
    unsigned char c_k = '1' + (n-1) + 39*(n >= 10)  - 58 * (n/36); /* Ascii for 1 is 49, 9 is 57, a is 97, z is 122, A is 65 */
    
    printf("%02d: ", randNum);

    
    if (randNum < width - randNum) /*Checks to see if the distance between Rk and 0 is less than the distance between w and Rk*/
      for (i = randNum - 1 ; i > 0 ; --i ) /*prints the numbers for all Rk less than or equal to 4*/
        printf("%c",c_k);

    else { /* if it isnt less than it does this*/
      
      for (above = randNum; above > 0 ; --above ) /*prints the spaces needed*/
        printf(" ");

      for (great = width- randNum ; great > 0 ; --great ) /*prints the numbers needed*/
        printf("%c", c_k);

    }

    printf("\n");
  }
  printf("Among %d numbers, the percentage of %d is %.2f%%\n", height, width/2, (float)half_width_count/height * 100);
  return 0;
}