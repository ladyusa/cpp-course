#include <iostream>

class Point {

    // stream insertion operator overload
    friend std::ostream &operator<<(std::ostream &output, Point &p);

public:
    Point();
    Point(int x, int y);

    void Offset(int dx, int dy);
    
    // ----- boolean operators -----
    bool operator==(Point &p) const;
    bool operator!=(Point &p) const;
    // bool operator<(Point &p) const;
    // bool operator<=(Point &p) const;
    // bool operator>(Point &p) const;
    // bool operator>=(Point &p) const;

    // ----- arithmetic operators -----
    Point &operator+(Point &p) const;
    Point &operator-(Point &p) const;

    // ---- unary operators ----
    Point &operator++();     // ++p
    Point operator++(int i); // p++

    Point &operator+=(int n);     // p += n

    std::string ToString() const;

private:
    int x_;
    int y_;
};