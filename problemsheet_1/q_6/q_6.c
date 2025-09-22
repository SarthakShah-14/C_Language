/*
 * q_6.c
 *
 *  Created on: 06-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int sum(int);
int main()
{
	int N;
	printf("Enter N:");
	scanf("%d",&N);
	printf("SUM of %d is %d",N,sum(N));
	return 0;
}
int sum(int n)
{
	int sum=0,r=0;
	while(n>0)
	{
		r=n%10;
		sum=sum+r;
		n=n/10;
	}
	return sum;
}

