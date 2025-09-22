/*
 * q_10.c
 *
 *  Created on: 03-Feb-2024
 *      Author: root
 */

#include<stdio.h>
void asort(int [],int);
void dsort(int [],int);
void input(int [],int);
void output(int [],int);
void aout(int [],int);
void dout(int [],int);
int main(){
	int a[5];
	input(a,5);
	output(a,5);
	asort(a,5);
	aout(a,5);
	dsort(a,5);
	dout(a,5);
	return 0;
}
void input(int a[],int m)
{
	printf("Enter Your Elements");
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
void asort(int a[],int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void dsort(int a[],int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(a[i]<a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void aout(int a[],int m)
{
	printf("\nThe Sorted Array in ascending order is:\n");
	for(int i=0;i<m;i++)
	{
		printf("%d\t",a[i]);
	}
}
void dout(int a[],int m)
{
	printf("\nThe Sorted Array in descending order is:\n");
	for(int i=0;i<m;i++)
	{
		printf("%d\t",a[i]);
	}
}
