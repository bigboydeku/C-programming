#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 3

//prototypes
char wordCap(char *s);

int main()
{
	int i = 0;
	char s[20];
	FILE *fPtr = NULL;
	fPtr = fopen("employee.dat", "r"); //opens file, reads, and writes
	while(!feof(fPtr)) //runs while not EOF
	{
		fscanf(fPtr,"%d %s %s", &s);
		wordCap(s); //fixes
		fputs(s, fPtr); //saves
	}
	fclose(fPtr);

}

//Description: Capitalizes the beginning of every word that is alphabetical, the rest lower
//Input: String
//Output: Capitalized first name and last
char wordCap(char *s)
{
	int letter = 1;
	for (int i = 0 ; s[i] != '\0' ; i++) //loops until null terminating character is reached
	{
		if (letter == 1    &&   isalpha ( s[i] ) ) //if first letter and is actually a letter
		{
			s[i] = toupper( s[ i ] ); //uppercase it
			letter = 0; //sets to 0 since the next one is not the first
		}
		else if (s[ i ] == ' ') //space = new word
		{
			letter = 1;
		}
		else if (isupper(s[i])) //if it is uppercase for the letters that arent first
		{
			s[ i ] = tolower( s[ i ] ); //lowercase them
		}
	}
} //end of WordCap function
