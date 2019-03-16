/*
Name: Denis Nadarevic
Date Due: December 1st, 2017
Description: Computs the number of digits in an inputted number
*/
#include <stdio.h>

int num_digits(j) {
  int digits=0;
  while (j > 0) {
    j /= 10;
    ++digits;
  }
  printf("There are %d digits.", digits);
}

int main(void) {
  int n, j;
  printf("Please enter a whole number: ");
  scanf("%d", &n);
  j = n;
  num_digits(j);
}