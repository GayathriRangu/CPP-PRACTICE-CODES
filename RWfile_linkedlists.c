#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

	struct node *head=NULL;
struct node *last=NULL;
struct node *first=NULL;
struct node * readfromll(char filename[])
{
  //declare a file
	char str[60];
	FILE *fp;
	char *t;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("couldnt open the file");
	}
	
	else{

		if(fgets(str,60,fp))
		{
	

		
	}
			last->next=NULL;
printf("linked list read from file]\n");
	}
	fclose(fp);
	return head;

}
void writelltofile(char filename[],struct node *head)
{
	FILE *fp;
	struct node *temp;
	temp=head;
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("file couldnt open");
		exit(1);
	}


	while(temp!=NULL)
	{
		fprintf(fp,"\n %d \n",temp->data);
		//fwrite(temp, sizeof(struct node),1,fp);
		temp=temp->next;
	}
	/*if(fwrite!=0)
	{
		printf("ll stored in file successfully\n");

	}
	else{
		printf("error while writing\n");
	}*/
fclose(fp);
}

void insertatbegin(struct node **head,int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(*head==NULL)
	{
		*head=last=temp;

	}
	else{
		temp->next=*head;
		*head=temp;
	}
	

}

void display(struct node *temp)
{
	struct node *t=temp;
	while(t!=NULL)
	{
		printf("%d \n",t->data);
		t=t->next;
	}
}
void main()
{

insertatbegin(&head,1);
insertatbegin(&head,2);
insertatbegin(&head,3);
display(head);
writelltofile("abc.txt",head);
struct node *temp=readfromll("hi.txt");
display(temp);

}