
#include <stdio.h>
#include <stdlib.h>


#define SIZE 10

void printValues(float *values, int size);
float largestElement(float *values, int size);
void replaceElement(float *values, int i, float v);
void sortOnValue(float *values, int size);

int main (void)
{
	float myArray[SIZE] = {1.5,2.2,7.3,9.2,7.4,7.5,-8.0,1.5,12};
	int i;
	float f;
	char op;
	
	
	
	while (1)
	{
		printf("Command (p/g/r/s/q): ");
		scanf(" %c",&op);
		switch (op)
		{
			case 'p' :
			{
				printValues(myArray, SIZE);
				break;
			}
			case 'g' :
			{
				printf("Max: %0.3f\n", largestElement(myArray, SIZE));
				break;
			}
			case 'r' :
			{
				printf("Replace (element,value): ");
				scanf("%d, %f",&i, &f);
				replaceElement(myArray, i,f);
				break;
			}
			case 's' :
			{
				sortOnValue(myArray, SIZE);
				break;
			}
			case 'q' : exit(1); break;
			
		}
	}
	
}

void printValues(float *values, int size)
{
	int i;
	printf("Value: ");
	for (i=0;i<size-1;i++)
	{
		printf("%0.3f, ",values[i]);
	}
	printf("%0.3f\n",values[i]);
	return;
}

float largestElement(float *values, int size)
{
	int i;
	float n;
	n=values[0];
	
	for (i=0;i<size;i++)
	{
		if (n<values[i]) n=values[i];
	}
	
	return n;
}

void replaceElement(float *values, int i, float v)
{
	values[i]=v;
	return;	
}

void sortOnValue(float *values, int size)
{
	int i,j,k;
	float f;
	//f=values[0];
	k=size;
	
	for(j=0;j<size;j++)
	{
		for(i=0;i<k-1;i++)
		{
			if (values[i]>values[i+1])
			{
				f = values[i+1];
				values[i+1] = values[i];
				values[i]=f;
				//printf("\n F = %0.2f ",f);
			}
			//printf("------------------------------ %d\n",i);
			//printValues(values, SIZE);
			//printf("------------------------------\n");
		}
		k--;
		//printValues(values, SIZE);
	}
}
