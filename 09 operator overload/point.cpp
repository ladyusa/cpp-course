#include <string>
#include "point.h"
using namespace std;

Point::Point() : x_(0), y_(0) {}
Point::Point(int x, int y) : x_(x), y_(y) {}

void Point::Offset(int dx, int dy) {
    x_ += dx;
    y_ += dy;
}
// --------- stream insertion operator ------
ostream &operator<<(ostream &output, Point &p) {
    //output << "(" << to_string(p.x_) << "," << to_string(p.y_) << ")";
    output << p.ToString();
    return output;
}
// --------- unary operators ------
Point &Point::operator++() {   // ++p   (prefix increment operator)
    ++x_;
    ++y_;
    return *this;
}
Point Point::operator++(int i) {  // p++
    Point tmp = *this;
    x_++;
    y_++;
    return tmp;
}
Point &Point::operator+=(int n) {    // p += n
    x_ += n;
    y_ += n;
    return *this;
}

// --------- boolean operators ------
bool Point::operator==(Point &p) const {
    return this->x_ == p.x_ && this->y_ == p.y_;
}
bool Point::operator!=(Point &p) const {
    return this->x_ != p.x_ || this->y_ != p.y_;
}

// --------- arithmetic operators ------
Point &Point::operator+(Point &p) const {
    int new_x = x_ + p.x_;
    int new_y = y_ + p.y_;
    Point *result = new Point(new_x, new_y);
    return *result;
}
Point &Point::operator-(Point &p) const {
    int new_x = x_ - p.x_;
    int new_y = y_ - p.y_;
    Point *result = new Point(new_x, new_y);
    return *result;
}
string Point::ToString() const {
    string s = "(" + to_string(x_) + "," + 
                     to_string(y_) + ")";
    return s;
}