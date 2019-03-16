/*
Name: Denis Nadarevic
Date: November 29th, 2017
*/
#include <stdlib.h>
#include <stdio.h>

/*
int main(int argc, char *argv[]) {
    if (argc !=2) {
        printf("Error using the argument in: 104445626_MyMessage filename\n");
        exit(EXIT_FAILURE);
    }
	
	FILE* fp = fopen("104445626_MyMessage.txt", "r");
	if (fp == NULL) {
		printf("Can't open fileleng");
	}
	
    char ch; 
	ch = getchar(fp);//Read first char if any
    while (ch != EOF) {
        putchar(ch);
        ch = getchar(fp);
    }
    fclose(fp);
	
	return 0;
}*/
int main(int argc, char *argv[]) {

	FILE *fp = fopen("104445626_MyMessage.txt", "r");
	if (fp == NULL) {
		printf("Can't open file");
		exit(EXIT_FAILURE);
	}
	
    char ch; 
	ch = fgetc(fp);//Read first char if any
    while (ch != EOF) {
        putchar(ch);
        ch = fgetc(fp);
    }
    fclose(fp);
	
	return 0;
}