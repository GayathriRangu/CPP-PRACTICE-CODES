#include <bits/stdc++.h>

using namespace std;

class node
{
	public:
	
	int roll;
	string name;
	string course;
	int marks;
	int attendance;
	node* next;
	
	node(int r, string n, string c, int m, int a)
	{
		roll = r;
		name = n;
		course = c;
		marks = m;
		attendance = a;
		next = NULL;
	}
	
	void show()
	{
		cout<<"Roll:\t\t"<<roll<<endl;
		cout<<"Name:\t\t"<<name<<endl;
		cout<<"Course:\t\t"<<course<<endl;
		cout<<"Marks:\t\t"<<marks<<endl;
		cout<<"Attendance:\t"<<attendance<<endl;
	}
};

class records
{
	node* head;
	
	public:
	
	records()
	{
		head = NULL;
	}
	
	void insert(int r, string n, string c, int m, int a)
	{
		node* newNode = new node(r, n, c, m, a);
		
		if(head == NULL)
		{
			head = newNode;
			return;
		}
		
		node* temp = head;
		
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		
		temp -> next = newNode;
	}
	
	void del(int k)
	{
		if(head == NULL)
		{
			cout<<"Record underflow."<<endl;
			return;
		}
		
		node* temp = head;
		node* prev;
		
		while(temp != NULL and temp -> roll != k)
		{
			prev = temp;
			temp = temp -> next;
		}
		
		if(temp == NULL)
		{
			cout<<"Record not found."<<endl;
			return;
		}
		
		prev -> next = temp -> next;
		
		cout<<"Record deleted with roll: "<<temp -> roll<<endl;
		
		delete temp;
	}
	
	void search(int r = -1, string n = "", string c = "", int m = -1, int a = -1)
	{
		if(head == NULL)
		{
			cout<<"Records underflow."<<endl;
			return;
		}
		
		node* temp = head;
		
		cout<<"Search results:"<<endl;
		
		while(temp != NULL)
		{
			if(temp -> roll == r or temp -> name == n or temp -> course == c or temp -> marks == m or temp -> attendance == a)
			{
				temp -> show();
				cout<<endl;
			}
			temp = temp -> next;
		}
	}
	
	void update(int r = -1, string n = "", string c = "", int m = -1, int a = -1)
	{
		if(head == NULL)
		{
			cout<<"Records underflow."<<endl;
			return;
		}
		
		node* temp = head;
		
		cout<<"Search results:"<<endl;
		
		while(temp != NULL)
		{
			if(temp -> roll == r or temp -> name == n or temp -> course == c or temp -> marks == m or temp -> attendance == a)
			{
				cout<<"Current record:"<<endl;
			
				temp -> roll = r;
				temp -> name = n;
				temp -> course = c;
				temp -> marks = m;
				temp -> attendance = a;
			
				temp -> show();
				cout<<endl;
			}
			temp = temp -> next;
		}
	}
	
	void display()
	{
		node* temp = head;
		
		while(temp != NULL)
		{
			temp -> show();
			cout<<endl;
			temp = temp -> next;
		}
	}
	
};

int main()
{
	records rc;
	
	rc.insert(1, "Surja", "PhD", 100, 100);
	rc.display();
	rc.insert(2, "Surja", "PhD", 100, 100);
	rc.display();
	rc.insert(3, "Sourav", "MSc", 100, 100);
	rc.display();
	rc.search(-1, "", "PhD");
	rc.del(2);
	rc.display();
}
