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
	
	bool empty()
	{
		if(q1.empty())
		{
			return true;
		}
		
		return false;
	}
	
	void pop()
	{
		if(!q1.empty())
		{
			q1.pop();
			N--;
		}
	}
	
	int size()
	{
		return N;
	}
	
	void push(int val)
	{
		q2.push(val);
		N++;
		
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
	}
	
	int top()
	{
		return q1.front();
	}
};

int main()
{
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
	cout<<st.size()<<endl;

	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.top()<<endl;
	
	st.pop();
	cout<<st.empty()<<endl;
	
	st.pop();
	cout<<st.size()<<endl;
}
