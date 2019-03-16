/*
Name: Denis Nadarevic
Date due: November 17th, 2017
Description: prints out a 5x5 array of random numbers and outputs the sum for each column and row
*/
#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int i,j,n=5,m=5, randNum;
  int a[5][5], rowTotal[5] = {0}, colTotal[5] = {0};
  int rand(void);
  time_t t;
  srand((unsigned) time(&t));
  
  for(i=1; i <= 5; ++i){//prints out the 5x5 array
    printf("\nRow %d: ", i);
    
    for(j=1,n=1; j<=5; ++j) { 
      randNum = rand() % 24; //randomizes the number between 0 and 23
      printf("%d ", randNum); //prints out the random number between 0 and 23 for each part of the 5x5 array
      a[i][j] = randNum; //places the random number in a specific location in the array
      rowTotal[i] += a[i][j]; //sums up each element in rows
      colTotal[j] += a[i][j]; //sums up each element in columns
			

    }
    n+=1; //used to do the same thing for each column
  }
  
  printf("\n\nRow totals: "); //Prints out the total for each row 
  for (i=1; i <= 5; i++) {
    printf("%d ", rowTotal[i]);
  }
  
    printf("\nColumn totals: "); //Prints out the total for each column
  for (j=1; j <= 5; j++) {
    printf("%d ", colTotal[j]);
  }
  
  return 0;
}