#include <iostream>

// ---------------------------------
//    static variable/function
//    เรียกใช้ได้โดยไม่ต้องสร้าง object
//    และเรียกใช้จากชื่อคลาสได้ (จากชื่อ object ก็ได้)
//      - static variable (class variable)
//          - ทุก object ของคลาสนี้ share ตัวแปร static
//            ตัวเดียวกัน
//      - static function (class function)
//          - ส่วนใหญ่ใช้ประมวลผล static variable
//          - ไม่สามารถใช้ตัวแปรที่ไม่ใช่ static ได้
// ---------------------------------
class Employee {
public:
    Employee(std::string n);
    ~Employee();

    std::string getName() const;
    static int getCount();  // static function

    int my_count_;       // object variable

private:
    std::string name_;   // object variable (instance variable)
    static int count_;   // class variable 
}; 
