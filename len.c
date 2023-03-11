#include<stdio.h>
#define MAXSIZE 100
int main()
{
	char a[MAXSIZE];
	 int i;
	 int count=0;
	 printf("enter a string");
	 gets(a);
	while(a[++i]!='\0');
	 printf("length of %s=%d",a,i);
	 return 0;
}