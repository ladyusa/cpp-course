#include <string>
#include "point.h"
#include "vector.h"
using namespace std;

Vector::Vector(Point *start, Point *end) {
    this->start = start;
    this->end = end;
}
     // v3 = this + v2
    // this: (1,1) ---> (3,3)
    // v2:   (10,10) ---> (20,20)
    // v3:   (11,11) ---> (23,23)
Vector *Vector::Add(Vector *v2) {
    Point *new_start = start->Add(v2->start);
    Point *new_end = end->Add(v2->end);
    Vector *v3 = new Vector(new_start, new_end);
    return v3;
}

string Vector::ToString() const {
    return start->ToString() + "-->" + end->ToString();
}