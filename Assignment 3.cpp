#include <bits/stdc++.h>

using namespace std;

class node
{
	public:
	
	char person;
	node* next;
	
	node(char name)
	{
		person = name;
		next = NULL;
	}
};

void display(node* head)
{
	node* temp = head;
	
	while(temp -> next != head)
	{
		cout<<temp -> person<<" -> ";
		temp = temp -> next;
	}
	cout<<temp -> person<<" -> Repeat."<<endl;
}

int kill(node* &head, int k)
{
	node* temp = head;
	node* previous;
	int count;
	
	if(head -> next == head)
	{
		return 0;
	}
	
	while(k > 0)
	{
		previous = temp;
		k--;
		temp = temp -> next;
		count++;
	}
	
	node* toDelete = temp;
	previous -> next = temp -> next;
	cout<<head -> person<<" kills "<<temp -> person<<endl;
	
	head = temp -> next;
	delete temp;
	
	return ++count;
}

int josephus(int n, int k)
{
	int arr[n];
	
	arr[0] = 65;
	node* temp = new node(arr[0]);
	node* head = temp;
	node* moving = head;
	
	for(int i=1; i<n; i++)
	{
		arr[i] = arr[i-1] + 1;
		temp = new node(arr[i]);
		moving -> next = temp;
		moving = temp;
	}
	moving -> next = head;
	
	display(head);
	
	int killed = 0;
	int links = 0;
	
	while(killed < n - 1)
	{
		links += kill(head, k);
		display(head);
		killed++;
	}
	
	return links;
}

class node1
{
	public:

	int data;
	node1* next;
	
	node1(int val)
	{
		data = val;
		next = NULL;
	}
};

node1* linkedRepresentation(int arr[], int n)
{
	node1* head = new node1(arr[0]);
	node1* temp;
	node1* previous = head;
	
	for(int i=1; i<n; i++)
	{
		temp = new node1(arr[i]);
		previous -> next = temp;
		previous = temp;
	}
	
	return head;
}

void displayLinear(node1* head)
{
	node1* temp = head;
	
	while(temp != NULL)
	{
		cout<<temp -> data<<" -> ";
		temp = temp -> next;
	}
	cout<<" NULL"<<endl;
}

void showArray(int arr[], int n)
{
	cout<<n<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void merge(node1* &head, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int arr1[n1], arr2[n2];
	int count = 0;
	cout<<n1<<" "<<n2<<endl;
	
	node1* temp = head;
	
	while(count < l)
	{
		temp = temp -> next;
		count++;
	}
	
	for(int i=0; i<n1; i++)
	{
		arr1[i] = temp -> data;
		temp = temp -> next;
		cout<<arr1[i]<<"hi"<<endl;
	}
	
	showArray(arr1, n1);
	
	for(int i=0; i<n2; i++)
	{
		while(temp != NULL)
		{
			arr2[i] = temp -> data;
			temp = temp -> next;
			cout<<arr1[i]<<"hello"<<endl;
		}
	}
	
	showArray(arr2, n2);
	
	node1* head1 = linkedRepresentation(arr1, n1);
	node1* head2 = linkedRepresentation(arr2, n2);
	
	//displayLinear(head1);
	//displayLinear(head2);
	
	node1* temp1 = head1;
	node1* temp2 = head2;
	
	temp = head;
	count = 0;
	
	while(count < l)
	{
		temp = temp -> next;
		count++;
	}
	
	while(temp1 != NULL and temp2 != NULL)
	{
		if(temp1 -> data < temp2 -> data)
		{
			temp -> data = temp1 -> data;
			temp1 = temp1 -> next;
		}
		else
		{
			temp -> data = temp2 -> data;
			temp2 = temp2 -> next;
		}
		temp = temp -> next;
	}
	
	while(temp1 != NULL)
	{
		temp -> data = temp1 -> data;
		temp1 = temp1 -> next;
		temp = temp -> next;
	}
	
	while(temp2 != NULL)
	{
		temp -> data = temp2 -> data;
		temp2 = temp2 -> next;
		temp = temp -> next;
	}
}

void mergeSort(node1* &head, int l, int r)
{
	if(l<r)
	{
		int m = (l + r)/2;
		
		mergeSort(head, l, m);
		mergeSort(head, m + 1, r);
		
		merge(head, l, m, r);
	}
}

int main()
{
	/*Q1
	int n = 10, k = 3;
	//cin >> n >> k;
	cout<<josephus(n, k)<<" links traversed."<<endl;
	*/
	
	
	int arr[] = {34, 75, 37, 8, 29, 56, 73, 30, 84, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	node1* head = linkedRepresentation(arr, n);
	displayLinear(head);
	mergeSort(head, 0, n-1);
	displayLinear(head);
}
