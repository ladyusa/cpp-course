#include <iostream>
using namespace std;

//  ------------- destructor -----------
//     - ถูกเรียก เมื่อโปรแกรมออกจาก scope
//       ของการประกาศ/สร้าง object นี้
//
//     - destructor จะถูกเรียกใน reverse order
//       ของ constructor ใน scope นั้น
//
//     - ใช้เมื่อ
//         - object has dynamically allocated memory
//         - closing files

class Point {
public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) {
        cout << " ---- in constructor: " << ToString() << endl;
    }
    ~Point() {
        cout << " ---- in DESTRUCTOR: " << ToString() << endl;
    }
    void Offset(int dx, int dy) {
        x_ += dx;
        y_ += dy;
    }
    Point &Add(Point &p) const {
        int new_x = x_ + p.x_;
        int new_y = y_ + p.y_;
        Point *result = new Point(new_x, new_y);
        return *result;
    }
    std::string ToString() const {
        string s = "(" + to_string(x_) + "," 
                       + to_string(y_) + ")";
        return s;
    }

    string name_;
private:
    int x_;
    int y_;
};

void func() {
    Point pFunc1(8,8), pFunc2(9,9);
}

int main() {
    Point p1(1,1);
    Point p2(2,2);
    func();

    Point p5(5,5);
}