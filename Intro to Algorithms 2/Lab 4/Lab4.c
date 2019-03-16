/*
Name: Denis Nadarevic
ID: 104445626
Lab #4
Date Due: February 27th, 2017

*/

#include <stdio.h>
#include <string.h>

//Prototypes
void reverse (char *s);
void reverseRecursive (char *sBuffer, int n);

int main (void)
{



  // Part I. Character array and string



  char buffer1[] =
    { 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'f', 'i',
'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '.', '\0' };
  char buffer2[] = "this is the second buffer.";
  char buffer3[80];
  printf ("Please enter a message: ");
  scanf ("%[^\r\n]79s", buffer3); //any message that the user inputs is put into buffer3
  printf ("%s\n", buffer1); //prints buffer1, buffer2, and buffer3
  printf ("%s\n", buffer2);
  printf ("%s\n", buffer3);



  // Part II. Using a pointer to access the array.



  char *pBuffer = buffer3;
  printf ("Contents of Buffer 3 using while loop: ");
  while (*pBuffer != '\0') //prints out each character until \0 is reached
    {

      printf ("%c", *(pBuffer++)); //pBuffer is incremented when used again
    }
  printf ("\n");




  // Part III. String Manipulation: Reverse & recursive reverse.




  printf ("\nBefore reverse: %s", buffer3); //displays original message
  reverse (buffer3); //reverses message
  printf ("\nReverse: %s\n", buffer3); //displays reversed message
  reverse (buffer3); //flips the message back to normal

  printf ("\nBefore recursive reverse: %s", buffer3); //displays original message
  reverseRecursive (buffer3, (strlen(buffer3))-1); //reverses message
  printf ("\nAfter recursive reverse: %s\n", buffer3); //displays reversed message
  reverseRecursive (buffer3, (strlen(buffer3))-1); //flips the message back to normal
}

// Description: Takes in a character type pointer and reverses the string
// Input: Pointer
// Output: None
void reverse(char *sBuffer)
{
  int len = strlen(sBuffer);	//length of pointer; in this case its the length of s pointing to buffer3
  char *sBegin = sBuffer;	//initialize new char pointer to buffer3
  char *sEnd = sBuffer + (len - 1);	//initialize new char pointer to last element of buffer 3
  char temp;			//temp var for switching
  while (sBegin <= sEnd)
    {				//runs until the first element is greater than the changing element
      temp = *sBegin;		//sorting algorithm
      *sBegin = *sEnd;
      *sEnd = temp;
      sBegin++;
      sEnd--;
    }
}

// Description: Takes in a character type pointer and reverses the string
// Input: Pointer
// Output: None
void reverseRecursive (char *sBuffer, int n)
{
  char *sBegin = sBuffer;	//initialize new char pointer to buffer3
  char *sEnd = sBuffer + n;	//initialize new char pointer to last element of buffer 3
  char temp;			//temp var for switching
  if (n <= 0)
    {
      return;
    }
  else
    {
      temp = *sBegin;		//sorting algorithm
      *sBegin = *sEnd;
      *(sEnd) = temp;
      reverseRecursive ((sBuffer+1), (n-2));
    }
}
