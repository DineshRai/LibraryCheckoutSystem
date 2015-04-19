#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>


//run with clang libraryprogram.c -lncurses (or another compiler)

char date[20];
char userName[20];
char bookName[20];
char telephoneNumber[20];

void write(); //writes book check out to record.txt file
void display();  //allows user to view books that were checked out on a given date


int main()
{
	int selection;
	char date[20];
	
	do
	{
		clear();
		//display user options
		printf("Welcome to the library!!\n\n");
		printf("Press 1 to add a book\n");
		printf("Press 2 to display a date\n");
		printf("press 3 to exit\n");

		printf("enter a selection:\n");
		scanf("%i", &selection);

		switch(selection)
		{
			case 1:
				write();  //writes book checkout to record.txt file
				break;

			case 2:
				printf("\nEnter Date:");
				scanf("%s", date);
				display(date);  //allows user to view books that were checked out on a given date
				break;

			case 3:
				exit(0);

			default: 
				printf("\nInvalid selection");

		}

		getch();

	} while (selection != 0);


} //closes main


void write() 
{
	FILE *fp;
	char date[20];
	char userName[20];
	char bookName[20];
	char telephoneNumber[20];

	//user inputs information for check out
	printf("Enter today's date: \t\t\n");
	scanf("%s", date);
	printf("Enter your name: \t\t\n");
	scanf("%s", userName);
	printf("Enter your telephone number: \t\t\n");
	scanf("%s", telephoneNumber);
	printf("Enter the book's name: \t\t\n");
	scanf("%s", bookName);

	fp = fopen("Record.txt", "a");

	//appends entry to Record.txt
	fprintf(fp, "\n%s %s %s %s\n", 	date, 
									userName, 
									telephoneNumber, 
									bookName
									);

	printf("Transaction was saved\n");

	fclose(fp);

}

void display(char dateKey[])
{
	FILE *fp;

	fp = fopen("Record.txt","r");

	while(fscanf(fp, "%s %s %s %s\n", 	date, 
									userName, 
									telephoneNumber, 
									bookName
									) != EOF)
	{
		// prints record if dates match
		if(strcmp(date, dateKey) == 0)
		{
			printf("\n\n Name = %s\n", userName);
			printf("Telephone = %s\n", telephoneNumber);
			printf("Book Name = %s\n", bookName);
		}

	}

	fclose(fp);
}