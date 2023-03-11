#include <bits/stdc++.h>

using namespace std;

void copyFrom(int arr[], int n, stack<int> &st)
{
	for(int i=0; i<n; i++)
	{
		st.push(arr[n - 1 - i]);
	}
}

void display(stack<int> st)
{
	if(st.empty())
	{
		return;
	}
	
	cout<<st.top()<<endl;
	
	st.pop();
	
	display(st);
}

void insertAtBottom(stack<int> &st, int topVal)
{
	if(st.empty())
	{
		st.push(topVal);
		return;
	}
	
	int current = st.top();
	
	st.pop();
	
	insertAtBottom(st, topVal);
	
	st.push(current);
}

void reverseStack(stack<int> &st)
{
	if(st.empty())
	{
		return;
	}
	
	int topVal = st.top();
	
	st.pop();
	
	reverseStack(st);
	
	insertAtBottom(st, topVal);
}

int main()
{
	int arr[] = {5, 8, 4, 2, 0, 4, 3, 7, 5, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	stack<int> st;
	copyFrom(arr, n, st);
	display(st);
	
	reverseStack(st);
	display(st);
}
