#include <bits/stdc++.h>

using namespace std;

class queues
{
	stack<int> st1;
	stack<int> st2;
	
	public:
	
	bool empty()
	{
		if(st1.empty() and st2.empty())
		{
			return true;
		}
		
		return false;
	}
	
	void push(int val)
	{
		st1.push(val);
	}
	
	int pop()
	{
		if(st1.empty() and st2.empty())
		{
			cout<<"Queue underflow."<<endl;
			return -1;
		}
		
		if(st2.empty())
		{
			while(!st1.empty())
			{
				st2.push(st1.top()); st1.pop();
			}
		}
		
		int topEle = st2.top();
		
		st2.pop();
		
		return topEle;
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
	cout<<q.pop()<<endl;
	cout<<q.empty()<<endl;
}
