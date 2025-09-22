#include<stdio.h>
void astrcat(char *,char *);
int main()
{

	char s[20];
	char s2[10];
	printf("Enter String 2 : ");
	scanf("%s",s2);
	printf("Enter String  : ");
	scanf("%s",s);
	 astrcat(&s[0],&s2[0]);
	 printf("\n %s",s);
	return 0;
}
void astrcat(char *p1,char *p2)
{
	while(*p1!='\0')
	{
		p1++;
	}
	while(*p2!='\0')
	{
		*p1=*p2;
		p2++;
		p1++;
	}

	*p1='\0'; // add *before p1

}