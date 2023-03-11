#include <bits/stdc++.h>

using namespace std;

#define n 10

class stack1
{
	int* arr;
	int top;
	
	public:
	stack1()
	{
		arr = new int[n];
		top = -1;
	}
	
	void push(int val)
	{
		if(top==n-1)
		{
			cout<<"Stack overflow."<<endl;
		}
		else
		{
			top++;
			arr[top]=val;
		}
	}
	
	void pop()
	{
		if(top==-1)
		{
			cout<<"Stack underflow."<<endl;
		}
		else
		{
			top--;
			cout<<arr[top+1]<<endl;
		}
	}
	
	void empty()
	{
		if(top==-1)
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
	}
	
	void Top()
	{
		cout<<top<<endl;
	}
};

int main()
{
	stack1 st;
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
