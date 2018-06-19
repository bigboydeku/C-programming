/*
Name: Denis Nadarevic
Description: This is a simple version of Twitter. The user can create tweets, 
search for tweet words, save tweets, and load tweets from files
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define MAX_TWEETS 5


struct tweetFormat { 
    int id;   								//ID to be used for every unique tweet
    char created_at[51];    				//stores the time (UTC) and the date
    char text[141];   						//holds text of type char, size 141
    char user[21];    						//holds username of type char, size 21
 }; typedef struct tweetFormat Tweet; 		//referred to as Tweet from now on

 
 
//prototypes
void menuDisplay(void);
void CreateNew(Tweet *tweetTemp, int idIncrement);
int SearchKeyWord(Tweet tweetTemp[], int idIncrement);
void ReadFile(Tweet tweetTemp[], int size);
int putChoice();
void saveFile(Tweet tweetTemp[], const char *FileName, int idIncrement);
int readTweets(Tweet tweetTemp[], const char *FileName, int idIncrement);




//beginning of main function
int main(){
  Tweet t[MAX_TWEETS]; //this is where all the tweets will be stored
  char username[21]; //temporary username storage
  int n; //this is to keep track of the option chossen for the menu
  char FileName[15]; //storage for file name
  for(int i = 0; i < MAX_TWEETS; i++)
  {
    t[i].id = 1000; //sets all tweet IDs to 1000
  }
  int idIncrement = 0;


//  printf("The value of the user id is %d",t->id);
  printf("Please enter your user name:\n>>");
  scanf("%[^\n]s", username);
  for(int i = 0; i < MAX_TWEETS; i++){
    strcpy(t[i].user, username); //put username to every tweet
  }

  printf("the user name that was entered: %s\n",t->user);
    do{
        menuDisplay(); //displays menu for user to see
		
		
		//description: goes through all the choices a user can pick, and calls the appropriate function for each case
		//switch statement will continue to loop after the selected operation is complete
		//it will also loop if an invalid input is given 
        switch(n = putChoice())
		{
			
			
          case 1 :
            if(idIncrement > 5)
			{
              printf("The array is full");
              break;
            }
            CreateNew(&t[idIncrement],idIncrement);
            //ender number, a space, and then the tweet
            idIncrement++;
            break;
          
		  
		  
		  case 2:
            printf("\n\nFound %d tweets matching the criteria!",SearchKeyWord(t,idIncrement));
            break;
          
		  
		  
		  case 3:
          printf("Displaying all %d tweets\n",idIncrement);
            for(int i = 0; i < idIncrement; i++)
			{
                printf("id: %d Created at: %sCreated by %s\n%s\n\n",t[i].id,t[i].created_at,t[i].user,t[i].text); //displays all tweets made
                }
            break;
          
		  
		  
		  case 4:
		  printf("Enter a file name: ");
		  scanf("%[^\n]s", FileName);
            saveFile(t, FileName, idIncrement);
            break;
          
		  
		  
		  case 5:
			printf("Enter a file name: ");
			scanf("%[^\n]s", FileName);
            readTweets(t, "tweetList.dat", idIncrement);
            break;
          
		  
		  
		  case 6:
          printf("Thank you for using Twitter.\n");
            break;
          default :
            printf("Invalid (input value between 1 - 6)");
		  }
		  
		  
        }while(n != 6);

  return 0;
}
//description: gets the user's input
//input: none
//output: integer
int putChoice() 
{
    int n;
    printf(">>");
    scanf("%d",&n);
    getchar();
    printf("\n");
    return n;
}

//description: displays the menu for the user to see
//input: none
//output: returns nothing, just prints
void menuDisplay(void)
{
  printf("\n\n~~~~~Welcome to Simple Twitter~~~~~\n");
  printf("1. Create a new tweet\n");
  printf("2. Search tweets\n");
  printf("3. Display tweets\n");
  printf("4. Save tweets to file\n");
  printf("5. Load tweets from file\n");
  printf("6. Exit\n");

}



//description: creates a new tweet ans saves it into the main tweet array where all the tweets are stores
//input: pointer to main array and the ID increment variable
//output: none, just adds information to the main array
void CreateNew(Tweet *tweetTemp, int idIncrement)
{

  char text[141]; //text array to store the tweet
  printf("Input:");
  fgets(text, sizeof(text), stdin); //stores the user's text into the array
  strcpy(tweetTemp->text, text); //copies the string in text and stores it into the text array in the tweetTemp pointer, which points to the main array of tweets
  printf("\nTweet has been successfully created.\n\n");

  
  
  //increases the ID, starting with 1000 to its max
  tweetTemp->id += idIncrement;

  //used to determine the time when the tweet was made
  
  struct tm *local;
  time_t t;
  
  t = time(NULL);
  
  local = gmtime(&t);
  //copy time information into the created_at array in the tweetTemp array
  strcpy(tweetTemp->created_at, asctime(local));
  
  
  
  
  //prints the tweets ID, time made, username, and the tweet itself
  printf("ID:%d\tCreated at:%s Created by %s\nTweet:%s\n",tweetTemp->id,tweetTemp->created_at,tweetTemp->user,tweetTemp->text);

} // end of CreateNew function




//Description: finds if a key is found in the list of tweets. User inputs the key.
//input: pointer to main array and ID increment
int SearchKeyWord(Tweet tweetTemp[], int idIncrement)
{
  char key[141]; //stores key to be searched for
  printf("Please enter the search keyword: ");
  scanf("%s",key);

  int matches = 0; //counter used to tell user how many times key was found in list of tweets

  	for(int i = 0; i < idIncrement; i++)
	{
  			if (strstr(tweetTemp[i].text,key) != NULL) 
			{
				printf("Key was found!:\n");
				printf("ID:%d\tCreated at:%sCreated by %s\n%s\n",tweetTemp[i].id,tweetTemp[i].created_at,tweetTemp[i].user,tweetTemp[i].text); //prints the tweet information
  				matches += 1; //increments everytime key is found in the main array
  			}
  		}
      return matches;
} //end of SearchKeyWord function





//Description: saves the list of tweets to a file
//Input: pointer to main array, file name to be made or written on, and ID increment
//Output: none, just saves a tweets
void saveFile(Tweet tweetTemp[], const char *FileName, int idIncrement)
{
    tweetTemp[idIncrement].text[strlen(tweetTemp[idIncrement].text)-141] = '\0';
    FILE* fPtr;
    fPtr = fopen(FileName, "w"); //writes a new file. If file name exists, it overwrites existing file
	
    for (int i = 0; i < idIncrement ; i++) 
	{
        
		
		if (fPtr != NULL) 
        {
			fprintf(fPtr,"%d\n%s%s\n%s", tweetTemp[i].id, tweetTemp[i].created_at, tweetTemp[i].user, tweetTemp[i].text); //prints the information one line at a time
        }
        
		
		
		else //runs if its a NULL pointer
        {
            fprintf(fPtr,"ILLEGAL INPUT, PLEASE TRY AGAIN.");
        }
    }
	
	
    fclose(fPtr); //closes the file, no more writing
} //end of saveFile function






//Description: reads the file made already and loads it in
//Input: pointer to main array, file name, and ID increment
int readTweets (Tweet tweetTemp[], const char *FileName, int idIncrement)
{
	int length = 0; 
	FILE *fPtr;
	fPtr = fopen(FileName, "r"); //reads existing file
	for(int i = idIncrement; i < MAX_TWEETS; i++)
	{
		if (!feof(fPtr)){ //runs until EOF is reached
			fscanf(fPtr, "%d", &tweetTemp[i].id); //scans file for information, 4 things at a time
			fscanf(fPtr, "%s", tweetTemp[i].created_at);
			fscanf(fPtr, "%s", tweetTemp[i].user);
			fscanf(fPtr, "%s", tweetTemp[i].text);
		}
		else //once EOF is reached, run this
		{
			fclose(fPtr);
		}
		
	}
	fclose(fPtr);
	return length;
} //end of readTweets function

















