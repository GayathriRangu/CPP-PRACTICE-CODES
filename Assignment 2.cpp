#include <bits/stdc++.h>

using namespace std;

class queues
{
	stack<int> s1;
	stack<int> s2;
	int N;
	
	public:
	
	queues()
	{
		N=0;
	}
	
	int pop()
	{
		if(!s2.empty())
		{	
			int topVal = s2.top();
			s2.pop();
			N--;
			return topVal;
		}
		
		if(s1.empty())
		{
			cout<<"Queue underflow."<<endl;
			return -1;
		}
		
		int lastVal;
		while(s1.size() != 1)
		{
			s2.push(s1.top());
			s1.pop();
		}
		lastVal = s1.top();
		s1.pop();
		N--;		
		return lastVal;
	}
	
	int size()
	{
		return N;
	}
	
	bool empty()
	{
		if(s1.empty())
			return true;
		
		return false;
	}
	
	void push(int val)
	{
		s1.push(val);
		N++;
	}
};

void towerofHanoi(int n, char src, char dest, char help)
{
	if(n==0)
	{
		return;
	}
	
	towerofHanoi(n - 1, src, help, dest);
	cout<<"Move disc "<<n<<" from "<<src<<" to "<<dest<<endl;
	towerofHanoi(n - 1, help, dest, src);
}

int main()
{
	int n = 4;
	char src = 'A', help = 'B', dest = 'C';
	
	towerofHanoi(n, src, dest, help);
	

	/*Q1
	queues q;
	q.push(1);
	q.push(2);
	q.push(3);
	
	cout<<q.size()<<endl;
	
	cout<<q.pop()<<endl;
	
	cout<<q.pop()<<endl;
	
	cout<<q.pop()<<endl;
	
	cout<<q.empty()<<endl;
	
	cout<<q.pop()<<endl;
	*/
}
