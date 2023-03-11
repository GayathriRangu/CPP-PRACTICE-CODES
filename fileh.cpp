#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout;//create an object of ofstream to write the content onto the file from the user input(keyboard)
	string line,line2;//this is where we store the user input from console or data read from the text file in the program
	fout.open("file1.txt");//next up, open the file
	while(fout)//check if the file has opened properly or not using its object, if yes, returns a positive value
	{
		getline(cin,line);//getline from the console and read it into a string so that you can wi=rite the line to the file
		if(line=="-1")//when to stop reading is defined by this condition
			break;
		fout<<line<<endl;//fout is used because we are writing the line onto the file
	}
	fout.close();//closing is very important


//almost same format is followed for reading from the file
	ifstream fin;//ifstream object is created
	fin.open("file1.txt");//open the file first
	while(fin)//check if its opened or not
	{
		getline(fin,line2);//get the string from the file into this variable
		cout<<line2<<endl;//print the read string from the file onto the display
	}
	fin.close();//close it again
	return 0;
}