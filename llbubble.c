#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//take input from user
//linkedlist elements into a file
//bubble sort the linked list
void insertnode(int);
void printnode();
//void bubblesort();
//void writetofile(char[]);

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;

void insertnode(int val1)
{
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   if(head==NULL)
   {
   	head=temp;
   	temp->data=val1;
   	temp->next=NULL;

   }
   else{
   	temp->data=val1;
   	temp->next=head;
   	head=temp;

   }
	
}
void printnode()
{
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("empty list");
	}
	else
	{
	while(temp!=NULL)
	 {
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	}
}
void writetofile(char filename[])
{
	struct node *temp=head;
	FILE *fp;
	fp=fopen(filename, "w");
	if(fp==NULL)
	{
		perror("error");
	}
	else{
		while(temp!=NULL)
		{
			fprintf(fp,"%d \n",temp->data);
			temp=temp->next;
		}
	}
}


void main()
{
	insertnode(1);
	insertnode(2);
	insertnode(200);
	insertnode(3);
	printnode();
	writetofile("bubblell.txt");
}