/*
 * q_7.c
 *
 *  Created on: 06-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int isPrime(int);
int main()
{
	int flag=0,n;
	printf("Enter the no n");
	scanf("%d",&n);
	flag=isPrime(n);
	if(flag==0)
	{
		printf("Prime No ");
	}
	else
	{
		printf("Not A prime no");
	}
	return 0;
}
int isPrime(int n)
{
	int i=2;
	for( i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return 1;
		}
	}
	return 0;
}

