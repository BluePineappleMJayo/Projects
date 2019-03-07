#include <iostream>
#include <cmath>

using namespace std;

void input( int& n, float& approx);
float sqrrtApprox(int n, float approx);

int main()
{
	int n;
	float approx, newApprox;
	input(n, approx);
	newApprox = sqrrtApprox(n,approx);
	
	cout << "The square root of " << n << "=" << newApprox;
	return 0;
}
void input( int& n, float & approx)
{
	cout<< "Enter n: ";
	cin >> n;
	cout << "Enter approximation: ";
	cin >> approx;
}
float sqrrtApprox(int n, float approx)
{
	float error = .00001, newApprox,difference;
	do{
		newApprox = ((n/approx)+approx)/2.0;
		difference = newApprox-approx;
		if(fabs(difference) <= error)
			break;
		approx = newApprox;
	}while(fabs(difference) > error);
	return newApprox;
	
}
