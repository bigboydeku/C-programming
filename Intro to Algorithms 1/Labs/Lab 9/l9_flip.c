/**
Name: Denis Nadarevic
Date Due: November 29th, 2017
Description: Prints out the results of flipping a coin 100 times
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 
int flip(){
    return rand() % 2; // the function returns a random number between 0 and 1.
}
 
int main(void)
{
  int heads = 0, tails = 0, result;
  
 
  srand(time(NULL));
  for(int i = 1; i <= 100; i++){ // for loop will run this code 100 times
  
      result = flip(); //result calls the function flip() and will randomly receive either a 0 or 1. 0 is tails while 1 is heads 
      result == 0 ? ++tails : ++heads;  //if the result = 0, adds 1 to the counting variable tails; if result = 1, adds 1 to the counting variable heads
      result == 1 ? printf("HEADS") : printf("TAILS"); //prints out the result, if it equals 1, it prints "HEADS", if it does not equal 1, prints "TAILS"
      i % 10 == 0 ? printf("\n") : printf(" "); //This makes a 10 by 10 grid. For every 10 loops this for loop does, it will print out a new line. within each 10 loop, it will print a space to space out the words
  }
  
  printf("\nThe total number of Heads was %d\nThe total number of Tails was %d", heads, tails); //prints out the counting variable to show the total number of heads and tails

}