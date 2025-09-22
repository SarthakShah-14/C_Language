/*
 * q_9.c
 *
 *  Created on: 03-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int fact(int);
int main(){
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Factorial of %d is %d",n,fact(n));
	return 0;
}
int fact(int n)
{
	int factorial;
	if(n==1)
	{
		return 1;
	}
	else
	{
		factorial=n*fact(n-1);
		return factorial;
	}
}

