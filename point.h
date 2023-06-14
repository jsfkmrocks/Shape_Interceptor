#include <cstdint>
#include <iostream>
#include "fraction.h"

#ifndef _POINT_H
#define _POINT_H

class Point {
public:
	//Constructor & Destructor num/den
	Point(Fraction x = Fraction(0), Fraction y = Fraction(0));
	~Point(void) {}

	//rhs == right hand side, as in the right hand side of the opereator
	Point operator+(Point rhs);//Add points
	Point operator-(Point rhs);//Subtract points
	Point operator*(Fraction rhs);//Scalar Multiplications
	Fraction operator*(Point rhs);//Cross Multiplier

	bool operator==(Point rhs);//Compares equality
	bool operator!=(Point rhs);//Compares inequality

	Fraction getX() {return x; } //getter for numerator
	Fraction getY() {return y; } //getter for denominator

private:
	Fraction
	x,
	y;
};

std::istream &operator>>(std::istream &,Point &);
std::ostream &operator<<(std::ostream &,Point);

#endif
