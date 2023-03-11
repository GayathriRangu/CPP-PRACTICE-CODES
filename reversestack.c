#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
//function prototypes
void push(struct stack **top, int data );
int pop(struct stack ** top);
int isempty(struct stack *top);
void print(struct stack *top);

void insertatbottom(struct stack **top,int x)
{
	if(isempty(*top))
		push(top,x);
	else{
		int temp=pop(top);
		insertatbottom(top,x);
		push(top,temp);
	}

}
void reverse(struct stack **top)
{
	if(!isempty(*top))
	{
		int temp=pop(top);
		reverse(top);
		insertatbottom(top, temp);
	}
}
void push(struct stack **top,int data)
{
	struct stack *node=(struct stack *)malloc(sizeof(struct stack));
	if(node==NULL)
	{
		printf("stack overflow\n");
		return;
	}
	node->data=data;
	node->next=(*top);
	(*top)=node;
}
int pop(struct stack **top)
{
	int x;
	struct stack *t;
	if(isempty(top))
		return;
	else
	{
		x=(*top)->data;
		t=*top;
		*top=(*top)->next;
	}
	return x;
}
void print(struct stack *top)
{
	while(!isempty(top))
	{
		printf("[%d] ",top->data);
		top=top->next;
	}

}
int isempty(struct stack *top)
{
	return (top==NULL)?1:0;
}
int main()
{
	struct stack *s=NULL;
	push(&s,1);
	push(&s,2);
	push(&s,3);
	print(s);
	reverse(&s);
	print(s);
	return 0;


}