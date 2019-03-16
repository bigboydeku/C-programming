/*
Name: Denis Nadarevic
ID: 104445626
Description: Saves employee records inputted
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define M 3

struct employee {
    char firstname[40];
    char lastname[40];
    int id;    
 }; typedef struct employee Employee;


/* Input the employee data interactively from the keyboard */
void InputEmployeeRecord(Employee *ptrEmp);

/* Display the contents of a given Employee record*/
void printEmployeeRecord(const Employee *empList);

/* Save the contents of the employee record list to the newly created text file specified by FileName */
void SaveEmployeeRecord(const Employee e[], const char *FileName);

void main() {

 Employee employeeList[3]; // modified to save an array of 3 employee records
 InputEmployeeRecord(employeeList);
 printEmployeeRecord(employeeList);
 SaveEmployeeRecord(employeeList, "employee.dat");
}



//Description: Takes in the information from the file
//Input: Pointer to employee struct members
//Output: None
void InputEmployeeRecord(Employee *ptrEmp)
{
	for (int i = 0 ; i < M ; i++) { //scans
		scanf("%d", &ptrEmp[i].id);
		scanf("%s", ptrEmp[i].firstname);
		scanf("%s", ptrEmp[i].lastname);
	}
} //end of InputEmployeeRecord function


void printEmployeeRecord(const Employee *empList)
{
	printf("ID\tFIRSTNAME\tLASTNAME\n");
	for (int i = 0 ; i < M ; i++)
	{
		printf("%d\t%s\t%s\n", empList[i].id, empList[i].firstname, empList[i].lastname);
	}
} //end of PrintEmployeeRecord function

void SaveEmployeeRecord(const Employee e[], const char *FileName)
{
	FILE *fPtr = NULL;
	fPtr = fopen(FileName, "w"); //opens up new file, any file with the same name gets overwritten
	for (int i = 0 ; i < M ; i++)
	{
		fprintf(fPtr,"%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
	}
	fclose(fPtr);
} //end of SaveEmployeeRecord function
