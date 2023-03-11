#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
	int data;
	int key;
	struct node * next;

};
struct node * head=NULL;
struct node * curr=NULL;
//insert
void insertfirst(int data, int key)
{
	struct node * temp=(struct node*)(malloc(sizeof(struct node)));
	temp->data=data;
	temp->key=key;
	temp->next=head;
	head=temp;
}
//display
void display()
{
	struct node * ptr=head;
	while(ptr!=NULL)
	{
		printf("%d, %d\n",ptr->data,ptr->key);
ptr=ptr->next;
	}
}
//deletefirst
struct node* deletefirst()
{
struct node *temp=head;
head=head->next;
return temp;
}
bool isEmpty()
{
	if(head==NULL)
		return 1;
	else return 0;
}
void main()
{
	insertfirst(1,10);
	insertfirst(2,20);
	display();
	while(!isEmpty())
	{
		struct node *temp=deletefirst();
	}
	
	printf("delete");
	display();

}