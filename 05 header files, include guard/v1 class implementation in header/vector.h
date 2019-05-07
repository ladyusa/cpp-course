#include <string>
#include "point.h"
// ----- ไม่ควรใช้ "using namespace" ในไฟล์ .h

// include guard
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    // (x1,y1) ----> (x2,y2)
    Point *start;   // double start_x, start_y;
    Point *end;     // double end_x, end_y;
public:
    Vector(Point *start, Point *end) {
        this->start = start;
        this->end = end;
    }
     // v3 = this + v2
    // this: (1,1) ---> (3,3)
    // v2:   (10,10) ---> (20,20)
    // v3:   (11,11) ---> (23,23)
    Vector *Add(Vector *v2) {
        Point *new_start = start->Add(v2->start);
        Point *new_end = end->Add(v2->end);
        Vector *v3 = new Vector(new_start, new_end);
        return v3;
    }
    std::string ToString() {
        return start->ToString() + "-->" + end->ToString();
    }
};

#endif
