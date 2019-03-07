#include <iostream>

using namespace std;

void input(int& n);
int fib(int n);

int main()
{
	int n, fibo;
do{	
	input(n);
	if (n<0)
		break;
	fibo=fib(n);
	if (n==1)
	cout << "The ";
	if (n==1)
		cout << " first ";
	else if(n==2)
		cout << " second ";
	else if (n==3)
		cout << " third ";
	else
		cout << n << "th ";
	cout <<" Fibbonacci number is " << fibo << "\n";
	}while(n>0);
	return 0;
}
void input(int& n)
{
	cout << "Which one do you want (negative to exit)? ";
	cin >> n;
}
int fib(int n)
{
	if (n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return (fib(n-1) + fib (n-2));
}
