//add two complex numbers using functions 
#include<stdio.h>
struct complex
{
	float real;
	float imag; 
};

struct complex add(struct complex n1,struct complex n2);
 void main()
 {
 struct complex y,n1,n2;
 scanf("%f",&n1.real);
 scanf("%f",&n1.imag);
 scanf("%f",&n2.real);
 scanf("%f",&n2.imag);
 y=add(n1,n2);
 printf("%f+%fi",y.real,y.imag);

 }
 struct complex add(struct complex n1, struct complex n2)
 {
 struct complex temp;
 temp.real=n1.real+n2.real;
 temp.imag=n1.imag+n2.imag;
 return temp;
 }