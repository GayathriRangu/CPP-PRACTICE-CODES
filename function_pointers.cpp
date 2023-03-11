#include <bits/stdc++.h>
using namespace std;

int _plus(int a, int b)
{
	return a + b;
}

int _minus(int a, int b)
{
	return a - b;
}

int _multiply(int a, int b)
{
	return a * b;
}

int _divide(int a, int b)
{
	return a / b;
}

int main(int argc, char *argv[]) 
{
    int (*fnptr[4]) (int, int);
    
    fnptr[0] = _plus;
    fnptr[1] = _minus;
    fnptr[2] = _multiply;
    fnptr[3] = _divide;
    
    cout << fnptr[atoi(argv[3])](atoi(argv[1]), atoi(argv[2])) << endl;
    
    return 0;
}
