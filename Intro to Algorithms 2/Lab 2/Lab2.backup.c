/*
Name: NADAREVIC, Denis
ID: 104445626
Lab #2
Date: February 6th, 2018
Purpose: Provide an interactive menu where the user can manipulate an array. The user may print the array,
randomize the elements in the array, and search for numbers in the array.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 10
#define N 5

// Input: the array and its elements.
// Output: Prints the full array at a certain point.
// Description: Goes through each element in the array and prints them out.
void printArray2D(int arrayTwoD[][N]) {
	for(int m = 0; m < M; m++) { //row for loop, goes through each row
		printf("["); //adds brackets for a cleaner-looping array
		for(int n = 0; n < N; n++) { //column for loop, goes through each column
			if(n == N-1) {
				printf("%d]\n",arrayTwoD[m][n]); //prints the last element at that specific time
				}
			else {
			printf("%d,",arrayTwoD[m][n]); //prints the element at that specific time
			}
		}
	}
	printf("\n");
}

// Input: Number z, Array
// Output: Returns true or false
// Description: Determines if the number z appears in the array, true if it does, false if not
int linearSearch(int key, int arrayTwoD[][N]) {
	int flag = 0; //1 being found, 0 being not found.
	for(int m = 0; m < M; m++) { //search array
		for(int n = 0; n < N; n++) {
			if(key == arrayTwoD[m][n]) { //if user's input = an element in the array, flag is set to 1
				flag = 1;
				break;
			} //make it so it prints true, not just returns true
		}
	}
	if (flag == 1) {  //turns 1 into found and 0 to false.
		printf("Number is in the array.");
		}
	else {
		printf("Number is not in the array.");
		}
	}

// Input: Array
// Output: None
// Description: takes in an array and rearranges the indices so 0's appear in the end
// preserves other order
void sort(int A[]) {
	int hold;
	for(int i = 0; i < M*N; i++) {
		for (int j = 0 ; j< M*N ; j++) { //switches current and old element values
			if(A[j] > A[j+1])  { // If element is zero
				hold = A[j+1]; // hold the value in a temporary var
				A[j+1] = A[j]; // set previous element value to current value
				A[j] = hold; // set the old current value to the previous value,
			}
		}
	}
} //end of sort function

// Input: Array
// Output: No output, sorts the array
// Description: array is filled with random numbers from 0 to 100
/*void populateRandom2D(int arrayTwoD[][N]) {
	int array[M*N]; //set array to 100 elements, M=10, N= 10, M*N= 100
	for(int i = 0; i < M*N; i++) {
		array[i] = i+1; //array is filled with numbers. Not necessary but it is my method.
	}
	int total = M*N; //for scalability
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			srand(time(NULL));
			int x = rand()%(100)+1; // Generate a random number from 0 to 100

			arrayTwoD[i][j] = array[x]; // value from the array[] is stored into the new array.

			array[x] = 0; // array from before is set to zero since it has been used
			//sort(array); // this will send all zeros to the end, as stated in the lab

			total -= 1; // Check 1 less index
		}
	}
}
*/
void populateRandom2D(int arrayTwoD[][N]) {
	int array[M*N];
	for(int i = 0 ; i < M*N ; i++) {
		array[i] = 1;
	}
	printArray2D(array);

	/*int total = M*N;
	srand(time(NULL));
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			int x = rand()%(100); // Generate a random number from 0 to 100
			array[i] = x; //set element at specific location to a random number
		}
	}*/
}

// Input: none
// Output: Returns 0 if program successful, displays menu
// Description: Main function controls function calls through an interactive menu
int main(void) {
	bool run = true;
	int choice,x;
	int arrayTwoD[M][N] = {};
	while(run) {
		printf("Enter an array operation: \n 1. Print Array \n 2. Populate Array\n 3. Linear Search \n 0. QUIT\n");
		scanf("%d",&choice);
		if(choice == 0) {break;}
		// select which operation to use depending on choice
		switch(choice) {
			case 1: // if first option
				printf("Print Array:\n");
				printArray2D(arrayTwoD);
				break;
			case 2:
				printf("Populate Array:\n");
				int arrayTwoD[M][N];
				populateRandom2D(arrayTwoD);
				printArray2D(arrayTwoD);

				break;
			case 3:
				printf("Linear Search - Enter a number: \n");
				scanf("%d",&x);
				linearSearch(x,arrayTwoD);
				printf("\n");
				break;
		}
	}
}
