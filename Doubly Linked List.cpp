#include<bits/stdc++.h>

using namespace std;

class node
{
	public:
	int data;
	node* next;
	node* prev;
	
	node(int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};

void display(node* head)
{
	while(head != NULL)
	{
		cout << head -> data << " <-> ";
		head = head -> next;
	}
	
	cout << "NULL" << endl;
}

void insert_node(node* &head, int val)
{
	node* temp = head;
	node* newnode = new node(val);
	
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	
	temp -> next = newnode;
	newnode -> prev = temp;
	
}

int main()
{
	node* head = new node(21);
	insert_node(head, 55);
	
	display(head);
	
}
