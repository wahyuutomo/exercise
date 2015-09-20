#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(char str[]);

int main ()
{
	char myString[36] = "charcharchar";
	
	printf("** Welcome to the Double Dutch game **\n");
	
	printString(myString);
	
	printf("\n");
	
}

void printString(char str[])
{
	int i;
	printf("Printed as string: %s\n",str);
	printf("printed as chars: ");
	for (i=0;i<strlen(str);i++)
	{
		printf("%c",str[i]);
	}
	return;
}
