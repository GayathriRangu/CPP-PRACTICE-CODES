#include <iostream>
#include<cstring>
using namespace std;
int main()
{
char key[20],buffer[20];
cout<<"enter key string"<<endl;
cin.getline(key,20);
cout<<"enter the buffer string";
cin.getline(buffer,20);
strcat(key,buffer);
cout<<key<<endl;
cout<<buffer<<endl;


}