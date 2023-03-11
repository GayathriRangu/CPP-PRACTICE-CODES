#include<stdio.h>
 int plus(int a, int b)
 {
  int c=0;
  c=a+b;
  return c;
 }

 int minus(int a,int b)
 {
 int c=0;
 c=a-b;
 return c;
 }
  
 int divide(int a, int b)
{
	int c=0;
	c=a/b;
	return c;
}

int multiply(int a, int b)
{
	int c=0;
	c=a*b;
	return c;
}
 
void main()
{
	int sum=0,a=0,b=0;
	int choice;
	scanf("%d\n",&choice);
	printf("%d is ur choice\n",choice);
	int (*arr[4])(int,int); //declaration of array of function pointers
	arr[0]=plus;
	arr[1]=minus;
	arr[2]=divide;
	arr[3]=multiply;
	printf("enter two nums\n");
	scanf("%d\n", &a);
	scanf("%d\n",&b);
	sum=(*arr[choice])(a,b);//calling the function
	printf("%d",sum);
}