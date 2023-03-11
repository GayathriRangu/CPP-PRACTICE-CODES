#include<iostream>
#include<fstream>
using namespace std;
class details
{
public:
	int rollno;
	string name;
	int val;
	void input();
	void output();
};
//function to input the object details to the file
void details::input()
{
	ofstream fout;
	details d;
	fout.open("inputfileh.txt",ios::app);
	
	/*
	int rollno1=20;
	string name1="greena";
	int val1=2000;*/
	int rollno1;
	int val1;
	string name1;
	while(fout)
	{
		//getline(cin,rollno1);
		getline(cin,name1);
		getline(cin,val1);
		//d.rollno=rollno1;
		d.name=name1;
		d.val=val1;
		fout.write((char*)&d,sizeof(d));
		if(name1==-1)
		{
			break;

		}

	}
	/*d.rollno=rollno1;
	d.name=name1;
	d.val=val1;
	fout.write((char*)&d,sizeof(d));
	rollno1=30;
	name1="meeena";
	val1=3000;
	d.rollno=rollno1;
	d.name=name1;
	d.val=val1;
	fout.write((char*)&d,sizeof(d));*/
	fout.close();

}

//function to output the object details from the file
void details::output()
{
	ifstream fin;
	fin.open("inputfileh.txt",ios::in);
	details d;
	fin.read((char*)&d,sizeof(d));
	string maxguy;
	int max=0;
	while(!fin.eof())
	{
		cout<<d.rollno;
		cout<<d.name;
		cout<<d.val;
		if(d.val>max)
			max=d.val;
			maxguy=d.name;
		
		fin.read((char*)&d,sizeof(d));

	}
	fin.close();
	cout<<maxguy;

}


int main()
{
		details det;
		det.input();
		det.output();
		return 0;

}