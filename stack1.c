#include<stdio.h>
#include<stdlib.h>
//array implementation of stacks
struct stack 
{
	int top;
	unsigned capacity;
	int *array;

};

struct stack * createstack(unsigned capacity)
{
	struct stack *s=(struct stack *)malloc(sizeof(struct stack));
	s->capacity=capacity;
	s->top=-1;
	s->array=(int *)malloc(s->capacity * sizeof(int));
	return s;

}

int isfull(struct stack *s)
{
	return s->top==s->capacity-1;
}

int isempty(struct stack *s)
{
	return s->top==-1;
}

void push(struct stack *s,int item)
{
	if(isfull(s))
	{
		return INT_MIN;
	}
	s->array[++s->top]=item;
	printf("%d pushed to stack\n",item);
}

int pop(struct stack *s)
{
	if(isempty(s))
		return INT_MIN;
	return s->array[s->top--];
}
int peek(struct stack *s)
{
	if(isempty(s))
		return INT_MIN;
	return s->array[s->top];

}
int main()
{
	struct stack *s=createstack(100);
	push(s,10);
	push(s,20);
	push(s,30);
	//printf("%d popped from stack\n",pop(s));
printf("%d\n",s->top);
printf("%d\n",s->capacity);
for(int i=0;i<=s->top;i++)
{
	printf("%d  ",s->array[i]);
}
	return 0;

}