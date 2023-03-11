#include <bits/stdc++.h>

using namespace std;

void insertAtBottom(stack<int> &st, int e)
{
	if(st.empty())
	{
		st.push(e);
		return;
	}
	
	int topElement = st.top();
	st.pop();
	insertAtBottom(st, e);
	
	st.push(topElement);
}

void reverse_stack(stack<int> &st)
{
	if(st.empty())
		return;
	
	int topElement = st.top();
	st.pop();
	
	reverse_stack(st);
	
	insertAtBottom(st, topElement);
}

void copyFrom(int arr[], int n, stack<int> &st)
{
	for(int i=0; i<n; i++)
		st.push(arr[n - 1 - i]);
}

void display(stack<int> st)
{
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main()
{
	int arr[] = {5, 8, 4, 2, 0, 4, 3, 7, 5, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	stack<int> st;
	copyFrom(arr, n, st);
	display(st);
	
	reverse_stack(st);
	display(st);
}
