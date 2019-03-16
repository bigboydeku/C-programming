/*
Name: Denis Nadarevic
Student ID: 104445626
Lab Exercise #3 Part B
Date Due: February 13th, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

//Prototypes
void PrintArray(int *array, int size);
void PopulateArray(int *array, int size);
int Triple(int *x, int size);
void bubbleSort(int *array, int flag, int size);



int main() {
  int NumList[MAX] = {}; //Declare array
  int flag; //flag for ordered array
  printf("Populate: ");
  PopulateArray(NumList, MAX-1); //calls function to populate array
  PrintArray(NumList, MAX-1); //prints array
  
  printf("\n\nTriple Array: ");
  Triple(NumList, MAX-1); //triples the values of array elements
  PrintArray(NumList, MAX-1);
  
  printf("\n\nInput 1 for Ascending Array or -1 for Descending Array:  ");
  scanf("%d", &flag); //used to determine what order to pick
  
  printf("\nBubble Sort Array: ");
  bubbleSort(NumList, flag, MAX-1); //Sorts array in either ascending or descending order
  PrintArray(NumList, MAX-1);
  printf("\n");
//call functions here
}



//PRINT ARRAY
// Description: Prints each element in the array
// Input: Array pointer
// Output: Array elements
void PrintArray(int *array, int size) {
	for(int i=0 ; i < size ; i++) {
		printf("%d ", (*array++));
	}
}

// Description: populates elements in array in increasing even numbers, starting from 4,6,8,...
// Input: Array pointer var
// Output: No value, but an array that is populated
void PopulateArray(int *array, int size) {
	for(int i=1 ; i <= size ; i++) {
	  (*array) += 2*i + 2; //adds 2*i for every i th element
	  *array++; //next element
	}
}



//SWAP ARRAY ELEMENTS
// Description: Swaps two integers
// Input: Two integers
// Output: variables with reversed values
void swap(int *x, int *y) {
	int temp = *x; //temp var
	*x = *y; //sets original var as the other variable's value
	*y = temp; //sets other variable to temp value
}



//TRIPLE FUNCTION
// Description: Triples the value of any integer inputted
// Input: Integer
// Output: Value is tripled
// Note: If you want to tripled ONE INTEGER, remove for loop
int Triple(int *x, int size) {
  for (int i = 0 ; i < size ; i++) { //for each element in array
    (*x) *= 3; //element value is tripled
    *x++; //next element
  }
  return *x;
}



//SORTING FUNCTION0
// Description: Sorts an array in decreasing order
// Input: Array pointer, size of array
// Output: No output
void bubbleSort(int *array, int flag, int size) {
  if (flag == 1) { //Ascending order
	  for (unsigned int pass = 0 ; pass < size ; pass++) { //for every pass 
		  for (int j = 0 ; j < size ; j++) { //goes through each element
			  if ((*array+j) > (*array+j+1)) { //compares both values
				  swap((array+j),(array+j+1)); //calls function to swap the values of the two elements
				  *array++;
			  }
		  }
	  }
  }
  else if (flag == -1) { //descending order
    for (int i = 0 ; i < size ; i++){ //for every pass
      for (int j = 0 ; j < size ; j++) { //goes through each element
        if ((*array+i) < (*array+j)){ //compares both values
          swap((array+i),(array+j)); //calls function to swap the values of the two elements
        }
      }
    }
  }
}
