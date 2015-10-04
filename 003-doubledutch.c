#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(char str[]);
char * stringReorder(char str[], int index1, int index2);
int findFirstOccurance(char str[], char aChar);
char * replaceChars(char str[], char sChar[], char rChar);
char * insertChar(char str[], char aChar, int index);

int main ()
{
	char myString[100];
	
	int i;
	int idx=0;
	int idx2=0;
	
	printf("** Welcome to the Double Dutch game **\n");
	printf("Please enter a string: ");
	scanf(" %99[^\n]s", myString);
	
	idx=findFirstOccurance(myString,' ');
	
	replaceChars(myString, "aiueo", 'a');
		
	if ((myString[0]!='a')&&(myString[0]!='i')&&(myString[0]!='u')&&(myString[0]!='e')&&(myString[0]!='o')&&(myString[0]!='A')&&(myString[0]!='I')&&(myString[0]!='U')&&(myString[0]!='E')&&(myString[0]!='O'))
		{
			insertChar(myString, 'a',0);
			insertChar(myString, 'y',1);
		}
		
		
	for (i=0;i<=strlen(myString);i++)
	{
		idx=findFirstOccurance(myString,' ');
		if (idx) myString[idx] = '-';

		if ((myString[idx+1]!='a')&&(myString[idx+1]!='i')&&(myString[idx+1]!='u')&&(myString[idx+1]!='e')&&(myString[idx+1]!='o')&&(myString[idx+1]!='A')&&(myString[idx+1]!='I')&&(myString[idx+1]!='U')&&(myString[idx+1]!='E')&&(myString[idx+1]!='O'))
		{
			insertChar(myString, 'a',idx+1);
			insertChar(myString, 'y',idx+2);
			
		} 
	}
	
	replaceChars(myString,"-",' ');
	
	idx = findFirstOccurance(myString,' ');
	if (idx) myString[idx]='-';
	idx2 = findFirstOccurance(myString,' ');
	if (idx2) replaceChars(myString,"-",' ');
	
	stringReorder(myString,idx,idx2);	
	insertChar(myString, ' ',(strlen(myString)-idx2));
	
	printf("Double Dutch translation: %s\n", myString);
	
	return 0;
}

void printString(char str[])
{
	printf("%s\n",str);
	return;
}

char * stringReorder(char str[], int index1, int index2)
{
	char part1[100]="\0";
	char part2[100]="\0";
	char part3[100]="\0";
	char temp[100]="\0";
	
	strncpy(part1, &str[0], index1);
	strncpy(part2, &str[index1], (index2-index1));
	strncpy(part3, &str[index2], strlen(str)-index2);	
	strcat(temp, part3);
	strcat(temp, part1);
	strcat(temp, part2);
	
	strcpy(str,temp);
	
	return str;
}

int findFirstOccurance(char str[], char aChar)
{
	int j=0;
	int stop = 0;
	do 
	{
		if (str[j]==aChar) stop=1; 
		j++;
	} while ((stop==0)&&(str[j]!='\0'));
	if (stop==1) {return j-1;} else {return -1;}
	 
}


char * replaceChars(char str[], char sChar[], char rChar)
{
	int idx=0;
	int j=0;
	int i=0;
	int lsChar=0;
	
	
	
	lsChar = strlen(sChar);
	
	for (j=0;j<lsChar;j++)
	{
		
		for (i=0;i<strlen(str);i++)
		{
			idx = findFirstOccurance(str,sChar[j]);
			if (idx!=-1) str[idx] = rChar;
		}
		
		
	}
	
	return str;
}

char * insertChar(char str[], char aChar, int index)
{
	int j = 0;
	
	for(j=strlen(str);j>=index;j--)
	{
		str[j+1] = str[j];
	}
	str[index] = aChar;

	return str;
}
