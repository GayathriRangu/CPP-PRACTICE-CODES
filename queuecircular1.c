#include<stdio.h>
#define SIZE 5
int items[SIZE];
int front=-1,rear=-1;
//is empty
int isempty()
{
	if(front==-1)
		return 1;
	return 0;
}
int isfull()
{
	if((front ==rear+1) || (front==0 && rear==SIZE-1))
		return 1;
	return 0;
}
void enqueue(int x)
{
	if(isfull())
	{
		printf("full\n");

	}
	else{

		if(front==-1)
		{
			front =0;
		}
		rear=(rear+1)%SIZE;
		items[rear]=x;
		printf("%d is added\n",items[rear]);
	}
}

void dequeue()
{
int x;
	if(isempty())
	{
		printf("empty\n");
		
	}
	else
	{
		if(front==rear)
		{
x=items[front];
		     front=-1;
		     rear=-1;
printf("%dis removed \n",x);
		}
		else
		{
			x=items[front];
			front=(front+1)%SIZE;
			printf("%dis removed \n",x);
		}
	}

}

void main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	dequeue();
}