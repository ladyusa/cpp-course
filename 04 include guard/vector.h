#include <string>

// -------------------------------------------
//              include guard
//
//   prevent multiple inclusions of header
//   ป้องกันการ include .h ซ้ำซ้อน
// -------------------------------------------
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
	Vector();
	Vector(int ex, int ey);
	Vector(int sx, int sy, int ex, int ey);

	void Offset(int d);
	void Offset(int dx, int dy);
	void Offset(Vector v);
	Vector Add(Vector v2) const;
	double Length() const;
	std::string ToString() const;

private:
	int start_x_, start_y_;
	int end_x_, end_y_;
};

#endif
