#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(char str[]);
void stringReorder(char str[], int index1, int index2);
int findFirstOccurance(char str[], char aChar);


int main ()
{
	char myString[36] = "charcharcharchar";
	char test[100];
	
	
	int i;
	int idx=0;
	
	printf("** Welcome to the Double Dutch game **\n");
	
	printf("Please enter a string: ");
	//scanf(" %100[^\n]s", &test);
	scanf(" %99[^\n]s", test);
	
	//printString(myString);
	
	
	
	printf("\n");
//	stringReorder(test,3,10);
	
	printf("\n");
	idx=findFirstOccurance(test,'a');
	printf("%d\n",idx);
	
	return 0;
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

void stringReorder(char str[], int index1, int index2)
{
	char part1[36]="\0";
	char part2[36]="\0";
	char part3[36]="\0";
	char temp[36]="\0";
	
	printf("index1: %d , index2: %d\n", index1,index2);
	strncpy(part1, &str[0], index1);
	strncpy(part2, &str[index1], (index2-index1));
	strncpy(part3, &str[index2], strlen(str)-index2);	
	strcat(temp, part3);
	strcat(temp, part1);
	strcat(temp, part2);
	printf("Part 1: %s\n",part1);
	printf("Part 2: %s\n",part2);
	printf("Part 3: %s\n",part3);
	printf("Result: %s\n",temp);
	
	return;
}
 /*
	void strclr(char string[])
	{
		int i=0;
		while (string[i]!='\0')
		{
			string[i]='\0';
			i++;
		}
	}
//*/
int findFirstOccurance(char str[], char aChar)
{
	int val = 0;
	char *cptr;
	char *first;
	
	first = str;
	
	cptr = strchr(str, aChar);
	if(cptr)
	{
		val = cptr-first;
		return val;
	}
	else 
	{
		printf("character is not on the fucking array\n");
		return -1;
	}
}
