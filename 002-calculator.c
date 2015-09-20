#include <stdio.h>
#include <stdlib.h>

int main ()
{	
	int value;
	float result;
	char operator,choice;
	
	result=0;
	printf("** Calculator **\n");
	
	while (1)
	{
		printf("Binary or decimal? (b/d) ");
		scanf(" %c", &choice); getchar();
		
		switch (choice)
		{
			case ('b') :
				{
					printf("Value? ");
					value = read_binary_value();
					printf("Input: %d\n",value);
					break;
				}
			case ('d') :
				{
					printf("Value? ");
					scanf(" %d", &value);
					//show input
					printf("Input: %d\n",value);
					break;
				}
			default : value=0; break;
		}		
		printf("Operation? ");
		scanf(" %c",&operator);
		switch (operator)
		{
			case ('+'): result = result + value; break;
			case ('-'): result = result - value; break;
			case ('*'): result = result * value; break;
			case ('/'): result = result / value; break;
			case ('c'): result = 0; break;
			case ('='): printf("Result = %.2f\n",result); exit(0); break;
		}
		printf("Result = %.2f\n",result);
	}
}

int read_binary_value()
{
	int value = 0, i=0, j=0;
	for (i=0;i<16;i++)
	{
		value = value * 2;
		scanf(" %1d", &j);
		value = value + j;	
	}
	return value;
}
