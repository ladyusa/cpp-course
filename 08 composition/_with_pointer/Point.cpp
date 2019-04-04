#include <string>
#include "Point.h"
using namespace std;


Point::Point(int x, int y) 
	: x(x), y(y) {
}

void Point::offset(int dx, int dy)  {
	x += dx;
	y += dy;
}

Point &Point::add(const Point &p2) const {
	Point *p = new Point(x + p2.x, y + p2.y);
	return *p;
}

string Point::toString() const {
	string s = "(" + to_string(x) + ", " +
				to_string(y) + ")";
	return s;
}

