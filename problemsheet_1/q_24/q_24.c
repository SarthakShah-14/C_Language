/*
 * q_24.c
 *
 *  Created on: 03-Feb-2024
 *      Author: root
 */
#include<stdio.h>
void pattern(int);
int main()
{
	int n;
	printf("Enter N :");
	scanf("%d",&n);
	pattern(n);
	return 0;
}
void pattern(int n)
{
		int i,j,k;
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>i;j--)
			{
				printf("  ");
			}
			for(k=0;k<i+j+1;k++)
			{
				printf("* ");
			}
			printf("\n");

		}
}
