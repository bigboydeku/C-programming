/*
Name: Denis Nadarevic
ID: 104445626
Lab #7
Description: Creates a linked list of values and words, can be modified
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
struct point *AddToEnd(struct point *data); //------------
struct point *InputRecord(struct point *ptrNew);
void mainMenu();
void save(struct point *ptrNew);
void load(struct point *data);

struct point *ptrFirst;
struct point *ptrLast;
int count = 0; //counts # of inputs






//main function ------------------------------------------
void main()
{
    struct point *data = NULL;
    int userInput = 0; //userInput by default is 0
    do {
        printf("\n");
        mainMenu(); //displays main menu
        printf("\n>>");
        scanf("%d", &userInput);
        switch(userInput)
        {
            case 1: data = AddToEnd(data); break;
            case 2: AddToBeginning(&data); break;
            case 3:printf("This list is (1 = empty, 0 = not empty) -------> %d", isEmptyList(data)); break;
            case 4: ResetList(&data); break;
            case 5: PrintList(data); break;
            case 6: save(data); break;
            case 7: load(data); break;
            case 0: printf("Bye bye!\n"); break;
        }
    } while(userInput != 0);

    free(data);
} //end of main function




//functions ----------------------------
void mainMenu()
{

    printf("~~~~~Main Menu~~~~~\n");
    printf("1. Add point at the end of the list\n2. Add a point at the beginning of the list\n3. Is the list empty?\n");
    printf("4. Erase all points from the list (reset)\n5. Display the list\n6. Save the list to a file\n7. Read the list back from a file.");
    printf("\n0. Exit");

}

//InputRecord sets the values for a node
//Input: a pointer to an existing record
//Output: sets the int value to a value from the keyboard
//also pointers are all null
struct point *InputRecord(struct point *ptrNew)
{
    if(ptrNew==NULL) //fail-safe: check for valid pointer
        return NULL;
    //grabs values from user
    printf("x and y: ");
    scanf("%d%d", &ptrNew->x,&ptrNew->y);

	printf("label: ");
    scanf("%s", ptrNew->label);

    ptrNew->ptrNext = NULL; //next node is null/end

	return ptrNew;
}



// Description: adds a node to the end of the linked list
// Input: Takes in the head pointer of the linked list
// Output: Returns the head of the linked list
struct point *AddToEnd(struct point *data)
{
    struct point *newNode = (struct point*)malloc(sizeof(struct point));
    printf("\n");
	InputRecord(newNode);
	newNode->ptrNext = NULL;

	if(data == NULL) //is it empty
	{
		data = newNode; //set the only node to new node
		return data;
	}

	struct point *node = data;
	while(node->ptrNext != NULL)  //while it isnt the end of the list
	{
		node = node->ptrNext;
	}

	node->ptrNext = newNode;
	return data; //return pointer to data
}


//Description: Adds in a new node in the linked list
//input: pointers to the first and ptrLast
//output: none, just adds a node to the beginning
void AddToBeginning(struct point **ptrF)
{
    struct point *newNode = (struct point*)malloc(sizeof(struct point));
    InputRecord(newNode);
    newNode->ptrNext = NULL;

    if (*ptrF == NULL) //if head is empty
    {
        *ptrF = newNode; //new node is the head/first
    }

    else //if not empty
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
		printf("%d %d %s --> ",node->x,node->y, node->label); //prints the data horizontally
		node = node->ptrNext;
	}
	printf("NULL!\n");
} //end of PrintList function





//Description: Checks to see if the list is empty
//input: pointer to head of list
//output: integer indicating the status of the list
int isEmptyList(struct point *ptrF)
{
    if(ptrF == NULL)
        return 1;
    else
        return 0;
} //end of isEmptyList function





//Description: Removes all nodes created
//input: Pointer to head of list
//output: nothing, resets list
void ResetList(struct point **ptrF){

    struct point *current  = *ptrF;

    while(current != NULL){ //while the list does not hit NULL
        free(*ptrF); //free memory
        current = current->ptrNext;
        *ptrF = current;
    }
} //end of resetList function





//description: saves the linked list in a file
//input: pointer to the linked list head
//output: nothing, just saves a file
void save(struct point *ptrNew)
{
	//count=0;
    FILE* outfile;
    struct point *ptrCurrent = ptrNew;

    outfile = fopen("file.dat", "w");

    while(ptrCurrent != NULL) //runs until list has ended
    {
        //count++;
        fprintf(outfile, "%d %d %s",ptrCurrent->x, ptrCurrent->y, ptrCurrent->label); //prints the formatted information into a file

		if(ptrCurrent->ptrNext != NULL)
		{
            fprintf(outfile, "\r\n");
		}
        ptrCurrent=ptrCurrent->ptrNext;
    }
	fclose(outfile); //close the file
} //end of save function






//description: reads a file and places all the information into nodes in a linked list
//input: nothing
//output: nothing, just loads in a linked list
void load(struct point *data) {
	FILE* infile;
    int count = 0;  // how many records saved
    struct point *ptrNew = NULL;
    infile = fopen("file.dat", "r");
		struct point * ptrF;
	while(1)
    {
        ptrNew = (struct point *) (malloc(sizeof(struct point)));
				ptrNew->ptrNext = NULL;
				if (fscanf(infile, "%d %d %s", &ptrNew->x, &ptrNew->y, ptrNew->label) == EOF) {
					break;
				}
				struct point *temp = data;
				if (data == NULL) {
					data = ptrNew;
				}
				else {
					for(;;) {
						if(temp->ptrNext == NULL) {
							temp->ptrNext = ptrNew;
							break;
						}
						else {
							temp = temp->ptrNext;
						}
					}
				}
        /*if(data==NULL) //if head is NULL
        {
            fscanf(infile, "%d %d %s", &ptrNew->x, &ptrNew->y, ptrNew->label);
						ptrNew->ptrNext=NULL;  //set last one to NULL
						data = ptrNew;
						ptrF = data->ptrNext;
						//printf("%s", ptrF->label);
						//ptrFirst=ptrNew; //head node = new pointer
            //ptrLast=ptrNew;
        }
        else
        {
            fscanf(infile, "%d %d %s", &ptrNew->x, &ptrNew->y, ptrNew->label);


						while(1)  //while it isnt the end of the list
						{
							if (node->ptrNext == NULL) {
								printf("%s", ptrNew->label);
								node= ptrNew;
								break;
							}
							fscanf(infile, "%d %d %s", &ptrNew->x, &ptrNew->y, ptrNew->label);else {
								node = node->ptrNext;
							}
						}
*/
						//node->ptrNext = ptrNew;

            //ptrNew->ptrNext=ptrFirst;


        }


		//PrintList(ptrF);
    fclose(infile); //close file
} //end of load function
