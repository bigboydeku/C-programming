/*
Name: Denis Nadarevic
Student ID: 104445626
Lab Exercise #3 Part A
Date Due: February 13th, 2018

*/
#include <stdio.h>

int main() {
	int a = 7; //declare var a and set to 7
	int *aPtr; //declare pointer aPtr
	aPtr = &a; //points pointer var to the address of a
	printf("%p\n", &a); //print address of var a
	printf("%p\n", aPtr); //print address of var a
	printf("%p\n", &aPtr); //print address of the pointer var aPtr
	printf("%d\n", a); //print value of a, which is 7
	printf("%d\n", *aPtr); //dereference pointer var aPtr, print out 7
	printf("%p\n", *&aPtr); //points to the address of a and prints it
	printf("%p\n", &*aPtr); //points to the address of a and prints it
	printf("%d\n", *&a); //prints address of a
	// printf("%d", &*a); //error since a is not a pointer
	return 0;
}
