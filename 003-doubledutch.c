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
	char myString[36] = "charcharcharchar";
	char test[100];
	char remove[] = "asd";
	
	printf("string length = %d\n",strlen(remove));
	
	printf("\n %c \n",myString[3]);
	
	printf("before = ");
	printString(myString);
	strcpy(myString,remove);
	printf("after = ");
	printString(myString);
	
	int i;
	int idx=0;
	
	printf("** Welcome to the Double Dutch game **\n");
	
	printf("Please enter a string: ");
	//scanf(" %100[^\n]s", &test);
	scanf(" %99[^\n]s", test);
	
	//printString(myString);
	printString(test);
	
	
	printf("\n");
//	stringReorder(test,3,10);
	
	printf("\n");
	idx=findFirstOccurance(test,'a');
	printf("%d\n",idx);
	
	printf("----------------------\n");
	printString(test);
	printString(remove);
	
	printf("----------- Replace -----------\n");
	replaceChars(test,remove,'+');
	printString(test);

	printf("------------ Insert ----------\n");
	insertChar(test,'@',3);
	printString(test);
	return 0;
}

void printString(char str[])
{
//	int i;
	printf("%s\n",str);
//	printf("printed as chars: ");
//	for (i=0;i<36;i++)
//	{
//		printf("%c",str[i]);
//	}
	return;
}

char * stringReorder(char str[], int index1, int index2)
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
	
	strcpy(str,temp);
	
	return str;
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
