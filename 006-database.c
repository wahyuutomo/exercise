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
void removeCarinfo(struct carinfo_t **carbase, struct carinfo_t *carinfo);

int ncar=0;

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
	/*/
	for(i=0;i<33;i++){
		carinfo = createCarinfo("1", "1", 1, 350.25);
		addCarinfo(carbase,carinfo);
		carinfo = createCarinfo("1", "1", 2, 350.25);
		addCarinfo(carbase,carinfo);
		carinfo = createCarinfo("1", "1", 3, 350.25);
		addCarinfo(carbase,carinfo);
		}
	//*/
	//*
	char op='\0';
	while (1)
	{
		//printf("ncar = %d\n",ncar);
		printf("Command (a/r/p/q): ");
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
					//carinfo = createCarinfo("Opel", "Manta", 1988, 350.25);
					carinfo = createCarinfo(brand,model,year,value);
					
					addCarinfo(carbase,carinfo);
					//ncar=ncar+1;
					//freeCarinfo(carinfo);
					break;
				}
				case ('p') :
				{
					printCarbase(carbase);
					break;
				}
				case ('r') :
				{
					printf("Remove a car:\n");
					printf("brand: ");
					scanf(" %[^\n]s", brand);
					printf("model: ");
					scanf(" %[^\n]s", model);
					printf("year: ");
					scanf(" %d", &year);
					carinfo = createCarinfo(brand,model,year,0);
					
					removeCarinfo(carbase,carinfo);
					ncar=ncar-1;
					
					break;
				}
				case ('q') : return 0;
			}
		}
		
	}
	//*/
	
	
	
	
	//printCarbase(carbase);
	//addCarinfo(carbase,carinfo);
	//printCarbase(carbase);
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
	
	//printf("YOLO\n");
	struct carinfo_t *carinfo;
	carinfo = (struct carinfo_t *) malloc (sizeof(struct carinfo_t));
	carinfo->brand=(char *) malloc (sizeof(char)*(strlen(brand)+1));
	carinfo->model=(char *) malloc (sizeof(char)*(strlen(model)+1));
	strcpy(carinfo->brand,brand);
	strcpy(carinfo->model,model);
	carinfo->year = year;
	carinfo->value 	= value;
	//free(carinfo->brand);
	//freeCarinfo(carinfo);
	//printf("carinfo->brand = %s\n",carinfo->brand);
	return carinfo;
}

void addCarinfo(struct carinfo_t **carbase, struct carinfo_t*carinfo)
{
	int n=0;
	n=numberOfCarInfo(carbase);
	
	if (ncar<100){
		
		carbase[n] = carinfo;
		ncar=ncar+1;	
		/*/
		//carbase[n]->brand = (char *) malloc (sizeof(char)*(strlen(carinfo->brand)+1));
		//carbase[n]->model = (char *) malloc (sizeof(char)*(strlen(carinfo->model)+1));
		strcpy(carbase[n]->brand,carinfo->brand);
		strcpy(carbase[n]->model,carinfo->model);
		carbase[n]->year = carinfo->year;
		carbase[n]->value = carinfo->value;
		//*/
		//carbase[n]=createCarinfo(carinfo->brand, carinfo->model, carinfo->year, carinfo->value);
	} else {printf("Failed adding car; carbase is already full!"); return;}
}

int numberOfCarInfo(struct carinfo_t **carbase)
{
	
	int i=0;
	while(carbase[i]!=NULL) {i++;}
	return i;
	
}

void freeCarinfo(struct carinfo_t *carinfo)
{
	//printf("Free Car Info!\n");
	//*
	if (carinfo != NULL) 
	{
		free(carinfo->brand);
		free(carinfo->model);
		free(carinfo);
		//carinfo->brand=NULL;	  	
		//carinfo->model=NULL;
		//carinfo=NULL;
	}
	//*/
}

void printCarbase(struct carinfo_t **carbase)
{
	int i = 0;
	int empty = 0;
	while (i<100)
	{
		if (carbase[i]!=NULL)
		{
			printf("Car:\n");
			printf("- brand: %s\n",carbase[i]->brand);
			printf("- model: %s\n",carbase[i]->model);
			printf("- year: %d\n",carbase[i]->year);
			printf("- value: %.2f\n",carbase[i]->value);
			empty=1;
		}
		i++;	
	}
	
	if (empty==0)
	{
		printf("The database is empty.\n");
	}
	
	/*/
	if (carbase[0]==NULL) {printf("The database is empty.\n");}
	int n=0,i;
	n=numberOfCarInfo(carbase);
	for (i=0;i<n;i++)
	{
		printf("Car:\n");
		printf("- brand: %s\n",carbase[i]->brand);
		printf("- model: %s\n",carbase[i]->model);
		printf("- year: %d\n",carbase[i]->year);
		printf("- value: %.2f\n",carbase[i]->value);
	}
	//*/
}

void removeCarinfo(struct carinfo_t **carbase, struct carinfo_t *carinfo)
{
	struct carinfo_t *temp;
	//int n=numberOfCarInfo(carbase);
	int i;
	for (i=0;i<100;i++)
	//while (i<100)
	{
		if (carbase[i]!=NULL)
		{
			if ((strcmp(carbase[i]->brand,carinfo->brand)==0)&&(strcmp(carbase[i]->brand,carinfo->brand)==0)&&(carbase[i]->year==carinfo->year))
				{
					//printf("FOUND!! %d\n",i);
					freeCarinfo(carbase[i]);
					//printf("after freecar info: \n");
					
					carbase[i] = NULL;
					//n=n-1;
					//i=0;
					//createCarinfo
					//freeCarinfo(carbase[n-1]);
					
					//printf("found\n");
					
				}
			//else {i++;}
		}
	}
}
