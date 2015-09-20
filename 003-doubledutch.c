#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(char str[]);

int main ()
{
	char myString[36] = "charcharcharchar";
	int i;
	
	printf("** Welcome to the Double Dutch game **\n");
	
	printf("Please enter a string of 8 chars: ");
	
	for (i=0;i<8;i++)
	{
		scanf("%1c",&myString[i]);
	}
	myString[i] = '\0';
	
	printString(myString);
	
	printf("\n");
	
}

void printString(char str[])
{
	int i;
	printf("Printed as string: %s\n",str);
	printf("printed as chars: ");
	for (i=0;i<36;i++)
	{
		printf("%c",str[i]);
	}
	return;
}
