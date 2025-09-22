/*
 * q_11.c
 *
 *  Created on: 03-Feb-2024
 *      Author: root
 */
#include<stdio.h>
void asort(int m,int n,int t[m][n]);
void dsort(int m,int n,int t[m][n]);
void input(int m,int n,int t[m][n]);
void output(int m,int n,int t[m][n]);
void aout(int m,int n,int t[m][n]);
void dout(int m,int n,int t[m][n]);

int main()
{
	int t[3][3];
	input(3,3,t);
	output(3,3,t);
	asort(3,3,t);
	aout(3,3,t);
	dsort(3,3,t);
	dout(3,3,t);
	return 0;
}
void input(int m,int n,int t[m][n])
{
	printf("Enter Your Elements");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&t[i][j]);
		}
	}
}
void output(int m,int n,int t[m][n])
{
	printf("\nThe Array is:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}
void asort(int m,int n,int t[m][n])
{
	int k;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
			if(t[i][j]>t[i][k])
			{
				int temp=t[i][j];
				t[i][j]=t[i][k];
				t[i][k]=temp;
			}
			}
		}
	}
}
void aout(int m,int n,int t[m][n])
{
	printf("The Sorted array in ascending order is:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{

				printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}


void dsort(int m,int n,int t[m][n])
{
	int k;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
			if(t[i][j]<t[i][k])
			{
				int temp=t[i][j];
				t[i][j]=t[i][k];
				t[i][k]=temp;
			}
			}
		}
	}
}
void dout(int m,int n,int t[m][n])
{
	printf("The Sorted array in descending order is:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{

				printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}


