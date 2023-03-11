#include <bits/stdc++.h>

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
		cout<<temp -> data<<" ";
		temp = temp -> next;
	}
	cout<<endl;
}

char show()
{
	cout<<"Options: Please choose an action."<<endl;
	cout<<"1. Display"<<endl;
	cout<<"2. Insert"<<endl;
	cout<<"3. Delete"<<endl;
	cout<<"4. Exit"<<endl;
	
	char option;
	
	cin >> option;
	
	return option;
}

bool isDigit(string s)
{
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] < '0' or s[i] > '9')
			return false;
	}
	
	return true;
}

void insert(node* &head)
{
	cout<<"Please enter the number to insert: ";
	
	string val;
	
	cin >> val;
	
	if(!isDigit(val))
	{
		cout<<"Value not numeric."<<endl;
		return;
	}
	else
	{
		int num = atoi(val.c_str());
		node* newnode = new node(num);
		
		if(head == NULL)
		{
			head = newnode;
			return;
		}
		
		node* temp = head;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newnode;
	}
}

void del(node* &head)
{
	if(head == NULL)
	{
		cout<<"Nothing to delete."<<endl;
		return;
	}
	else
	{
		node* temp = head;
		node* previous = head;
		
		while(temp -> next != NULL)
		{
			previous = temp;
			temp = temp -> next;
		}
		
		node* toDelete = temp;
		
		if(temp != head)
		{
			previous -> next = temp -> next;
		}
		else
		{
			head = NULL;
		}
		
		cout<<"Deleting value: "<<toDelete -> data<<endl;
		
		delete toDelete;
	}
}

void menu(node* &head)
{
	char option = show();
	
	if(option < '1' or option > '4')
	{
		cout<<"Please enter a valid option."<<endl;
		return;
	}
	else
	{
		if(option == '1')
		{
			display(head);
			return;
		}
		else if(option == '2')
		{
			insert(head);
			return;
		}
		else if(option == '3')
		{
			del(head);
			return;
		}
		else if(option == '4')
		{
			exit(0);
		}
	}
}

int main()
{
	node* head = new node(21);
	
	display(head);
	
	while(true)
	{
		menu(head);
	}
}
