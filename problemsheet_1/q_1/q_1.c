#include<stdio.h>
#include<string.h>
#define size 10
struct census
{
	char city[20];
	int population;
	float literacy;
};
int main()
{

	int i,j;
	struct census c[10],temp;


	//-To read details for 10 city
	for(i=0;i<size;i++)
	{
		printf("Enter %d city name:\n",i+1);
		scanf("%s",c[i].city);
		printf("Enter %d city population:\n",i+1);
		scanf("%d",&c[i].population);
		printf("Enter %d city literacy level:\n",i+1);
		scanf("%f",&c[i].literacy);
	}
	printf("The list which is given in input is:");
	printf("\ncity\tpopulation\tliteracy\n");
	for(i=0;i<size;i++)
	{
		printf("%s\t%d\t%f\n",c[i].city,c[i].population,c[i].literacy);
	}

	//- To sort the list alphabetically
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(strcmp(c[i].city,c[j].city)>0)
			{
				temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}

		}
	}
	printf("The sorted list of city is:");
	printf("\ncity\tpopulation\tliteracy\n");
		for(i=0;i<size;i++)
		{
			printf("%s\t%d\t%f\n",c[i].city,c[i].population,c[i].literacy);
		}

		//sorting literacy
		for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(c[i].literacy>c[j].literacy)
						{
							temp=c[i];
							c[i]=c[j];
							c[j]=temp;
						}
			}
		}

		printf("The  sorted list based on literacy");
		printf("\ncity\tpopulation\tliteracy\n");
				for(i=0;i<size;i++)
				{
					printf("%s\t%d\t%f\n",c[i].city,c[i].population,c[i].literacy);
				}

				//sorting population
				for(i=0;i<size;i++)
						{
							for(j=i+1;j<size;j++)
							{
								if(c[i].population>c[j].population)
										{
											temp=c[i];
											c[i]=c[j];
											c[j]=temp;
										}
							}
						}


						printf("The  sorted list based on population is:");
						printf("\ncity\tpopulation\tliteracy\n");
								for(i=0;i<size;i++)
								{
									printf("%s\t%d\t%f\n",c[i].city,c[i].population,c[i].literacy);
								}

		return 0;
}
