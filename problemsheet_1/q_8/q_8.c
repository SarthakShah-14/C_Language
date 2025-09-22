/*
 * q_8.c
 *
 *  Created on: 06-Feb-2024
 *      Author: root
 */
#include<stdio.h>
int isArmstrong(int);
int cube(int);
int main()
{
	int n;
	printf("Enter N:");
	scanf("%d",&n);
	int f=isArmstrong(n);
	if(f==0)
	{
		printf("%d is Armstrong number",n);
	}
	else
	{
		printf("%d is not an Armstrong number",n);
	}
	return 0;
}
int cube(int a)
{
	int c=1;
	for(int i=0;i<3;i++)
	{
		c=c*a;
	}
	return c;
}
int isArmstrong(int n)
{
	int num=n,cnt=0, sum=0;
	while(n>0)
	{
		n=n/10;
		cnt++;
	}
	n=num;
	for(int i=0;i<cnt;i++)
	{
		int r=n%10;
		n=n/10;
		sum=sum+cube(r);
	}
	if(sum==num)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

