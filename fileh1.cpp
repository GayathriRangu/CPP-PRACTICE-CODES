#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	
	char name[20];
	int rollno;
	int phno;
	ifstream fin("file.txt");
	while(!fin.eof())
	{
		fin>>name>>rollno>>phno;
		fin.close();
		cout<<name<<""<<rollno<<""<<phno<<"";

	}
	return 0;

}
//only workingg for reading one line . doesnt read the next line elements