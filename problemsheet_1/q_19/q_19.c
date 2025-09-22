/*
 * q_19.c
 *
 *  Created on: 10-Feb-2024
 *      Author: root
 */
#include<stdio.h>
void fibonacci(int);
int main()
{
	int n;
	printf("Enter Number :");
	scanf("%d",&n);
	printf("Fibonacci series :");
	fibonacci(n);
	return 0;
}
void fibonacci(int n)
{
	int a = 0;
	int b = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		printf("%d ",a);
		int c = a + b;
		a = b;
		b = c;
	}
}


