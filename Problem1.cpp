#include <iostream>
#include <cmath>

using namespace std;

void getDim(float& a);
void getDim(float& a, float& b);
void getDim(float& a, float& b, float& c);
float area(float a);
float area(float a, float b);
float area(float a, float b, float c);
float perim(float a);
float perim(float a, float b);
float perim(float a, float b, float c);
void display(float area, float perim, int shape);
const float PI = 3.141592654;

int main()
{
	float ara, peri, a, b, c;
	int shape;
	cout<< "AREA/PERIMETER CALCULATOR \nSelect a shape: \nCircle (1)  Rectangle (2)  Triangle (3) Exit (4) /nEnter selection => ";
	cin >> shape;
	switch (shape)
	{
		case 1:
			getDim(a);
			ara= area(a);
			peri= perim(a);
			break;
		case 2:
			getDim(a,b);
			ara= area(a,b);
			peri= perim(a,b);
			break;
		case 3:
			getDim(a,b,c);
			ara= area(a,b,c);
			peri= perim(a,b,c);
			break;
		default:
			cout << "Bye... ";
			break;			
	}
	display(ara,peri,shape);
	return 0;
}

void getDim(float& a)
{
	cout << "Enter the circle radius: ";
	cin >> a;
}
void getDim(float &a, float &b)
{
	cout << "Enter rectangle length: ";
	cin >> a;
	cout << "Enter rectangle width: ";
	cin >> b;
}
void getDim(float &a, float& b, float& c)
{
	cout << "Enter side 1 of triangle: ";
	cin >> a;
	cout << "Enter side 2 of triangle: ";
	cin >> b;
	cout << "Enter side 3 of triangle: ";
	cin >> c;
}
float area(float a)
{
	return (PI*pow(a,2));
}
float area(float a, float b)
{
	return (a*b);
}
float area(float a, float b, float c)
{
	float s;
	s= (a+b+c)/2.0;
	float temp = sqrt(s*(s-a)*(s-b)*(s-c));
	return (temp);
}
float perim(float a)
{
	return (2*PI*a);
}
float perim (float a, float b)
{
	return ((2*a)+(2*b));
}
float perim(float a, float b, float c)
{
	return(a+b+c);
}
void display(float area, float perim, int shape)
{
	switch (shape)
	{
		case 1:
			cout << "The circle area = " << area << "\nPerimeter= " << perim;
			break;
		case 2:
			cout << "The rectangle area = " << area << "\nPerimeter = "<< perim;
			break;
		case 3:
			cout << "The triangle area = " << area << "\nPerimeter = " << perim;
			break;
		default:
			break;
	}
}
