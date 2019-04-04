#include <iostream>
using namespace std;

// ---------- const object -----------
class Point {
public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) {
    }
    void Offset(int dx, int dy) {
        x_ += dx;
        y_ += dy;
    }
    Point &Add(const Point &p) const {
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

int main() {
    Point p1(1,1);

    // const object : ทำให้ไม่สามารถเปลี่ยนแปลง object นี้ได้
	//   - จะเรียกฟังก์ชันที่เป็น const เท่านั้น
    const Point p2(2,2);  

    p1.Offset(10,10);
    p2.Offset(10,10);  // จะเรียก Offset ไม่ได้
}