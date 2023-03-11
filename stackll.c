#include<stdio.h>
#include<stdlib.h>
struct stacknode 
{
	int data;
	struct stacknode *next;
};
//top is the new head in stacks.
//top can be declared in here which will make it accessible throughout all the functions but not a safe practice
//so declare it inside the  main
int count;
void push(struct stacknode **top,int x)
{
	struct stacknode *s=(struct stacknode *)malloc(sizeof(struct stacknode));
	printf("inserting\n");
	if(!top)
		printf("heap overflow");
	//these are the main lines of code for pushing element
	s->data=x;
	s->next=*top;
	*top=s;
	count++;
	//no need to return anything cuz pass by reference is used here
}

int isempty(struct stacknode *top)
{
	return top==NULL;
}

int peek(struct stacknode *top)
{
	if(!isempty(top))
		return top->data;
	//here, only value is being passed, cuz we dont want to change its value. No need of double pointers.
else
	printf("empty stack\n");

}

int pop(struct stacknode **top)
{
	struct stacknode *s;
	//stack underflow
	if(*top==NULL)
	{
		printf("stack underflow\n");
		return 0;
	}
int x=peek(*top);
printf("removing");
s=*top;
*top=(*top)->next;
count--;
free(s);
return x;



}




int main()
{
	struct stacknode *top=NULL;//this is a local variable so if it has to be accessed by other functions, it has to be 
	//sent using its address
	push(&top,1);//passing the address of the variable so now we need a double pointer to catch this.
	push(&top,2);
	push(&top,3);
	printf("top element is %d\n",peek(top));
	pop(&top);
	pop(&top);
	pop(&top);

}