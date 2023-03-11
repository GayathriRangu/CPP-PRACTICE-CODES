#include <bits/stdc++.h>

using namespace std;

void addThem(long long arr1[], long long arr2[], int n1, int n2)
{
	int maxLen = max(n1, n2);
	
	int count = 0;
	long long sum, carry = 0;
	
	long long res[maxLen];
	
	while(count<n1 and count<n2)
	{
		sum = arr1[count] + arr2[count] + carry;
		carry = sum/100000000;
		sum = sum % 100000000;
		res[count] = sum;
		count++;
	}
	
	if(count<n1)
	{
		while(count<n1)
		{
			res[count] = arr1[count] + carry;
			carry = res[count]/100000000;
			res[count] = res[count] % 100000000;
			count++;
		}
	}
	
	if(count<n2)
	{
		while(count<n2)
		{
			res[count] = arr2[count] + carry;
			carry = res[count]/100000000;
			res[count] = res[count] % 100000000;
			count++;
		}
	}
	
	for(int i=n1-1; i>=0; i--)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
	
	for(int i=n2-1; i>=0; i--)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
	
	string finalResult;
	
	cout<<res[maxLen-1];
	for(int i=maxLen-2; i>=0; i--)
	{
		string pad = "00000000";
		finalResult = pad.substr(0, 8 - to_string(res[i]).length()) + to_string(res[i]);
		
		cout<<finalResult;
	}
	cout<<endl;
	
}

void addNums(string s1, string s2)
{
	//cout<<s1<<endl;
	//cout<<s2<<endl;
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int n1 = s1.length()/8 + 1, n2 = s2.length()/8 + 1;
	long long arr1[n1], arr2[n2];
	string part;
	
	for(int i=0; i<n1; i++)
	{
		part = s1.substr(i * 8, 8);
		reverse(part.begin(), part.end());
		arr1[i] = atoi(part.c_str());
	}
	
	for(int i=0; i<n2; i++)
	{
		part = s2.substr(i * 8, 8);
		reverse(part.begin(), part.end());
		arr2[i] = atoi(part.c_str());
	}
	
	addThem(arr1, arr2, n1, n2);
}

int main()
{
	freopen("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Practice/two_numbers.txt", "r", stdin);
	//freopen("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Practice/output.txt", "w", stdout);
	
	string s1, s2;
	
	cin >> s1 >> s2;
	
	addNums(s1, s2);
}
