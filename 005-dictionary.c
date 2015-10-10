#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfWordsInDict(char **dict);
void addWord(char **dict, char *word);
void printDict(char **dict);
void removeWord(char **dict, char *word);
void swapWords(char **dict, char *word1, char *word2);

int main ()
{
	
	/**TESTING CORNER**/
	int i;
	int nwords;
	static char *dict[10];
	char *test;
	for (i=0;i<9;i++)
		{dict[i]=NULL;}
	
	char* word;
	char* word2;
	
	///--------------------------------------------///
	//*
	dict[0]="anak";
	dict[1]="kambing";
	dict[2]="saya";
	//*/
	///--------------------------------------------///
	//*
	char op='\0';
	while (1)
	{
		printf("Command (a/p/r/s/q): ");
		if (scanf(" %c",&op)==1)
		{
			switch(op)
			{
				case ('a') : 
				{
					if (word = (char *) malloc(36))
					{
						printf("Add a word: ");
						scanf(" %[^\n]s", word);
						addWord(dict,word);
						free(word);
					}
					
					break;
				}
				case ('p') :
				{
					printDict(dict);
					break;
				}
				case ('r') :
				{
					if (word = (char *) malloc(36))
					{
						printf("Remove a word: ");
						scanf(" %[^\n]s", word);
						removeWord(dict,word);
						free(word);
					}
					break;
				}
				case ('s') :
				{
					if ((word = (char *) malloc(36))&&(word2 = (char *) malloc(36)))
					{
						printf("Swap two words:\n");
						printf("Enter first word: ");
						scanf(" %[^\n]s", word);
						printf("Enter second word: ");
						scanf(" %[^\n]s", word2);
						swapWords(dict,word,word2);
						free(word);
						free(word2);
					}
					break;
				}
				case ('q') :  return 0;
			}
		}
		
	}
	//*/
	///--------------------------------------------///
	
		
	/**TESTING CORNER**/
	//*
	
	//printf("String = %s\n", test);
	
	//addWord(dict,"Babi");
	//addWord(dict,"Enak");
	//printDict(dict);
	dict[0]="Stupid";
	dict[1]="Baka";
	dict[2]="Goublog";
	//removeWord(dict,"Baka");
	//addWord(dict,"Sate");
	
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
	
	int i=0;
	printf("Dictionary:\n");
	
	while (dict[i] != NULL)
	{
		printf("- %s\n",dict[i]);
		i++;	
	}
	
	if(i==0) printf("The dictionary is empty\n");
}

void removeWord(char **dict, char *word)
{
	int i=0;
	int idx=0;
	while (dict[i] != NULL)
	{
		if (strcmp(dict[i],word)==0)
		{
			
			idx=numberOfWordsInDict(dict);
			dict[i]=dict[idx-1];
			//printf("\n\nindex %d : %s\n\n",idx,dict[idx]);
			//printf("\n\nindex %d : %s\n\n",i,dict[i]);
			dict[idx-1]=NULL;
		}
		i++;	
	}
}

void swapWords(char **dict, char *word1, char *word2)
{	
	char*tmp;
	int found=0,found2=0;
	int i=0;
	int idx=999,idx2=999;
	while ((dict[i] != NULL)&&((found!=1)||(found2!=1)))
	{
		if ((found!=1)&&(strcmp(dict[i],word1)==0)) {found=1; idx=i; i=0;}
		if ((found2!=1)&&(strcmp(dict[i],word2))==0) {found2=1; idx2=i; i=0;}
		i++;	
		//printf("\n\nidx found1= %d, idx found2= %d\n\n",found,found2);
	} 
	//printf("%d",i);
	printf("\n\nidx found1= %d, idx found2= %d\n\n",idx,idx2);
	if ((found==0)||(found2==0)) {printf("Cannot swap words. At least one word missing in the dictionary.\n"); return;}
	dict[idx]=NULL;
	addWord(dict,word2);
	dict[idx2]=NULL;
	addWord(dict,word1);
	
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
