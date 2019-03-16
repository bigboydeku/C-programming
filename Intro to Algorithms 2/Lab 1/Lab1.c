/* NADAREVIC, Denis
ID: 104445626
Lab Exercise #0
Date: January 16th, 2018
Purpose: 
*/

#include <stdio.h>
#include <math.h>

int functionOne();
int functionTwo();
int functionThree();
int functionFour();

int main() {
  int userInput; //stores the user's selected function
  while(1){ //runs continuously
    printf("Please choose a number to access a specific function: \n" //prints a list of available functions to choose from
    "#1\n"
    "#2\n"
    "#3\n"
    "#4\n"
    "#5\n"); 
    scanf("%d", &userInput); //variable = user's Input
    
    switch(userInput) { //runs function corresponding to user's selected number
        case 1:
          functionOne();
          break;
        case 2:
          functionTwo();
          break;
        case 3:
          functionThree();
          break;
        case 4:
          functionFour();
          break;
        
          
          
        default:
          printf("That is not a valid input. Try again.\n");
      
    } //end of switch
  } //end of while loop
  return 0;
}

 //Non-Recursive Functions Below

  int functionOne() { //outputs the answer for 1+2+3...+n 
    int userInput; //user's input for n
    int sum=0; //all the numbers are collected here
    printf("Please type a natural number to receive the sum:");
    scanf("%d", &userInput);
    for (int i=0; i<=userInput ; i++) { //runs loop 'userInput' times to get sum
      sum += i; //sum is a collection of incrementing 'i' values
    }
    printf("\nThe sum is: %d\n\n", sum);
    return 0;
  } //end of functionOne
  
  int functionTwo(){
    int userInput; //user's input for n
    int sum=0; //all the numbers are collected here
    printf("Please type a natural number to receive the sum:");
    scanf("%d", &userInput);
    for(int i = 1; i <=userInput ; i++) { //runs loop 'userInput' times to get sum
      sum += pow((i+1),2);
    }
    printf("\nThe sum is: %d\n\n", sum);
    return 0;
  }
  
  int functionThree(){
    int userInput;
    int n1=0,n2=1,n3;
    printf("Please type a natural number to receive the sum:");
    scanf("%d", &userInput);
    printf("\n\n");
    for (int i = 1; i <= userInput; ++i)
    {
        printf("%d ", n1);
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    printf("\n\n");
  }
  
  int functionFour(){
  
    
  }
