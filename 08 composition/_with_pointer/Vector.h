#include <string>
#include "Point.h"

#ifndef VECTOR_H
#define VECTOR_H

// -----------------------------------------------------
//   				Composition
//
//  - เป็นหลักการในการประกอบคลาสหลายคลาสเข้าด้วยกัน 
//  - คือ 
//     - การมี object ของคลาสอื่นในคลาสเรา 
//     - การมี object ของคลาสอื่น เป็น instance var ในคลาสเรา
//  - เช่น
//     - Vector มี Point เป็น instance variable
//     - Bank มี Customer เป็น instance variable
//  - เราเรียก Composition ว่า ความสัมพันธ์แบบ "การมี" หรือ
//    "Has-A" Relationship
//     - Vector มี Point
//     - Bank มี Customer
// -----------------------------------------------------

class Vector {
public:
	Vector();
	Vector(Point *s, Point *e);

	void offset(int dx, int dy);
	Vector &add(const Vector &v2) const;
	std::string toString() const ;

private:  
	Point *start;
	Point *end;
};  
#endif
