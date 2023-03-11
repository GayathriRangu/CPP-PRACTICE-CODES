#include<bits/stdc++.h>

using namespace std;

class student
{
	string name;
	public:
	int age;
	bool gender;
	
	void print_info()
	{
		cout << name << " " << age << " " << gender << endl;
	}
	
	void set_name(string name1)
	{
		name = name1;
	}
};

int main()
{
	//freopen("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Apna College/inputs.txt", "r", stdin);
	//freopen("/home/surja/Documents/Avi Study Docs/Programming/C++/Terminal Codes/Apna College/outputs.txt", "a", stdout);
	
	/*
	student a;
	a.name = "Surja";
	a.age = 32;
	a.gender = 0;
	*/
	
	student arr[1];
	string name1;
	cin >> name1 >> arr[0].age >> arr[0].gender;
	
	arr[0].set_name(name1);
	arr[0].print_info();
	
}
