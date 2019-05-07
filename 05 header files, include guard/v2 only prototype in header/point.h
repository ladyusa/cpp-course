#include <string>
// ----- ไม่ควรใช้ "using namespace" ในไฟล์ .h

class Point {
private:
    int x, y;
public:
    Point(int x, int y);

    Point *Add(Point *other);
    std::string ToString() const;
};