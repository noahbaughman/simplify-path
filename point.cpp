/**
 * This illustrates operator overloading with a simple Point class.
 *
 */

#include <iostream>

 using namespace std;

class Point {
public:
   Point(int theX=0, int theY=0): x(theX), y(theY) {}
   Point operator+(Point addend);
   friend ostream& operator<<(ostream& os, Point ovr);
private:
   int x;   // x-coordinate of the Point
   int y;   // y-coordinate of the Point
};

// add two Points, component-wise
Point Point::operator+(Point addend)
{
   Point result;
   result.x = x + addend.x;
   result.y = y + addend.y;
   return result;
}

// output a Point
ostream& operator<<(ostream& os, Point ovr)
{
   os << "(" << ovr.x << ", " << ovr.y << ")";
   return os;
}

int main()
{
   Point p1(1,2);
   Point p2(3,4);
   Point p3 = p1 + p2;
   cout << p1 << " + " << p2 << " = " << p3 << endl;
}