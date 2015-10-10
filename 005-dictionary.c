
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfWordsInDict(char **dict);
void addWord(char **dict, char *word);
void printDict(char **dict);

int main ()
{
	
	/**TESTING CORNER**/
	//*
	char test[34]="Hello World";

	//*/

	int i;
	int nwords;
	static char **dict;
	
	dict = (char **) malloc (10);
	for (i=0;i<10;i++)
	{dict[i]=NULL;}
	
	nwords = 0;
	
	
	/**TESTING CORNER**/
	//*
	
	//printf("String = %s\n", test);
	
	//addWord(dict,"Babi");
	//addWord(dict,"Enak");
	//dict[0]="Stupid";
	//dict[1]="Baka";
	//addWord(dict,"Sate");
	//dict[2]="Goublog";
	//dict[3]="Wancur";
	//printf("%s\n",dict[0]);
	//printf("%s\n",dict[1]);github
	
	printDict(dict);
	
	nwords=numberOfWordsInDict(dict);
	printf("number of words = %d\n",nwords);
	//*/



	return 0;
}

int numberOfWordsInDict(char **dict)
{
	int i, nstring;
	i=0;
	nstring=0;
	
	while(dict[i]!=NULL)
	{
		//*
		nstring=nstring+1;
		
		i++;
		//*/
		//if (*(dict[i])=='\0') nstring=nstring+1;
		//i++;
	}

	return nstring;
}

void addWord(char **dict, char *word)
{
	int idx;
	idx = numberOfWordsInDict(dict);
	if (idx!=9)
	{
		dict[idx]=word;
	} else 
	{
		printf("Dictionary is already full!! The word could not be added.\n");
	}
}

void printDict(char **dict)
{
	
	char *word;
	int i=0;
	printf("Dictionary:\n");
	
	while (dict[i] != NULL)
	{
		printf("- %s\n",dict[i]);
		i++;	
	}
	
	if(i==0) printf("The dictionary is empty\n");
}
