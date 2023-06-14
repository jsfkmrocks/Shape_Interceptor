#include <iostream>
#include <fstream>
#include "fraction.h"
#include "point.h"
using namespace std;


//Prototypes
Point FindOutsidePoint(Point *Q, Point p1, int HowMany);
int intersect(Point p1, Point p2, Point q1, Point q2);

int main()
{


	//Variables
	Point AllPoints[101];
	Point TestPoint;
	Point OutsidePoint;
	int NumIntersects = 0;
	int NumPoints;

	//Find NumPoints
	cin >> NumPoints;

	//Read in Values
	for(int i = 0; i < NumPoints + 1; i++)
	{
		cin>>AllPoints[i];
	}


	//Find Test Point
	TestPoint = AllPoints[NumPoints];

	//Find Outside Point
	OutsidePoint=FindOutsidePoint(AllPoints, TestPoint, NumPoints);

	//Test for Inside Circle
	for(int i = 1; i < NumPoints; i++)
	{
        NumIntersects = NumIntersects + intersect(TestPoint, OutsidePoint, AllPoints[i-1], AllPoints[i]);
	}

	//Evaluate Based on Test Results
	if(NumIntersects > 999999)
	{

	}
	else if(NumIntersects % 2 == 0)
	{
		cout << "Point is outside the polygon" << endl;
	}
	else
	{
		cout << "Point is inside the polygon" << endl;
	}


	return 0;
};


//Finding OutsideX
Point FindOutsidePoint(Point *Q, Point p1, int HowMany)
{
	Fraction OutsideX;
	Fraction OutsideY;
	Point p2(OutsideX, OutsideY);
	bool good;


	//Find Y Max
	for(int i = 0; i < HowMany; i++)
	{
		if(Q[i].getY() >= OutsideY)
		{
			OutsideY=(Q[i].getY());
		}
	}

	//Adding 1 to Y
	OutsideY = OutsideY + 1;

	//Finding X outside the Polygon
	do
	{
		OutsideX = OutsideX + 1;
		good = true;
		p2 = (OutsideX, OutsideY);
		for(int i = 0; i < HowMany - 1; i++)
		{
			if((Q[i] - p1) * (p2 - p1) == 0)
			{
				good = false;
			}
		}
	}
	while(good = false);
	//Return X
	return(OutsideX, OutsideY);
}



int intersect(Point p1, Point p2, Point q1, Point q2)
{
	//Variables
  Point r, s, v, q1p1, q2p1;
  Fraction t, u, d, vs, vr, online;
  int BorderTest;



  r = p2 - p1;
  s = q2 - q1;

  v = q1 - p1;
  d = r * s;

	q1p1 = q1 - p1;
  q2p1 = q2 - p1;

	//Test on Line
	online = q1p1 * q2p1;

	if(online == 0)
	{
		if ((q2.getY() <= p1.getY()) && (p1.getY() <= q1.getY()) || (q1.getY() <= p1.getY()) && (p1.getY() <= q2.getY()))
		{
			if ((q2.getX() <= p1.getX()) && (p1.getX() <= q1.getX()) || (q1.getX() <= p1.getX()) && (p1.getX() <= q2.getX()))
			{
				cout << "The point is on the edge" << endl;
				BorderTest = 1000000;
			}
		}
	}

  if(d == 0)
  {
    BorderTest = 0;
  }
  else
  {
		vs = v * s;
		vr = v * r;
		t = vs / d;
		u = vr / d;
		if((t >= 0 && t <= 1) && (u >= 0 && u <= 1))
		{
			BorderTest = 1;
		}
		else
		{
			BorderTest = 0;
		}
  }
  return BorderTest;
	cout << BorderTest << endl;
};
