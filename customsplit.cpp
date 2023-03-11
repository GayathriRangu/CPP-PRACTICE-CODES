#include<iostream>
#define max 8
using namespace std;

string strings[max];
int len(string str)
{
	int count,length=0;
	for(count=0;str[count]!='\0';count++)
		length++;
	return length;
		

}
void split(string str,char seperator)
{
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;

while (i <= len(str))  
    {  
        if (str[i] == seperator || i == len(str))  
        {  
            endIndex = i;  
            string subStr = "";  
            subStr.append(str, startIndex, endIndex - startIndex);  
            strings[currIndex] = subStr;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
        }     

}

int main()
{
string str;
getline(cin,str);
cout<<str;
char seperator=' ';
split(str,seperator);

   for (int i = 0; i < max; i++)  
    {  
        cout << "\n i : " << i << " " << strings[i];  
    }  
return 0;

}