#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 100	

struct carinfo_t
{
	char *brand;
	char *model;
	int year;
	float value;
};

struct carinfo_t *createCarinfo(char *brand, char *model, int year, float value);
void addCarinfo(struct carinfo_t **carbase, struct carinfo_t*carinfo);
int numberOfCarInfo(struct carinfo_t **carbase);
void freeCarinfo(struct carinfo_t *carinfo);
void printCarbase(struct carinfo_t **carbase);

int main ()
{
	
	int i;
	struct carinfo_t *carbase[max_size];
	for (i=0;i<max_size;i++)
	{carbase[i]=NULL;}
	
	char brand[35]; 
	char model[35];
	int year;
	float value;
	
	struct carinfo_t *carinfo;
	
	//*
	char op='\0';
	while (1)
	{
		printf("Command (a/p/q): ");
		if (scanf(" %c",&op)==1)
		{
			switch(op)
			{
				case ('a') : 
				{
					printf("Add a car:\n");
					printf("brand: ");
					scanf(" %[^\n]s", brand);
					printf("model: ");
					scanf(" %[^\n]s", model);
					printf("year: ");
					scanf(" %d", &year);
					printf("value: ");
					scanf(" %f", &value);
					//struct carinfo_t *carinfo = createCarinfo("Opel", "Manta", 1988, 350.25);
					carinfo = createCarinfo(brand,model,year,value);
					addCarinfo(carbase,carinfo);
					break;
				}
				case ('p') :
				{
					printCarbase(carbase);
					break;
				}
				case ('q') : return 0;
			}
		}
		
	}
	//*/
	
	
	
	
	printCarbase(carbase);
	addCarinfo(carbase,carinfo);
	printCarbase(carbase);
	///----------------------------------------------------------///
	/*
	int n;
	n=numberOfCarInfo(carbase);
	//printf("number of carbase = %d\n",n);

	
		carbase[0]=(struct carinfo_t*)malloc(sizeof(struct carinfo_t));
		//printf("TESTINGMONI\n");
		
		carbase[0]->brand = (char *) malloc (sizeof(strlen(carinfo->brand)+1));
		carbase[0]->model = (char *) malloc (sizeof(strlen(carinfo->model)+1));

		strcpy(carbase[0]->brand,carinfo->brand);
		strcpy(carbase[0]->model,carinfo->model);
			
		carbase[0]->year = carinfo->year;
		carbase[0]->value = carinfo->value;
	
		printf("Car:\n");
		printf("- brand: %s\n",carbase[0]->brand);
		printf("- model: %s\n",carbase[0]->model);
		printf("- year: %d\n",carbase[0]->year);
		printf("- value: %f\n",carbase[0]->value);
	//*/	
	
	///----------------------------------------------------------///
	
}

struct carinfo_t *createCarinfo(char *brand, char *model, int year, float value)
{
	
	struct carinfo_t *carinfo;
	carinfo->brand=(char *) malloc (45);
	printf("debug\n");
	carinfo->model=(char *) malloc (sizeof(strlen(model)+1));
	strcpy(carinfo->brand,brand);
	strcpy(carinfo->model,model);
	carinfo->year = year;
	carinfo->value 	= value;
	return carinfo;
}

void addCarinfo(struct carinfo_t **carbase, struct carinfo_t*carinfo)
{
	int n=0;
	n=numberOfCarInfo(carbase);
	
	if (n<100){
		carbase[n] = (struct carinfo_t*)malloc(sizeof(struct carinfo_t));	
		carbase[n]->brand = (char *) malloc (sizeof(strlen(carinfo->brand)+1));
		carbase[n]->model = (char *) malloc (sizeof(strlen(carinfo->model)+1));
		strcpy(carbase[n]->brand,carinfo->brand);
		strcpy(carbase[n]->model,carinfo->model);
		carbase[n]->year = carinfo->year;
		carbase[n]->value = carinfo->value;
	} else {printf("Failed adding car; carbase is already full!\n"); return;}
}

int numberOfCarInfo(struct carinfo_t **carbase)
{
	
	int i=0;
	while(carbase[i]!=NULL) {i++;}
	return i;
	
}

void freeCarinfo(struct carinfo_t *carinfo)
{
	free(carinfo->brand);	  	
	free(carinfo->model);
	free(carinfo);
}

void printCarbase(struct carinfo_t **carbase)
{
	if (carbase[0]==NULL) {printf("The database is empty.\n");}
	int n=0,i;
	n=numberOfCarInfo(carbase);
	for (i=0;i<n;i++)
	{
		printf("Car:\n");
		printf("- brand: %s\n",carbase[i]->brand);
		printf("- model: %s\n",carbase[i]->model);
		printf("- year: %d\n",carbase[i]->year);
		printf("- value: %f\n",carbase[i]->value);
	}
}
