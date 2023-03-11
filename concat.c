#include<stdio.h>
#define MAXSIZE 100
int main()
{
	char str1[MAXSIZE],str2[MAXSIZE];
	char *s1=str1;
	char *s2=str2;
	printf("enter first str: ");
	gets(str1);
	printf("enter sencond str: ");
	gets(str2);
	while(*(++s1));
	while(*(s1++)=*(s2++));
	printf("%s",str1);
	return 0;

}