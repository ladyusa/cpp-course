#include <iostream>
#include "Vector.h"
#include "Point.h"
using namespace std;


Vector::Vector() {
	start = new Point();
	end = new Point();
}

Vector::Vector(Point *s, Point *e) 
	: start(s), end(e)
{
}

void Vector::offset(int dx, int dy) {
	start->offset(dx, dy);
	end->offset(dx, dy);
}	

Vector &Vector::add(const Vector &v2) const {
	Vector *v = new Vector(); 
	v->start = &this->start->add(*v2.start);
	v->end = &this->end->add(*v2.end);
	return *v;
}

string Vector::toString() const {
	string s =  start->toString() + " -> "
			   + end->toString();
	return s;
}
