#include <iostream>
#include <cmath>
using namespace std;

// --------------------------------------------
//   Composition: การประกอบกันของคลาส/อ๊อบเจ็กต์
// --------------------------------------------
//     - การมี data member เป็นอ๊อบเจ็กต์ของคลาส
//
//     - data member ในคลาส แบ่งได้เป็น 2 ประเภท
//       - primitive type: เรียกว่า attribute, คุณลักษณะของคลาส/อ๊อบเจ็กต์
//       - class type: เรียกว่า composition ---> เกิดเป็นความสัมพันธ์ระหว่างคลาส
//  
//     - composition เป็นความสัมพันธ์ระหว่างคลาสประเภทหนึ่ง
//           เป็นความสัมพันธ์แบบ "การมี" (Has-A relationship)
//
//       เฌอปราง  เป็น  นักร้อง  ---> "object" is a "class"
//       เกษตรศาสตร์  เป็น มหาวิทยาลัย ---> "object" is a "class"
//       มหาวิทยาลัย  มี  คณะ ---> "class" has a "class" (composition)
//       มหาวิทยาลัย  มี  ชื่อ/name ---> "class" has a attribute
//
//         class, object, data member
//       สินค้า           class      
//       ราคา           data member of class สินค้า
//       โค้ก            object of class สินค้า
//       ซุปเปอร์มาเก็ต    class
//       บิ๊กซี            object of class ซุปเปอร์มาเก็ต
//       ท็อป            object of class ซุปเปอร์มาเก็ต
//
//      class, object, data member
//    barcode        data member (primitive) in class Product
//    BigC           object of class SuperMarket
//    Tops           object of class SuperMarket
//    Central        object of class Mall
//    price          data member (primitive) in class Product
//    category       data member (primitive) in class Product
//    product        class (has data member: barcode, price, category)
//    customer       class (has data member: name, id, age)
//    cashier        class (has data member: name, title)
//    supermarket    class (has data member: branch, name)
//
//     - Vector มี Point เป็น data member
//     - Bank มี Customer เป็น data member
//  - เราเรียก Composition ว่า ความสัมพันธ์แบบ "การมี" หรือ
//    "Has-A" Relationship
//     - Vector มี Point
//     - Bank มี Customer
//
class Point {
private:
    int x, y;
public:
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    // p3 = this + p2
    // this: (1,1) 
    // p2:   (10,10)
    // p3:   (11,11)
    Point Add(Point p2) {
        int new_x = this->x + p2.x;
        int new_y = this->y + p2.y;
        Point p3(new_x, new_y);
        return p3;
    }
    string ToString() const {
        return "(" + to_string(x) + ","
                   + to_string(y) + ")";
    }
};

class Vector {
private:
    // (x1,y1) ----> (x2,y2)
    Point start;   // double start_x, start_y;
    Point end;     // double end_x, end_y;
public:
    Vector() {

    }
    Vector(Point start, Point end) {
        this->start = start;
        this->end = end;
    }
     // v3 = this + v2
    // this: (1,1) ---> (3,3)
    // v2:   (10,10) ---> (20,20)
    // v3:   (11,11) ---> (23,23)
    Vector Add(Vector v2) {
        Point new_start = start.Add(v2.start);
        Point new_end = end.Add(v2.end);
        Vector v3(new_start, new_end);
        return v3;
    }
    string ToString() {
        return start.ToString() + "-->" + end.ToString();
    }
};

int main() {
    Point p1(1,1), p2(3,3);
    Vector v1(p1,p2);

    Point pAdd = p1.Add(p2);
    cout << "p1: " << p1.ToString() << endl;
    cout << "p2: " << p2.ToString() << endl;
    cout << "pAdd: " << pAdd.ToString() << endl;

    cout << "v1: " << v1.ToString() << endl;

    Point p3(10,10), p4(20,20);
    Vector v2(p3,p4);

    Vector v3 = v1.Add(v2);

    cout << "v2: " << v2.ToString() << endl;
    cout << "v3: " << v3.ToString() << endl;

}