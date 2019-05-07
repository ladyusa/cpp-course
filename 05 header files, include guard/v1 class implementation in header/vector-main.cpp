#include <iostream>
#include <cmath>
#include "point.h"
#include "vector.h"
using namespace std;

// ---------------------------------
//  we must compile all .cpp file
// ---------------------------------

int main() {
    Point *p1 = new Point(1,1);
    Point *p2 = new Point(3,3);
    Point *pAdd = p1->Add(p2);

    Vector *v1 = new Vector(p1,p2);

    cout << "p1: " << p1->ToString() << endl;
    cout << "p2: " << p2->ToString() << endl;
    cout << "pAdd: " << pAdd->ToString() << endl;

    cout << "v1: " << v1->ToString() << endl;

    Point *p3 = new Point(10,10);
    Point *p4 = new Point(20,20);

    Vector *v2 = new Vector(p3,p4);

    Vector *v3 = v1->Add(v2);

    cout << "v2: " << v2->ToString() << endl;
    cout << "v3: " << v3->ToString() << endl;

}