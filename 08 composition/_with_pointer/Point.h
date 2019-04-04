#include <string>

#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(int x = 0, int y = 0);

	void offset(int dx, int dy);
	
	Point &add(const Point &p2) const;
	std::string toString() const;

private:
	int	x;
	int y;
};

#endif