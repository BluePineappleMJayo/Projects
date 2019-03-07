#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
	int x;
	int y;
};
void dist(Point pt1, Point pt2);
float slope(Point pt1, Point pt2, bool useful);
void midPoint(Point pt1, Point pt2);
void equation(Point pt1, Point pt2,float);
void readPt(Point& pt1);
void showPt(Point pt1);
bool collinear(Point pt1, Point pt2, Point pt3);
//void menu(int x);

int main()
{
	Point pt1, pt2, pt3;
	char ans='y';
	int x;
	bool useful=false;
	do{
		cout << "\nPOINTLAND\n"
			<<"What do you want to do?\n"
			<<"1 - Find the distance between two points\n"
			<<"2 - Find Slope\n"
			<<"3 - Find a midpoint\n"
			<<"4 - Find an equation of a line\n"
			<<"5 - Determine if three points are collinear\n"
			<<"6 - Exit\n"
			<<"Selection => ";
		cin >> x;
		if(x<1||x>5)
		{
			cout<< "Sorry, I don't know what that is! Goodbye!";
			exit(0);
		}
		readPt(pt1);
		readPt(pt2);
		switch(x)
		{
			case 1:
				dist(pt1,pt2);
				break;
			case 2:
				slope(pt1,pt2,false);
				break;
			case 3:
				midPoint(pt1,pt2);
				break;
			case 4:
				equation(pt1,pt2, slope(pt1,pt2,true));
				break;
			case 5:
				readPt(pt3);
				if (collinear(pt1,pt2,pt3))
					cout << "The points are collinear";
				else
					cout << "The points are not collinear";
				break;
		}
	}while(ans == 'y');
	return 0;
}
void dist(Point pt1, Point pt2)
{
	float temp,temx,temy;
	temx=pt2.x-pt1.x;
	temy=pt2.y-pt1.y;
	temp = sqrt((temx*temx)+(temy*temy));
	cout << "Distance = "<< temp<<endl;
}
float slope(Point pt1, Point pt2, bool useful)
{
	float m;
	if(pt1.x==pt2.x)
	{
		cout<<"The slope is undefined.";
		exit;
	}
	m = (pt2.y-pt1.y)/(pt2.x-pt1.x);
	if (useful == true)
		return m;
	else
		cout << "Slope = "<< m;
		exit;
}
void midPoint(Point pt1, Point pt2)
{
	Point pt3;
	pt3.x=(pt1.x+pt2.x)/2;
	pt3.y=(pt1.y+pt2.y)/2;
	cout <<"Midpoint = ";
	showPt(pt3);
}
void equation(Point pt1, Point pt2, float m)
{
	int b;
	if (m==0)
		cout << "x = " << pt1.x;
	else
	b = pt1.y-m*(pt1.x);
	cout << "y = "<< m << "x + " << b;
}
void readPt(Point& pt1)
{
	char junk;
	cout << "Enter first point in format \"(x,y)\": ";
	cin >> junk >> pt1.x >> junk >> pt1.y >> junk;
}
void showPt(Point pt1)
{
	cout << "("<<pt1.x<<","<<pt1.y<<")";
}
bool collinear(Point pt1, Point pt2, Point pt3)
{
	int check12,check23;
	//Checks slope pt1 to pt2 and slope of pt2 to pt 3
	check12 = slope(pt1,pt2,true);
	check23 = slope(pt2,pt3,true);
	if((abs(check12-check23)) < .000001)
		return true;
	else
		return false;
}
