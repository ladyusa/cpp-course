#include <string>
#include "point.h"
using namespace std;

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point *Point::Add(Point *other) {
    int new_x = this->x + other->x;
    int new_y = this->y + other->y;
    Point *p3 = new Point(new_x, new_y);
    return p3;
}

string Point::ToString() const {
    return "(" + to_string(x) + ","
               + to_string(y) + ")";
}