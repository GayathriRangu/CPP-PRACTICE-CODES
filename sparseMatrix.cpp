#include <bits/stdc++.h>

using namespace std;

void show(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void sparcify(int B[], int n, int flatLength)
{
	ifstream cin("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Practice/sparseMatrix.txt");

	int incoming;
	
	int index = 0;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> incoming;
			
			if(j>=i)
			{
				B[index++] = incoming;
			}
		}
	}
	
	show(B, flatLength);
}

void find(int B[], int n, int i, int j)
{
	if(j<i)
	{
		cout<<"The element at A["<<i<<"]["<<j<<"] is: 0."<<endl;
		cout<<"The element A["<<i<<"]["<<j<<"] is stored in B at: ignored."<<endl;
	}
	else
	{
		int index = i * n + j - (i * (i + 1))/2;
		int val = B[index];
		
		cout<<"The element at A["<<i<<"]["<<j<<"] is: "<<val<<"."<<endl;
		cout<<"The element A["<<i<<"]["<<j<<"] is stored in B at: B["<<index<<"]."<<endl;
	}
}

int main()
{
	int n = 5;
	
	int flatLength = (n * (n + 1)) / 2;
	
	int B[flatLength];
	
	sparcify(B, n, flatLength);
	
	while(true)
	{
		int i, j;
		cin >> i >> j;
		
		find(B, n, i, j);
	}
}
