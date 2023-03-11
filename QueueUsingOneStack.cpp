#include <bits/stdc++.h>

using namespace std;

class queues
{
	stack<int> st;
	
	public:
	
	void push(int val)
	{
		st.push(val);
	}
	
	bool empty()
	{
		if(st.empty())
		{
			return true;
		}
		
		return false;
	}
	
	int pop()
	{
		if(st.empty())
		{
			cout<<"Queue underflow."<<endl;
			return -1;
		}
		
		int topEle = st.top();
		
		st.pop();
		
		if(st.empty())
		{
			return topEle;
		}
		
		int item = pop();
		
		st.push(topEle);
		
		return item;
	}
};

int main()
{
	queues q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	cout<<q.pop()<<endl;
	
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.pop()<<endl;
	cout<<q.empty()<<endl;
}
