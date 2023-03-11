#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ofstream of;
char ch[50];
of.open("details.txt");

for(int i =0;i<5;i++)
{cout<<"enter your name";
cin.getline(ch,50);
of<<ch<<endl;
cout<<"enter your age";
cin>>ch;
of<<ch<<endl;
}

of.close();

ifstream ifs;
string l;
ifs.open("details.txt");
while(getline(ifs,l))
{
cout<<l<<endl;
}
ifs.close();
return 0;

}