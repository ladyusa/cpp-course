#include <string>

class Vector {
private:
    Point *start;  
    Point *end;   
public:
    Vector(Point *start, Point *end);

    Vector *Add(Vector *v2);
    std::string ToString() const;
};