/*
 * q_5.c
 *
 *  Created on: 03-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int leap(int);
int main()
{
	int year;
	printf("Enter The Year you want to check ");
	scanf("%d",&year);
	if(leap(year)==0)
	{
		printf("%d is a leap year",year);
	}
	else
	{
		printf("%d is not a leap year",year);
	}
}
int leap(int n)
{
	if(n%4==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

