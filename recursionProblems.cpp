#include <bits/stdc++.h>

using namespace std;

void strRev(string s)
{
	if(s.length() == 0)
		return;
	
	strRev(s.substr(1));
	cout<<s[0];
}

void replace(string s)
{
	if(s.length() == 0)
		return;

	if(s.substr(0, 2) == "pi")
	{
		cout<<"3.14";
		replace(s.substr(2));
	}
	else
	{
		cout<<s.substr(0, 1);
		replace(s.substr(1));
	}
}

void towerofHanoi(int n, char src, char dest, char help)
{
	if(n == 0)
	{
		return;
	}
	
	towerofHanoi(n-1, src, help, dest);
	cout<<"Move from "<<src<<" to "<<dest<<endl;
	towerofHanoi(n-1, help, dest, src);
}

string duplicate(string s)
{
	if(s.length() == 0)
		return "";
	
	char first = s[0];
	
	string rest = duplicate(s.substr(1));
	
	if(first == rest[0])
		return rest;
	else
		return first+rest;
}

string movetoEnd(string s)
{
	if(s.length() == 0)
		return "";
	
	if(s[0] == 'x')
	{
		return movetoEnd(s.substr(1))+'x';
	}
	else
	{
		cout<<s[0];
		return movetoEnd(s.substr(1));
	}
}

void allSubstr(string s, string res)
{
	if(s.length() == 0)
	{
		cout<<res<<endl;
		return;
	}
	
	char ch = s[0];
	
	allSubstr(s.substr(1), res);
	allSubstr(s.substr(1), res + ch);
	
}

int main()
{
	/*Q1
	string str = "Surja Sanyal";
	strRev(str);
	*/
	
	/*Q2
	string str = "pijkdbpiipafefiipiadjsdjpiksf";
	replace(str);
	*/
	
	/*Q3
	int n = 3;
	char src = 'A', dest = 'C', help = 'B';
	towerofHanoi(n, src, dest, help);
	*/
	
	/*Q4
	string str = "aaaaabbbbbbbcdddddeeeeeeefffffffffgg";
	cout<<duplicate(str)<<endl;
	*/
	
	/*Q5
	string str = "jergoonxofjrjokwdfiowfxod2ioioewsoxxwo";
	cout<<movetoEnd(str)<<endl;
	*/
	
	/*Q6
	string str = "abc";
	allSubstr(str, "");
	*/
	
	
	
	
	cout<<endl;
}
