/*
Name: Denis Nadarevic
ID: 104445626
Description: ???
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct point {
	int x;
	int y;
	char label[21];
	struct point *ptrNext;  // self referential pointer
};






//prototype list -----------------------------------------
int isEmptyList(struct point *ptrF);
void PrintList(struct point *ptrF); //--------------
void ResetList(struct point **ptrF);
void AddToBeginning(struct point **ptrF);
struct point *AddToEnd(struct point *data, struct point *ptrF, struct point *ptrL); //------------
void InputRecord(struct point *ptrNew); // used by Add to interactively get the values from the user
void mainMenu();

struct point *ptrFirst;
struct point *ptrLast;







//main function ------------------------------------------
void main()
{
    struct point *data;
    int userInput = 0; //userInput by default is 0
    do {
        printf("\n");
        mainMenu(); //displays main menu
        printf("\n>>");
        scanf("%d", &userInput);
        switch(userInput)
        {
            case 1: data = AddToEnd(data, ptrFirst, ptrLast); break;
            case 2: AddToBeginning(&data); break;
            case 3:printf("This list is (1 = empty, 0 = not empty) -------> %d", isEmptyList(data)); break;
            case 4: ResetList(&data); break;
            case 5: PrintList(data); break;
            case 6: InputRecord(data); break;
            case 7:
            case 0: printf("Bye bye!\n");
        }
    } while(userInput != 0);
    
    if(data) free(data);
} //end of main function




//functions ----------------------------
void mainMenu()
{

    printf("~~~~~Main Menu~~~~~\n");
    printf("1. Add point at the end of the list\n2. Add a point at the beginning of the list\n3. Is the list empty?\n");
    printf("4. Erase all points from the list (reset)\n5. Display the list\n6. Save the list to a file\n7. Read the list back from a file.");
    printf("\n0. Exit");
    
}





// Description: adds a node to the end of the linked list
// Input: Takes in the head pointer of the linked list
// Output: Returns the head of the linked list
struct point *AddToEnd(struct point *data, struct point *ptrF, struct point *ptrL)
{
    struct point *newNode = (struct point*)malloc(sizeof(struct point));
    printf("\n");
	scanf("%d %d",&(newNode->x),&(newNode->y));
	newNode->ptrNext = NULL;
	
	if(data == NULL) 
	{
		data = newNode;
		return data;
	}
	
	struct point *node = data;
	while(node->ptrNext != NULL) 
	{
		node = node->ptrNext;
	}
	
	node->ptrNext = newNode;
	return data;
}


//Description: Adds in a new node in the linked list
//input: pointers to the first and ptrLast
//output: none, just adds a node to the beginning
void AddToBeginning(struct point **ptrF)
{
    struct point *newNode = (struct point*)malloc(sizeof(struct point));
    
    printf("Enter data: ");
    scanf("%d %d",&(newNode->x),&(newNode->y));
    newNode->ptrNext = NULL;
    
    if (*ptrF == NULL)
    {
        *ptrF = newNode;
    }
    
    else
    {
        newNode->ptrNext = *ptrF;
        *ptrF = newNode;
    }
}



// Description: Cycles through the linked list printing node data for nodes which are not null
// Input: Takes in the head pointer of the linked list
// Output: Cycles through the linked list printing each node data
void PrintList(struct point *ptrF) {
	struct point *node = ptrF;
	while(node != NULL) {
		printf("%d %d --> ",node->x,node->y);
		node = node->ptrNext;
	}
	printf("NULL!\n");
}

//Description: Checks to see if the list is empty
//input: pointer to head of list
//output: integer indicating the status of the list
int isEmptyList(struct point *ptrF)
{
    if(ptrF == NULL)
        return 1;
    else
        return 2;
}

//FIX THIS ONE, CHANGE SHIT
void ResetList(struct point **ptrF){

    struct point *current  = *ptrF;

    while(current != NULL){
        free(*ptrF);
        current = current->ptrNext;
        *ptrF = current;
    }
}


void InputRecord(struct point *ptrNew)
{
	FILE *fptr;
    fptr = fopen("file.txt", "w");    // overwrites or create new file
    if (fptr!=NULL)             // always check for fptr not be NULL before writing!
    {
        fprintf(fptr, "score\tname\n");         // header (optional)
        fprintf(fptr, "%d\t%s", score, name);   // write so you can read it back!
        fclose(fptr);       // don't forget to close the file
    }
    else                        // safe code with informative error message
    {
        fprintf(stderr, "Error (%d) opening the file \"%s\" for writing.\n",
            errno, filename);   // need stdlib.h for errno
    }
}













