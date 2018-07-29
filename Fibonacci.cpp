//Fibonacci.cpp

#include<iostream>
using namespace std;
int f(int n)
{
	//out
	if(n==0 || n==1)
		return 1;
	else
		return f(n-1)+f(n-2);
}
int main()
{
	int n;
	cout<<"Input the n:";
	cin>>n;
	cout<<"The result is"<<f(n);
	return 0;
}
