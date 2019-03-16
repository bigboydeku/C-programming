/*
Name: Denis Nadarevic
Date Due: November 15th, 2017
Description: Output the factorial for any given positive integer.
*/

#include <stdio.h>

int main(void)
{
	/*Declaring variables for each integer type, assigning each one to a value of 1*/
  int userInput, factorial = 1, i;
  short s_factorial=1;
  unsigned short x_factorial=1;
  unsigned int lu_factorial=1;
  long ld_factorial=1;
  unsigned long u_factorial=1;
  long long lli_factorial=1;
  unsigned long long llu_factorial=1;
  long double Lg_factorial=1;
  

  
  /*Loops continuously, asking the user for a positive integer and output the factorial*/
  
  while(1)
  {
    printf("Enter a positive integer (or -ve integer to exit): ");
    scanf("%d", &userInput);
    /*If input is a negative integer, loop below breaks and outputs the final printf statement*/
    /*Checks to see if user's input is a positive integer or zero*/
    if (userInput < 0) {
      break;
    }
    factorial = 1;
    s_factorial = 1;
    x_factorial = 1;
    lu_factorial = 1;
    ld_factorial = 1;
    u_factorial = 1;
    lli_factorial = 1;
    llu_factorial = 1;
    Lg_factorial = 1;
    /*Computes the factorial for each integer type*/
    for(i = userInput; i > 1; i--) {
   	 factorial *= i;
         s_factorial *= i;
         x_factorial *=  i;
         lu_factorial *=  i;
         ld_factorial *=  i;
         u_factorial *= i;
         lli_factorial *= i;
         llu_factorial *= i;
         Lg_factorial *= i;
    }
    /*Outputs the factorial of the user's input for each integer type*/
    printf("Factorial of %d:\n", userInput);
    printf("%d (short, size = 2)\n",s_factorial);
    printf("%hu (unsigned short , size = 2)\n",x_factorial);
    printf("%d (int , size = 4)\n",factorial);
    printf("%u (unsigned int , size = 4)\n",lu_factorial);
    printf("%i (long , size = 4)\n",ld_factorial);
    printf("%u (unsigned long , size = 4)\n",u_factorial);
    printf("%lli (long long , size = 8)\n",lli_factorial);
    printf("%llu (unsigned long long , size = 8)\n",llu_factorial);
    printf("%Lg (long double, size = 12)\n",Lg_factorial);
     
    
  }
printf("Thank you for using my software :)\n");
return 0;
}
