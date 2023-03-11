#include<stdio.h>
#include<stdlib.h>
void main()
{
	int max=0;
	int *ptr;
	printf("enter the num of elems: ");
	scanf("%d", &max);
	ptr=(int *)(malloc(max*(sizeof(int))));
	printf("enter elements\n");
	for(int i=0; i<max;i++)
	{
	scanf("%d",ptr+i);
	}
	for(int i=0;i<max;i++)
	{
	printf("%d", *(ptr+i));
}
free(ptr);
}