#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a,b,c, descriminate,x1,x2,realPart,imagiPart;
	do{
		cout << "\nEnter a: ";
		cin >> a;
		if (a != 0)
			break;
		else
		cout << "\nA cannot be 0 -- reenter.";
	}while(a==0);
	cout << "\nEnter b: ";
	cin >> b;
	cout << "\nEnter c: ";
	cin >> c;
	descriminate = b*b - 4*a*c;
	if ( descriminate > 0)
	{
		x1 = (-b + sqrt(descriminate))/2*a;
		x2 = (-b - sqrt(descriminate))/2*a;
		cout << "\nThere are two real solutions: " << x1 << " and " << x2;
	}
	else if(descriminate == 0)
	{
		x1= (-b + sqrt(descriminate))/2*a;
		cout << "\nThere is one real solution: " << x1;
	}
	else
	{
		realPart = -b/2*a;
		imagiPart = sqrt(-descriminate)/ 2*a;
		cout << "\nThere are two complex solutions: " << realPart << " + " << imagiPart << "i"
			<< " and " << realPart << " - " << imagiPart << "i";
	}
	return 0;
}
