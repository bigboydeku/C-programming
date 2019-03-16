/*
Name: Denis Nadarevic
Date due: November 17th, 2017
Description: Converts letter to a telephone number
*/
#include <stdio.h>

int main(void)
{
  char input;
  char word[] = {'C','A','L','L','A','T','T'}; /*Fixed the array to one word*/
  int count = 0;
  printf("size is %i\n", sizeof(word)); /*Prints the size of the word*/
  printf("The translation of CALLATT is: ");
  for (; count < sizeof(word); ++count) { /*Loop will look at each character of the array and convert them into numbers*/
        switch (input = word[count]) { 
            case 'A': case 'B': case 'C': /* If a character belongs to any of these cases, the program will print the number corresponding to that letter*/
                   printf("2");
                   break;
            case 'D': case 'E': case 'F':
                   printf("3");
                   break;
            case 'G': case 'H': case 'I':
                   printf("4");
                   break;
            case 'J': case 'K': case 'L':
                   printf("5");
                   break;
            case 'M': case 'N': case 'O':
                   printf("6");
                   break;
            case 'P': case 'R': case 'S':
                   printf("7");
                   break;
            case 'T': case 'U': case 'V':
                   printf("8");
                   break;
            case 'W': case 'X': case 'Y':
                   printf("9");
                   break;
            default:
                   putchar(input); /*If none of the cases are seen in the input, it will place that element regardless*/
                   /*For example, the user might input a "-"; the program will output the "-"*/
    }
  }
  printf("\n");
  return 0;
}