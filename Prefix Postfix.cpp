#include <bits/stdc++.h>

using namespace std;

int prefixEval(string s)
{
	int op1, op2;
	stack<int> st;
	
	for(int i=s.length()-1; i>=0; i--)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			st.push(s[i]-'0');
		}
		else
		{
			op1=st.top(); st.pop();
			op2=st.top(); st.pop();
			
			if(s[i]=='+')
				st.push(op1 + op2);
			else if(s[i]=='-')
				st.push(op1 - op2);
			else if(s[i]=='*')
				st.push(op1 * op2);
			else if(s[i]=='/')
				st.push(op1 / op2);
			else if(s[i]=='^')
				st.push(pow(op1, op2));
		}
	}
	return st.top();
}

int postfixEval(string s)
{
	int op1, op2;
	stack<int> st;
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			st.push(s[i] - '0');
		}
		else
		{
			op2=st.top(); st.pop();
			op1=st.top(); st.pop();
			
			if(s[i]=='+')
				st.push(op1 + op2);
			else if(s[i]=='-')
				st.push(op1 - op2);
			else if(s[i]=='*')
				st.push(op1 * op2);
			else if(s[i]=='/')
				st.push(op1 / op2);
			else if(s[i]=='^')
				st.push(pow(op1, op2));
		}
	}
	return st.top();
}

int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' or c=='/')
		return 2;
	else if(c=='+' or c=='-')
		return 1;
	else
		return -1;
}

string infixToPostfix(string s)
{
	stack<char> st;
	
	string result="";
	
	for(int i=0; i<s.length(); i++)
	{
		if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))
		{
			result += s[i];
		}
		else if(s[i]=='(')
			st.push(s[i]);
		else if(s[i]==')')
		{
			while(!st.empty() and st.top() != '(')
			{
				result += st.top(); st.pop();
			}
			
			if(!st.empty())
				st.pop();
		}
		else
		{
			while(!st.empty() and prec(st.top()) > prec(s[i]))
			{
				result += st.top(); st.pop();
			}
			st.push(s[i]);
		}
	}
	
	while(!st.empty())
	{
		result += st.top(); st.pop();
	}
	
	return result;
}

string infixToPrefix(string s)
{
	string result="";
	stack<char> st;
	
	for(int i=s.length()-1; i>=0; i--)
	{
		if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))
		{
			result += s[i];
		}
		else if(s[i] == ')')
		{
			st.push(s[i]);
		}
		else if(s[i] == '(')
		{
			while(!st.empty() and st.top() != ')')
			{
				result += st.top(); st.pop();
			}
			
			if(!st.empty())
			{
				st.pop();
			}
		}
		else
		{
			while(!st.empty() and prec(st.top()) > prec(s[i]))
			{
				result += st.top(); st.pop();
			}
			st.push(s[i]);
		}
	}
	
	while(!st.empty())
	{
		result += st.top(); st.pop();
	}
	
	reverse(result.begin(), result.end());
	
	return result;
}

int main()
{
	string pre = "-+7*45+20";
	string post="46+2/5*7+";
	string in  ="(a-b/c)*(a/k-l)";
	cout<<prefixEval(pre)<<endl;
	cout<<postfixEval(post)<<endl;
	cout<<infixToPostfix(in)<<endl;
	cout<<infixToPrefix(in)<<endl;
}
