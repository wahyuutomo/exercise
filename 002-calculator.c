#include <stdio.h>
#include <stdlib.h>

int main ()
{	
	int value;
	float result;
	char operator;
	
	result=0;
	printf("** Calculator **\n");
	
	while (1)
	{
		printf("Value? ");
		scanf("%d",&value);
		printf("Input: %d\n",value);		
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
