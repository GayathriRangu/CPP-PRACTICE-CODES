#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ofstream of;
of.open("txtfile.txt");
if(of.is_open())
{
	of<<"welcome\n";
	of<<"c++ practice\n";
	of.close(); 

}
else 
{cout<<"file open failed";}
ifstream ifs;
ifs.open("txtfile.txt");
string str;
if(ifs.is_open())
{
	while(getline(ifs,str))
	{
		cout<<str<<endl;
	}
ifs.close();
	
}
else{
	cout<<"file open failed"<<endl;
}



return 0;



}