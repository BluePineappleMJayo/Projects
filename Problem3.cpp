#include <iostream>
using namespace std;

void input(int&,int&);

int main()
{
	int a,b,c,d,num,denom;
	char operation;
	char again = 'y';
	do{
		cout << "Enter first fraction: ";
		input (a,b);
		cout << "Enter the operation: ";
		cin >> operation;
		cout << "Enter the second fraction: ";
		input(c,d);
		
		switch (operation)
		{
			case '+':
				num = (a*d)+ (c*b);
				denom = b*d;
				cout << "Sum = " << num << "/" << denom;
				break;
			case '-':
				num = (a*d)-(c*b);
				denom = d*b;
				cout << "Difference = " << num << "/" << denom;
				break;
			case '/':
				num = a*d;
				denom = b*c;
				cout << "Quotient = " << num << "/" << denom;
				break;
			case '*':
				num = a*c;
				denom = d*b;
				cout << "Product = " << num << "/" << denom;
				break;
			default:
			cout << "Sorry, I didn't catch that.";
			break;
		}
		cout << "\nContinue? (Y/N): ";
		cin >> again;
	}while (again == 'y' || again == 'Y');
	return 0;
}
void input (int& a, int& b)
{
	char slash;
	cin >> a >> slash >> b;
}
