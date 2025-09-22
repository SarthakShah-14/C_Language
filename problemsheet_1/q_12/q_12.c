/*
 * q_12.c
 *
 *  Created on: 06-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int min(int [],int);
int max(int [],int);
void input(int [],int);
void output(int [],int);
int main()
{
	int a[5];
	input(a,5);
	output(a,5);
	printf("\nThe maximum no in the array is: %d\nThe minimum no in the array is: %d",max(a,5),min(a,5));
	return 0;
}
int min(int a[],int size)
{
	int mini;
	mini=a[0];
	for(int i=1;i<size;i++)
	{
		if(mini>a[i])
		{
			mini=a[i];
		}
	}
	return mini;
}
int max(int a[],int size)
{
	int maxi;
	maxi=a[0];
	for(int i=1;i<size;i++)
	{
		if(maxi<a[i])
		{
			maxi=a[i];
		}
	}
	return maxi;
}
void input(int a[],int m)
{
	printf("Enter the Elements");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
}
void output(int a[],int m)
{
	printf("\nThe Array is:\n");
	for(int i=0;i<m;i++)
	{
		printf("%d\t",a[i]);
	}
}
