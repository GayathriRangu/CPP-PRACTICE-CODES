#include <bits/stdc++.h>

using namespace std;

class Stack
{
	queue<int> q1;
	queue<int> q2;
	int N;
	
	public:
	
	Stack()
	{
		N = 0;
	}
	
	void push(int val)
	{
		q1.push(val);
		N++;
	}
	
	int size()
	{
		return N;
	}
	
	bool empty()
	{
		if(q1.empty())
			return true;
		
		return false;
	}
	
	int top()
	{
		if(q1.empty())
		{
			cout<<"Stack underflow."<<endl;
			return -1;
		}
		
		while(q1.size() >= 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int item = q1.front();
		q2.push(item);
		
		queue<int> temp;
		
		temp = q1;
		q1 = q2;
		q2 = temp;
		
		return item;
	}
	
	void pop()
	{
		if(q1.empty())
		{
			cout<<"Stack underflow."<<endl;
			return;
		}
		
		while(q1.size() >= 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		N--;
		
		queue<int> temp;
		
		temp = q1;
		q1 = q2;
		q2 = temp;
	}
};

int main()
{
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
	cout<<st.top()<<endl;

	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	cout<<st.empty()<<endl;
}
