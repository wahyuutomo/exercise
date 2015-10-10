
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfWordsInDict(char **dict);
void addWord(char **dict, char *word);
void printDict(char **dict);

int main ()
{
	
	/**TESTING CORNER**/
	/*
	char *mem;
	
	char *string="teas";
	mem = (char *) malloc(sizeof(char)*strlen(string));
	//strcpy(mem,string);
	//printf("String = %s,  Address = %u\n", mem, mem);
	//*/

	int i;
	int nwords;
	static char *dict[10];
	char *test;
	for (i=0;i<9;i++)
		{dict[i]=NULL;}
	/*
	if (dict = (char **) malloc (10))
	{
		
		for (i=0;i<9;i++)
		{dict[i]=NULL;}
	}
	dict[0]="Stupid";
	dict[1]="Baka";
	char *string="teas";
	//*/
		
	nwords = 0;

	char* words;
	
	///--------------------------------------------///
	
	char op='\0';
	while (1)
	{
		
	//	printDict(dict);
		printf("Command (a/p/q): ");
		if (scanf(" %c",&op)==1)
		{
			switch(op)
			{
				case ('a') : 
				{
					//free(test);
					//test = malloc(20);
					if (words = (char *) malloc(36))
					{
						printf("Add a word: ");
						scanf(" %[^\n]s", words);
						addWord(dict,words);
						free(words);
					}
					
					break;
				}
				case ('p') :
				{
					printDict(dict);
					break;
				}
				case ('q') :  return 0;
			}
		}
		
	}
	///--------------------------------------------///
	
		
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
	//printf("%s\n",dict[1]);
	
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
	char *mem;
	int r=0;

	
	//free(mem);
	mem = (char *) malloc(sizeof(char)*(strlen(word)+1));
//	while(word[r]!='\0')
//	{
//		mem[r]=word[r];
//		r++;
//	}
//		mem[r]='\0';
	//mem = (char *) malloc(15);
	idx = numberOfWordsInDict(dict);
	
	if (idx!=10)
	{
	//	printf("Idex = %d\n",idx);
		//printDict(dict);
		dict[idx]=mem;
		strcpy(dict[idx],word);

		//printDict(dict);
		return;
		
		//printf("Idex %d contains word= %s\n",idx, dict[idx]);
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


///-------------------TEMPLATE COMMAND-----------------------///
	/*
	char op='\0';
	while (1)
	{
		printf("Command (p/g/r/s/q): ");
		if (scanf(" %c",&op)==1)
		{
			switch(op)
			{
				case () : break;
				case ('q') : return 0;
			}
		}
		
	}
	//*/
///---------------------------------------------------------///
