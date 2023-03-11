#include<iostream>
#include<fstream>
using namespace std;
class human
{
public:
	string name;
	int age;
	bool alive;
	char newlinechar;
	void putdata();
	void getdata();
};
void human:: putdata()
{
	cout<<"name: ";
	//cin.getline(name,20);
	cin>>name;
	cout<<"age";
	cin>>age;
	cout<<"alive";
	cin>>alive;
	cin.get(newlinechar);
}
void human:: getdata()
{
	cout<<name<<" "<<age<<" "<<alive<<endl;

}

int main()
{
	human h[5];
	ofstream fout;
	fout.open("file.txt",ios::out);
//--//

	string name;
	int age;
	char newlinechar;
	bool alive;
	//--//
		cout<<"writing into the file from user input\n";
		for(int i=0;i<5;i++)
		{
			//h[i].putdata();
			cout<<"name: ";
	//cin.getline(name,20);
	cin>>name;
	cout<<"age";
	cin>>age;
	cout<<"alive";
	cin>>alive;
	cin.get(newlinechar);
	h[i].name=name;
	h[i].age=age;
	h[i].alive=alive;
			fout.write((char*)&h[i].name, sizeof(h[i]));

		}
		//fout.write((char*)&h,sizeof(h));
	fout.close();
	cout<<"getting obj values from the file now\n";
	ifstream fin;
	fin.open("file.txt",ios::in);
	fin.read((char*)&h,sizeof(h));
	for(int i=0;i<5;i++)
	{
		h[i].getdata();
	}
	
	fin.close();

	return 0;
}