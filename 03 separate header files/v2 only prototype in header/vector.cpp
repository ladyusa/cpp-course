#include <string>
#include <cmath>
#include "vector.h"
using namespace std;

// ---------------------------------
//  we must compile all .cpp file
// ---------------------------------

Vector::Vector() {
	start_x_ = 0;
	start_y_ = 0;
	end_x_ = 0;
	end_y_ = 0;
}
Vector::Vector(int ex, int ey) {
	start_x_ = 0;
	start_y_ = 0;
	end_x_ = ex;
	end_y_ = ey;
}
Vector::Vector(int sx, int sy, int ex, int ey) {
	start_x_ = sx;
	start_y_ = sy;
	end_x_ = ex;
	end_y_ = ey;
}
void Vector::Offset(int d) {
	start_x_ += d;
	start_y_ += d;
	end_x_ += d;
	end_y_ += d;
}
void Vector::Offset(int dx, int dy) {
	start_x_ += dx;
	start_y_ += dy;
	end_x_ += dx;
	end_y_ += dy;
}
void Vector::Offset(Vector v) {
	start_x_ += v.start_x_;
	start_y_ += v.start_y_;
	end_x_ += v.end_x_;
	end_y_ += v.end_y_;
}
Vector Vector::Add(Vector v2) const {
	Vector v3;
	v3.start_x_ = start_x_ + v2.start_x_;
	v3.start_y_ = start_y_ + v2.start_y_;
	v3.end_x_ = end_x_ + v2.end_x_;
	v3.end_y_ = end_y_ + v2.end_y_;
	return v3;
}
double Vector::Length() const {
	double x_2 = pow((end_x_ - start_x_), 2);
	double y_2 = pow((end_y_ - start_y_), 2);
	double length = sqrt(x_2 + y_2);
	return length;
}
string Vector::ToString() const {
	// (sx,sy) ---> (ex,ey)
	string s = "(" + to_string(start_x_) + "," + to_string(start_y_) + ")" 
	         + " ---> " 
			 + "(" + to_string(end_x_) + "," + to_string(end_y_) + ")";
	return s;
}

