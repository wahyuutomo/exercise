#include <stdio.h>

void main (void)
{
	char a1, a2, a3;
	printf("Welcome to the game console selection help desk! \n");
	printf("Do you like video games? (y/n) ");
	scanf("%c",&a1);
	getchar();
	printf("You entered: '%c'\n",a1);
	//a1=getchar();
	//getchar();
	
	if (a1=='n')
	{
		printf ("Our Advice: Buy a PC\n");
	
	} 
	else if (a1=='y')
	{
		printf("Do you have any friends? (y/n) ");
		scanf("%c", &a2); getchar();
		printf("You entered: '%c'\n",a2);
		//a2=getchar();
		//getchar();
		if (a2=='n') 
		{
			printf("Our Advice: Buy a PS3 \n");
		} else 
		{
			printf("Do you meet friends offline? (y/n)");
			//scanf("%c \n", &a3);
			a3=getchar();
			getchar();
			printf("You entered: '%c'\n",a3);
			if (a3=='n') 
			{
				printf("Our Advice: Buy a Xbox360 \n");
			} else
			{
				printf("Our Advice: Buy a Wii \n");
			}
		}
	}
	
}
