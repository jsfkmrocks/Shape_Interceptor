#include "point.h"
#include "fraction.h"

Point::Point(Fraction x,Fraction y)
{
  this->x = x;
  this->y = y;
}

//Point operator+(Point rhs);
Point Point::operator+(Point rhs)
{
  Fraction
    s,t;
  s = x + rhs.x;
  t = y + rhs.y;
  return Point(s,t);
}

//Point operator-(Point rhs);
Point Point::operator-(Point rhs)
{
  Fraction
    s,t;
  s = x - rhs.x;
  t = y - rhs.y;
  return Point(s,t);
}

//Scalar Multiplications
Point Point::operator*(Fraction rhs)
{
  Fraction
  s,
  t;

  s = x*rhs;
  t = y*rhs;

  return Point(s,t);
}

//Cross Multiplication
Fraction Point::operator*(Point rhs)
{
  return (x*rhs.y)-(y*rhs.x);
}

//bool operator==(Point rhs);
bool Point::operator==(Point rhs)
{
  return Fraction(x) == Fraction(rhs.x) || Fraction(y) == Fraction(rhs.y);
}

//bool operator!=(Point rhs);
bool Point::operator!=(Point rhs)
{
  return Fraction(x) != Fraction(rhs.x) || Fraction(y) != Fraction(rhs.y);
}






std::istream &operator>>(std::istream &is,Point &p) {
  Fraction
    n,d;
  char
    lp, comma, rp;

  is >> lp >> n >> comma >> d >> rp;

  p=Point(n,d);

  return is;
}

std::ostream &operator<<(std::ostream &os,Point p) {

  os << "(" << p.getX() << "," << p.getY() << ')';

  return os;
}
