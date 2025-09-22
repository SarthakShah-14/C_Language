/*
 * q_13.c
 *
 *  Created on: 09-Feb-2024
 *      Author: root
 */
#include<stdio.h>
void input(int m,int n,int a[m][n]);
void output(int m,int n,int a[m][n]);
int min(int m,int n,int a[m][n]);
int max(int m,int n,int a[m][n]);
int main(){
	int a[3][3];
	input(3,3,a);
	output(3,3,a);
	printf("\nThe maximum : %d\nThe minimum : %d",max(3,3,a),min(3,3,a));
	return 0;
}
void input(int m,int n,int a[m][n])
{
	printf("Enter Your Elements");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void output(int m,int n,int a[][n])
{
	printf("\nThe Array is:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
		printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
int min(int m,int n,int a[][n])
{
	int mini=a[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mini>a[i][j])
			{
				mini=a[i][j];
			}
		}
	}
	return mini;
}
int max(int m,int n,int a[][n])
{
	int maxi=a[0][0];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(maxi<a[i][j])
			{
				maxi=a[i][j];
			}
		}
	}
	return maxi;
}

