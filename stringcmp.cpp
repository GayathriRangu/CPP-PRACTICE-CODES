#include <iostream>
#include<cstring>
using namespace std;
int main()
{
char key[]="apple";
char buffer[20];
do{
cout<<"what is my favorite fruit?";
cin>>buffer;
}while(strcmp(key,buffer)!=0);
cout<<"correct"<<endl;
return 0;
}