/*
 * q_14.c
 *
 *  Created on: 09-Feb-2024
 *      Author: root
 */
#include<stdio.h>

struct age{
	int present_date;
	int present_month;
	int present_year;
	int birth_date;
	int birth_month;
	int birth_year;
}e;
void age(int present_date,int present_month,int present_year,int birth_date,int birth_month,int birth_year)
{
	int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(e.birth_date>e.present_date)
	{
		e.present_date=e.present_date+month[e.birth_month-1];
	}
	if(e.birth_month>e.present_month)
	{
		e.present_year=e.present_year-1;
		e.present_month=e.present_month+12;
	}
	int final_date=e.present_date-e.birth_date;
	int final_month=e.present_month-e.birth_month;
	int final_year=e.present_year-e.birth_year;

	printf("Present age Years:%d Months:%d Days:%d",final_year,final_month,final_date);
}
int main()
{
	printf("Enter Birth Date");
	scanf("%d",&e.birth_date);
	printf("Enter Birth Month");
	scanf("%d",&e.birth_month);
	printf("Enter Birth Year");
	scanf("%d",&e.birth_year);
	printf("Enter Present Date");
	scanf("%d",&e.present_date);
	printf("Enter Present Month");
	scanf("%d",&e.present_month);
	printf("Enter Present Year");
	scanf("%d",&e.present_year);

	if(e.birth_year>=1000&&e.present_year<=9999&&e.birth_month>=1&&e.birth_month<=12&&e.birth_date>=1&&e.birth_date<=31&&e.present_date>=1&&e.present_date<=31&&e.present_month>=1&&e.present_month<=12&&e.present_year>=1000&&e.present_year<=9999)
	{
		age(e.present_date,e.present_month,e.present_year,e.birth_date,e.birth_month,e.birth_year);
	}
	else{
		printf("Date,month or year in negative not possible or greater than their limit not possible");
	}
		return 0;
}

