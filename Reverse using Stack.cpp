#include <bits/stdc++.h>

using namespace std;

void revStr(string s)
{
	stack<string> st;
	string word;
	
	for(int i=0; i<s.length(); i++)
	{
		word="";
		while(s[i]!=' ' and i<s.length())
		{
			word+=s[i];
			i++;
		}
		st.push(word);
	}
	
	while(!st.empty())
	{
		cout<<st.top()<< " ";
		st.pop();
	}
	cout<<endl;
}

int main()
{
	string s = "Hi, how are you doing?";
	revStr(s);
}
