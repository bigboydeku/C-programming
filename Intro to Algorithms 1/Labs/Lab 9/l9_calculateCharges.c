/*
Name: Denis Nadarevic
Date Due: November 29th, 2017
Description: Displays the charge for each car that parks in a parking garage, along with how long each car stayed for
*/
#include <stdio.h>
#include <math.h>

float calculateCharges(float car_hours){  /*This function calculates the charges for any input of hours*/
	float fee = 2.0; /*initial fee*/
    fee += car_hours > 3 ? 0.5 * ceil(car_hours-3) : 0; /* Checks to see if the car has stayed longer than 3 hours; if not, fee is just 2 dollars*/
    fee = fee > 10 ? 10 : fee; /*checks to see if the fee is above 10 due to maximum. If so, it locks the fee at 10*/
    return fee;
	}
int main(void) {
	
    float cars[3], total_cost = 0, curr_cost, total_hours = 0, curr_hour;
    
	printf("Enter the hours parked for 3 cars: ");
    scanf("%f %f %f", &cars[0], &cars[1], &cars[2]);
    printf("\n  Car\tHours\tCharge\n");
    
	for(int i = 0; i < 3; i++)
	{ /*For each of the three car parking lengths, it will output the car number, the number of hours they parked for, and the how much the car owner has to pay*/
        curr_hour = cars[i]; 
        total_hours += curr_hour; /*totals up the number of hours for all three cars*/
        curr_cost = calculateCharges(curr_hour); /*uses the calculateCharges function to compute the cost*/
        total_cost += curr_cost; /*totals the cost up*/
        printf("%5d\t%5.1f\t%6.2f\n", i+1, curr_hour, curr_cost); /*outputs the information for each car, spaced out*/
    }
	
    printf("TOTAL\t%5.1f\t%6.2f", total_hours, total_cost); /*outputs the total number of hours and the charge for all the cars together*/
    return 0;
	}