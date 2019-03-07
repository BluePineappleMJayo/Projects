#include <iostream>
using namespace std;

int findingFibN(int);

int main()
{
	int n,fibN;
	char again = 'y';
	do{
	do
	{
		cout << "Enter a positive integer n: ";
		cin >> n;
	}while (n<=0);
	fibN= findingFibN(n);
	cout << n << "th Fibonacci number is: " << fibN
		<< "\n Continue?(Y/N): ";
		cin >> again;
	}while(again == 'y' || again == 'Y');
}
int findingFibN(int n)
{
	int temp1=0,temp2=1,next=0;
	if (n == 1)
		return temp1;
	if (n== 2)
		return temp2;
	int i;
	{
		for(i=2; i<n; i++)
		{
			next = temp1+temp2;
			temp1=temp2;
			temp2=next;
		}
	}
	return next;
}
