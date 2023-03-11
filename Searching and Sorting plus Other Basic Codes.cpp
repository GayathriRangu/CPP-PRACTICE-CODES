#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
	if(n==1)
		return 1;
	else
		return n * fact(n - 1);
}

void fibo(int n)
{
	int a = 1, b = 1, c;
	cout << a << " " << b;
	
	for(int i=0;i<n-2;i++)
	{
		c = a + b;
		cout << " " << c;
		b = a;
		a = c;
	}
}

void find_prime(int a, int b)
{
	if(a>b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	for(int i=a; i<=b; i++)
	{
		int check = 2, flag = 0;
		while(check <= sqrt(i))
		{
			if(i%check == 0)
			{
				flag = 1;
				break;
			}
			check++;
		}
		if(flag==0)
			cout << i << " ";
	}
}

void diamond(int n)
{
	int count;
	
	for(int i=0;i<n;i++)
	{
		count = 1;
		for(int j=1;j<n+1;j++)
		{
			if(j<n-i)
			{
				cout << " ";
			}
			else
			{
				if(count<=ceil(n/2))
				{
					count += 1;
					cout << "*";
				}
				else
					cout << " ";
			}
		}
		
		if(i>ceil(n/2))
		{
			for(int j=i-ceil(n/2);j>0;j--)
				cout << " ";
			for(int j=0;j<ceil(n/2);j++)
				cout << "*";
		}
		else
		{
			for(int j=i;j>0;j--)
					cout << "*";
		}
		
		cout << endl;
	}

	for(int i=1;i<n;i++)
	{
		count = 1;
		for(int j=0;j<n;j++)
		{
			if(j<i)
			{
				cout << " ";
			}
			else
			{
				if(count<=ceil(n/2))
				{
					count += 1;
					cout << "*";
				}
				else
					cout << " ";
			}
		}
		
		if(i<ceil(n/2))
		{
			for(int j=n%2==0?ceil(n/2)-i-1:ceil(n/2)-i;j>0;j--)
				cout << " ";
			for(int j=0;j<ceil(n/2);j++)
				cout << "*";
		}
		else
		{
			for(int j=n-i-1;j>0;j--)
					cout << "*";
		}
		
		cout << endl;
	}
}

int binary_search(int arr[], int n, int key)
{
	if(n>0)
	{
		int mid = n/2;
		if(arr[mid] == key)
			return mid;
		else
		{
			if(arr[mid] > key)
				return binary_search(arr, mid, key);
			else
				return binary_search(&arr[mid], n - mid, key);
		}
	}
	else
		return -1;
}

void selection_sort(int arr[], int n)
{
	int min, temp;
	for(int i=0;i<n;i++)
	{
		min = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubble_sort_1(int arr[], int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubble_sort(int arr[], int n)
{
	int temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n - i - 1;j++)
		{
			if(arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for(int i = 0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void insertion_sort(int arr[], int n)
{
	int temp;
	for(int i=1; i<n; i++)
	{
		temp = arr[i];
		for(int j=i; j>0; j--)
		{
			if(arr[j-1] > temp)
			{
				arr[j] = arr[j-1];
				
				if(j==1)
					arr[j-1] = temp;
			}
			else
			{
				arr[j] = temp;
				break;
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void max_subarray(int arr[], int n)
{
	int newarr[] = {10, 7, 4, 6, 8, 10, 11};
	arr = newarr;
	n = 7;
	int maxlen, maxdef, arr1[n-1], arr2[n-1];
	
	for(int i=0; i<n-1; i++)
	{
		arr1[i] = arr[i+1] - arr[i];
	}
	
	for(int i=1; i<n-1; i++)
	{
		arr2[i] = 0;
	}
	
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr1[j] == arr1[i])
				arr2[i] += 1;
		}
	}
	
	maxlen = 0;
	for(int i=1; i<n-1; i++)
	{
		if(arr2[i] > arr2[maxlen])
			maxlen = i;
	}
	
	maxdef = 0;
	for(int i=1; i<n-1; i++)
	{
		if(arr1[i] > arr1[maxdef])
			maxdef = i;
	}
	
	for(int i=0; i<n-1; i++)
	{
		cout<< arr1[i] << " ";
	}
	
	cout << "Max freq element: " << arr1[maxlen] << ". Max freq count: " << arr2[maxlen] << ". Chain length: " << arr2[maxlen] + 1 << endl;
	cout << "Max difference element: " << arr1[maxdef] << ". Max difference count: " << arr2[maxdef] << endl;
}

void record_breaking_day(int arr[], int n)
{
	int newarr[] = {1, 2, 0, 7, 2, 0, 2, 2};
	arr = newarr;
	n = 8;
	int flag;
	
	for(int i=0; i<n; i++)
	{
		flag = 0;
		for(int j=0; j<i; j++)
		{
			if(arr[i] <= arr[j])
			{
				flag = 1;
				break;
			}
		}
		
		if(flag != 1)
		{
			if(arr[i] > arr[i + 1])
			{
				cout << i << " ";
			}
		}
	}
	cout << endl;
}

void char_array()
{
	/*
	char arr1[10];
	cin.getline(arr1, n);
	for(int i=0; i<10; i++)
	{
		cout << arr1[i] << " ";
	}
	*/

	char name[10] = "Surja";
	
	int i=0;
	
	while(name[i] != '\0')
	{
		cout << name[i] << " ";
		i++;
	}
	cout << endl;
}

void counting_sort(int arr[], int n)
{
	int max = arr[0];
	for(int i=0; i<n; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	int freq[++max];
	
	memset(freq, 0, sizeof(freq));
	
	for(int i=0; i<n; i++)
	{
		freq[arr[i]] += 1;
	}
	
	for(int i=0; i<max; i++)
	{
		cout << freq[i] << " ";
	}
	cout << endl;
	
	int cum_freq[max];
	
	memset(cum_freq, 0, sizeof(freq));
	
	cum_freq[0] = freq[0];
	for(int i=1; i<max; i++)
	{
		cum_freq[i] = cum_freq[i - 1] + freq[i];
	}
	
	for(int i=0; i<max; i++)
	{
		cout << cum_freq[i] << " ";
	}
	cout << endl;
	
	int arr_out[n];
	
	for(int i=n-1; i>=0; i--)
	{
		arr_out[--cum_freq[arr[i]]] = arr[i];
	}
	
	for(int i=0; i<n; i++)
	{
		cout << arr_out[i] << " ";
	}
	cout << endl;
}

void merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1, n2 = right - mid;
	int l[n1], r[n2];
	
	for(int i=0; i<n1; i++)
	{
		l[i] = arr[left + i];
	}
	
	for(int i=0; i<n2; i++)
	{
		r[i] = arr[mid + 1 + i];
	}
	
	int j=left;
	int l1 = 0, r1 = 0;
	while(l1 < n1 && r1 < n2)
	{
		if(l[l1] < r[r1])
		{
			arr[j] = l[l1];
			l1++;
		}
		else
		{
			arr[j] = r[r1];
			r1++;
		}
		j++;
	}
	
	while(l1<n1)
	{
		arr[j++] = l[l1++];
	}
	
	while(r1<n2)
	{
		arr[j++] = r[r1++];
	}
}

void merge_sort(int arr[], int l, int r)
{

	if(l<r)
	{
		int mid = (l + r)/2;
		
		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);
		
		merge(arr, l, mid, r);
	}
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	
	int i = left - 1;
	int temp;
	
	for(int j = left; j<right; j++)
	{
		if(arr[j] < pivot)
		{
			temp = arr[++i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	temp = arr[++i];
	arr[i] = arr[right];
	arr[right] = temp;
	
	return i;
}

void quick_sort(int arr[], int left, int right)
{
	if(left < right)
	{
		int pivot = partition(arr, left, right);
		
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}

void heapify(vector<int> &v, int n, int i)
{
	int maxIndex = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if(left < n && v[left] > v[maxIndex])
		maxIndex = left;
	
	if(right < n && v[right] > v[maxIndex])
		maxIndex = right;
	
	if(maxIndex != i)
	{
		swap(v[i], v[maxIndex]);
		
		heapify(v, n, maxIndex);
	}
}

void heap_sort(int arr[], int n)
{
	vector<int> v (arr, arr + n);
	
	for(int i=(n/2) - 1; i>=0; i--)
	{
		heapify(v, n, i);
	}
	
	for(int i=n-1; i>0; i--)
	{
		swap(v[0], v[i]);
		
		heapify(v, i, 0);
	}
	
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	
	cout << endl;
	
}

void shell_sort(int arr[], int n)
{
	vector<int> v (arr, arr + n);
	
	for(int i=n/2; i>0; i /=2)
	{
		for(int j=0; j + i < n; j++)
		{
			if(v[j] > v[j + i])
				swap(v[j], v[j + i]);
		}
	}
	
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	
	cout << endl;
}

int main(int argc, char *argv[])
{
	//freopen("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Apna College/inputs.txt", "r", stdin);
	//freopen("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Apna College/outputs.txt", "a", stdout);
	/*
	int n, key;
	cin >> n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	
	cin >> key;
	*/
	
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	/*
	int a, b;
	
	cin >> a >> b;
	*/
	
	//shell_sort(arr, n);
	//heap_sort(arr, n);
	//quick_sort(arr, 0, n - 1);
	//merge_sort(arr, 0, n - 1);
	
	/*
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	*/
	
	//counting_sort(arr, n);
	//char_array();
	//record_breaking_day(arr, n);
	//max_subarray(arr, n);
	//insertion_sort(arr, n);
	//bubble_sort(arr, n);
	//bubble_sort_1(arr, n);
	//selection_sort(arr, n);
	//cout << binary_search(arr, n, key) << endl;
	//diamond(20);
	//find_prime(a, b);
	//cout << fact(a) << endl;
	//fibo(a);
}
