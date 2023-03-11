#include <bits/stdc++.h>

using namespace std;

class node
{
	public:

	char data;
	node* next;
	
	node(char val)
	{
		data = val;
		next = NULL;
	}
};

void display(node* head)
{
	if(head == NULL)
	{
		cout<<"Underflow."<<endl;
		return;
	}
	
	node* temp = head;
	
	while(temp != NULL and temp -> next != head)
	{
		cout<<temp -> data<<" -> ";
		temp = temp -> next;
	}
	
	cout<<"NULL"<<endl;
}

void movetoFront(node* &head, string input)
{
	if(input == "")
	{
		cout<<"Blank input."<<endl;
		return;
	}
	
	node* temp;
	node* prev;
	int found;
	int count = 0;
	
	for(int i=0; i<input.length(); i++)
	{
		temp = head;
		prev = head;
		found = 0;
		
		while(temp != NULL)
		{
			count++;
			if(temp -> data == input[i])
			{
				found = 1;
				break;
			}
			
			prev = temp;
			temp = temp -> next;
		}
		
		if(found)
		{
			if(temp != head)
			{
				prev -> next = temp -> next;
				temp -> next = head;
				head = temp;
			}
		}
		else
		{
			node* newNode = new node(input[i]);
			
			if(head == NULL)
			{
				head = newNode;
			}
			else
			{
				prev -> next = newNode;
			}
		}
		display(head);
	}
	
	cout<<count<<endl;
}

void transpose(node* &head, string input)
{
	if(input == "")
	{
		cout<<"Blank input."<<endl;
		return;
	}
	
	node* temp;
	node* prev;
	node* third;
	int found;
	int count = 0;
	
	for(int i=0; i<input.length(); i++)
	{
		temp = head;
		prev = NULL;
		third = NULL;
		found = 0;
		
		while(temp != NULL)
		{
			count++;
			if(temp -> data == input[i])
			{
				found = 1;
				break;
			}
			third = prev;
			prev = temp;
			temp = temp -> next;
		}
		
		if(found)
		{
			if(temp != head)
			{
				if(third == NULL)
				{
					prev -> next = temp -> next;
					temp -> next = prev;
					head = temp;
				}
				else
				{
					prev -> next = temp -> next;
					temp -> next = prev;
					third -> next = temp;
				}
			}
		}
		else
		{
			node* newNode = new node(input[i]);
			
			if(head == NULL)
			{
				head = newNode;
			}
			else
			{
				prev -> next = newNode;
			}
		}
		display(head);
	}
	
	cout<<count<<endl;
}

int main()
{
	string input1 = "ACBCDAD";
	string input2 = "ACBBB";
	
	node* head1 = NULL;
	movetoFront(head1, input1);
	
	node* head2 = NULL;
	transpose(head2, input1);
	
	head1 = NULL;
	movetoFront(head1, input2);
	
	head2 = NULL;
	transpose(head2, input2);
}
