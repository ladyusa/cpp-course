#include <string>
// ----- ไม่ควรใช้ "using namespace" ในไฟล์ .h

// -------------------------------------------
//              include guard
//
//   prevent multiple inclusions of header
//   ป้องกันการ include .h ซ้ำซ้อน
// -------------------------------------------
#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    // p3 = this + p2
    // this: (1,1) 
    // p2:   (10,10)
    // p3:   (11,11)
    Point *Add(Point *other) {
        int new_x = this->x + other->x;
        int new_y = this->y + other->y;
        Point *p3 = new Point(new_x, new_y);
        return p3;
    }
    std::string ToString() const {
        return "(" + std::to_string(x) + ","
                   + std::to_string(y) + ")";
    }
};

#endif
