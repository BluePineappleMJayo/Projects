//fucking around to print out a graph when given the number of cycles or the number of colors, up to 9
// the user wants
//maybe on the other feature so you can pick two numbers and find their color without needing the consult the graph
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void input(int& n, int& num);
// takes in the number of colors

void color(int n, int i);
// determines the color for box/ number

int main()
{
	int n=0, i,num=1;
	string col;
	input(n,num);
	for( i=0; i<256; i++)
	{
		if (i%10 == 0)
			cout << "\n";
		color(n,i);
	}
	return 0;
}
void input (int& n, int& num)
{
	int t,x,i;
	char ans='Y';
	cout << "Enter your desired amount of colors(256 max please): ";
	cin >> n;
	do{
		cout<< "Did you want to check on any multiplied numbers or numbers beyond 256? (Y/N): ";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			break;
		cout << "How many? (minimum 2, to check specific number do your number and 1) : ";
		cin >> x;
		for (i=1;i<=x;i++)
		{
			cout<<"Enter number " << i <<": ";
			cin >> t;
			num= num*t;
		}
		cout << "Your number will show up as ";
		color(n,num);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "\nThe remainder of " << num << " and " << n << " is: " << num%n;
		ans = 'n';
	}while (ans == 'Y' || ans == 'y');
}
void color(int n, int i)
{
	int color = i%n;
	if (color == 0)
		color = 10;
	if(i<10)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << "| " << i << " | ";
	}
	else
	{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << "| " << i << " |";
	}
}
