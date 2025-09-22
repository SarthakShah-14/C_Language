/*
 * q_16.c
 *
 *  Created on: 09-Feb-2024
 *      Author: root
 */

#include<stdio.h>

struct date{
	int date;
	int month;
	int year;
	int present_date;
	int present_month;
	int present_year;
}e;
int date(int date,int month,int year,int present_date,int present_month ,int present_year)
{

	if(e.date==e.present_date&&e.month==e.present_month&&e.year==e.present_year)
	{
			return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
int n;

			printf("Enter date 1");
			scanf("%d",&e.date);
			printf("Enter Month 1");
			scanf("%d",&e.month);
			printf("Enter Year 1");
			scanf("%d",&e.year);
			printf("Enter date 2");
			scanf("%d",&e.present_date);
			printf("Enter Month 2");
			scanf("%d",&e.present_month);
			printf("Enter Year 2");
			scanf("%d",&e.present_year);

          n= date(e.present_date,e.present_month,e.present_year,e.date,e.month,e.year);
          printf("n=%d\n",n);
          if(n==0)
          {
        	  printf("Equal");
          }
          else
          {
        	  printf("Not Equal");
          }

	return 0;
}
