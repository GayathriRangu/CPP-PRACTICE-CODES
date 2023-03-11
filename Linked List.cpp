#include<bits/stdc++.h>

using namespace std;

class node
{
	public:
	
	int data;
	node* next;
	
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

void display(node* head)
{
	node* temp = head;
	
	while(temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	
}

void insert_at_tail(node* &head, int val)
{
	node* newnode = new node(val);
	
	if(head == NULL)
	{
		head = newnode;
		return;
	}
		
	node* temp = head;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	temp->next = newnode;
}

void insert_at_head(node* &head, int val)
{
	node* newnode = new node(val);
	
	newnode->next = head;
	head = newnode;
}

void find_val(node* head, int val)
{
	node* temp = head;
	
	while(temp->data != val)
	{
		temp = temp->next;
	}
	cout << temp->data << " -> " << temp->next->data << endl;
}

void deletion(node* &head, int val)
{
	node* temp = head;
	node* previous;
	
	while(temp->next != NULL and temp->data != val)
	{
		previous = temp;
		temp = temp->next;
	}
	
	if(temp->data == val)
	{
		previous->next = temp->next;
		delete temp;
	}
	else
		cout << "Key not found" << endl;
}

void reverse_list(node* &head)
{
	node* left = NULL;
	node* current = head;
	node* right = head->next;
	
	while(current != NULL)
	{
		right = current->next;
		current->next = left;
		
		left = current;
		current = right;
	}
	
	head = left;
}

node* reverse_k(node* &head, int k)
{
	node* prev = NULL;
	node* curr = head;
	node* nxt;
	
	int count = 0;
	
	while(curr != NULL and count < k)
	{
		nxt = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = nxt;
		
		count++;
	}
	
	if(nxt != NULL)
	{
		head->next = reverse_k(nxt, k);
	}
	
	return prev;
}

int main()
{
	node* head = NULL;
	
	insert_at_tail(head, 55);
	insert_at_tail(head, 67);
	insert_at_head(head, 02);
	insert_at_tail(head, 23);
	insert_at_tail(head, 90);
	insert_at_tail(head, 84);
	insert_at_head(head, 29);
	display(head);
	
	find_val(head, 23);
	
	//deletion(head, 23);
	display(head);
	
	reverse_list(head);
	display(head);
	
	head = reverse_k(head, 2);
	display(head);
}
