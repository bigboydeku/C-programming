/*
Name: Denis Nadarevic
ID: 104445626
Lab #5 - Advanced Strings
Date: March 13th, 2018
Description: 
User may input any sentence, with the final output being their input sorted
alphabetically.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE 256 
#define MAX_WORD 31
#define MAX_WORDS 100


//prototypes
char *read(char *s, const char *prompt);
void ParseSentence(char *s);

//main function
int main() 
{
  
  char s[MAX_LINE]; //original
  int numWords = 0; //stores number of words
  read(s, "enter sentence: "); //stores input into the s array
   ParseSentence(s); //calls function to parse sentence and sort alphabetically
   return 0;
   
   
} // end of main function





//Prompt the user nd read one sentence from the user
//input: a char array to hold the values
//return the populated array and a pointer to it
char *read(char *s, const char *prompt) 
{
  
  fgets(s, MAX_LINE, stdin);
  return s;

}






// given a sentence, it will overwrite the array with the words extracted 
// Input: char pointer
// Output: Alphabetically sorted array of inputted sentence
void ParseSentence(char *s) 
{
  
  char *temp;
  char wordList[MAX_WORD][MAX_LINE]; //stores to list
  int count = 0; //start with no words in the list
  
  
  
  //tokenizing sentence and storing into storage array
  char *ptrToken = NULL; //token pointer for strtok
  ptrToken = strtok(s, " .,;"); //set a \0 over the first delimiter
  
  while (ptrToken != NULL) 
  { //while the token is not \0
    strcpy(wordList[count], ptrToken); //copy word into the storage array
    count++; //increment for next element
    
    ptrToken = strtok(NULL, " .,;"); //continues where it left off
  } //keeps looking until official \0 is reached
  
  
  
  
  
  
  
  
  
  
  //Sorting alphabetically
  for(int i = 0; i < count; i++) 
  { //nested for loop to go through each letter and word
		for(int j = 0; j < count - 1; j++)
		{
			if(strcmp(wordList[j],wordList[j+1]) > 0) 
			{ // if the current word is < next word, Swap the elements
				strcpy(temp, wordList[j]); // same as the equal sign; copy element value to temp 
				strcpy(wordList[j],wordList[j+1]); 
				strcpy(wordList[j+1],temp); 
			}
		}
	} //end of nested for loop
  
  //prints the storage array, which is the final solution
    for (int i=0 ; i <count ; i++) 
  {
    printf("%s\n\n", wordList[i]);
  }
  
} //end of ParseSentence

