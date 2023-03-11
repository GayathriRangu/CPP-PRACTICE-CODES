#include <bits/stdc++.h>

using namespace std;

#define n 10

class stacks
{
	int* arr;
	int top;
	
	public:
	
	stacks()
	{
		arr = new int[n];
		top = -1;
	}
	
	void Top()
	{
		cout<<top<<endl;
	}
	
	void empty()
	{
		if(top == -1)
		{
			cout<<"True"<<endl;
		}
		else
		{
			cout<<"False"<<endl;
		}
	}
	
	void push(int val)
	{
		if(top == n - 1)
		{
			cout<<"Stack overflow."<<endl;
			return;
		}
		
		top++;
		
		arr[top] = val;
	}
	
	void pop()
	{
		if(top == -1)
		{
			cout<<"Stack underflow."<<endl;
			return;
		}
		
		cout<<arr[top--]<<endl;
	}
};

int main()
{
	stacks st;
	st.pop();
	st.push(12);
	st.push(65);
	st.push(79);
	st.push(36);
	st.pop();
	st.Top();
	st.pop();
	st.empty();
	st.pop();
	st.pop();
	st.empty();
}
