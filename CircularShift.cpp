#include <bits/stdc++.h>

using namespace std;

void circular(string s, int d)
{
	string word = "", res = "";
	queue<string> buff;
	queue<char> symbols;
	queue<int> positions;
	queue<char> lastVal;
	
	int count = 0;
	int words = 0;
	
	for(int i=0; i<=s.length(); i++)
	{
		if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z'))
		{
			word += s[i];
		}
		else 
		{
			if((s[i-1] >= 'A' and s[i-1] <= 'Z') or (s[i-1] >= 'a' and s[i-1] <= 'z'))
			{
				words++;
			}
			if(s[i] == ' ' or s[i] == '\0')
			{
				if(count < d)
				{
					buff.push(word);
					count++;
				}
				else
				{
					res += word + " ";
				}
				word = "";
			}
			else
			{
				symbols.push(s[i]);
				positions.push(words);
				lastVal.push(s[i - 1]);
			}
		}
		
	}
	
	while(!buff.empty())
	{
		res += buff.front() + " ";
		buff.pop();
	}
	
	words = 0;
	
	while(!symbols.empty())
	{
		for(int i=0; i<=res.length(); i++)
		{
			if(res[i] == ' ' or s[i] == '\0')
			{
				words++;
			}
			
			if(words == positions.front())
			{
				if(lastVal.front() == ' ')
				{
					res.insert(i + 1, 1, symbols.front());
				}
				else
				{
					res.insert(i, 1, symbols.front());
				}
				
				words = 0;
				symbols.pop();
				positions.pop();
				lastVal.pop();
				
				break;
			}
		}
	}
	
	cout<<s<<endl;
	cout<<res<<endl;
}

int main()
{
	int d;
	cin >> d;
	string str;
	
	{ifstream cin("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Practice/CircularShift.txt");
	getline(cin, str);}	
	
	circular(str, d);
}
