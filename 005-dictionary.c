#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfWordsInDict(char **dict);
void addWord(char **dict, char *word);
void printDict(char **dict);
void removeWord(char **dict, char *word);
void swapWords(char **dict, char *word1, char *word2);
void sortDict(char **dict);

int main ()
{
	
	/**TESTING CORNER**/
	int i;
	static char *dict[10];
	
	for (i=0;i<9;i++)
		{dict[i]=NULL;}
	
	char* word;
	char* word2;
	
	///--------------------------------------------///
	/*
	dict[0]="apple";
	dict[1]="union";
	dict[2]="apple";
	dict[3]="orange";
	//dict[4]="yakin";
	//dict[5]="duku";
	//*/
	///--------------------------------------------///
	//*
	char op='\0';
	while (1)
	{
		printf("Command (a/r/s/p/o/q): ");
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
				case ('o') :
				{
					sortDict(dict);
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
	//dict[0]="Stupid";
	//dict[1]="Baka";
	//dict[2]="Goublog";
	//removeWord(dict,"Baka");
	//addWord(dict,"Sate");
	
	//dict[3]="Wancur";
	//printf("%s\n",dict[0]);
	//printf("%s\n",dict[1]);
	
	//printDict(dict);
	
	//nwords=numberOfWordsInDict(dict);
	//printf("number of words = %d\n",nwords);
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
	
	//free(mem);
	
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
		mem = (char *) malloc(sizeof(char)*(strlen(word)+1));
		dict[idx]=mem;
		strcpy(dict[idx],word);
		

		//printDict(dict);
		return;
		
		//printf("Idex %d contains word= %s\n",idx, dict[idx]);
	} else 
	{
		printf("Dictionary is already full! The word could not be added.\n");
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
	
	if(i==0) printf("The dictionary is empty.\n");
}

void removeWord(char **dict, char *word)
{
	int i=0;
	int idx=0;
	int found=0;
	while ((dict[i] != NULL) && (found!=1))
	{
		if (strcmp(dict[i],word)==0)
		{
			
			idx=numberOfWordsInDict(dict);
			dict[i]=dict[idx-1];
			//printf("\n\nindex %d : %s\n\n",idx,dict[idx]);
			//printf("\n\nindex %d : %s\n\n",i,dict[i]);
			dict[idx-1]=NULL;
			found=1;
		}
		i++;	
	}
}

void swapWords(char **dict, char *word1, char *word2)
{	
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
	//printf("\n\nidx found1= %d, idx found2= %d\n\n",idx,idx2);
	if ((found==0)||(found2==0)) {printf("Cannot swap words. At least one word missing in the dictionary.\n"); return;}
	dict[idx]=NULL;
	addWord(dict,word2);
	dict[idx2]=NULL;
	addWord(dict,word1);
	
}

void sortDict(char **dict)
{
	char *word;
	int n,k=0;
	int i=0,j=0;
	n=numberOfWordsInDict(dict);
	k=n;
	for (i=0;i<n-1;i++)
	{
		//printf("\n\ndict[%d] = %s\n",i,dict[i]);
		//printf("dict[%d] = %s\n\n",i+1,dict[i+1]);
		//*/
		for (j=0;j<k-1;j++)
		{
			//printf("\nj= %d\n",j);
			
			if (strcmp(dict[j],dict[j+1])>0)
			{
				//printf("\nj= %d\n",j);
				//printf("\ndict[%d] = %s\n",j,dict[j]);
				//printf("dict[%d] = %s\n",j+1,dict[j+1]);
				//swapWords(dict,dict[j],dict[j+1]);
				//printf("sorted: \n");
				
				//k++;
				//printf("\n%d\n",j);
				word=(char *)malloc(sizeof(char)*(strlen(dict[j])+1));
				strcpy(word,dict[j]);
				//realloc(dict[j],sizeof(char)*(strlen(dict[j+1])+1));
				//strcpy(dict[j],dict[i+1]);
				//realloc(dict[j+1],sizeof(char)*(strlen(word)+1));
				//strcpy(dict[j+1],word);
				dict[j]=NULL;
				addWord(dict,dict[j+1]);
				dict[j+1]=NULL;
				addWord(dict,word);
				//free(word);
				//printf("%s",word);
				//strcpy(dict[i],dict[i+1]);
				//strcpy(dict[i+i],word);
				//printDict(dict);
			}
			//printf("\n%d\n",i);
		}
		k--;
		//printf("\n%d\n",i);
		//*/
	}
	//printDict(dict);
	return;
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
