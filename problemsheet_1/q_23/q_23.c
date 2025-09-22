/*
 * q_23.c
 *
 *  Created on: 13-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int amstrong(int);
int main()
{
	int n;
	printf("Enter number :");
	scanf("%d",&n);
	int ams = amstrong(n);
		if(ams == 1)
		{
			printf("%d is Amstrong number.\n",n);
		}
		else
		{
			printf("%d is not Amstrong number.\n",n);
		}
	return 0;
}
int amstrong(int n)
{
	int summ = n;
	int sum = 0;
	while(n>0)
	{
		int r = n % 10;
		sum = sum + (r*r*r);
		n = n /10;
	}
	if(sum == summ)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

