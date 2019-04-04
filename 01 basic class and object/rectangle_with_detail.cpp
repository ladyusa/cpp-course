#include <iostream>
using namespace std;

// ----------------
// class is a user-defined type
//
// class ประกอบด้วย (** encapsulate/encapsulation **)
//   - data : member, data member, field, attribute,
//            instance variable
//   - function : member function, method, operation,
//                behavior
// 
// function is one type of ** abstraction ** การกำหนดสาระสำคัญ
//   - ให้เห็นแค่สิ่งที่สำคัญ (รู้ว่าทำอะไรได้ โดยไม่จำเป็นต้องรู้ว่าภายในทำงานอย่างไร)
//   - สามารถใช้งาน function ได้ โดยไม่ต้องเข้าใจการเขียนโค้ดข้างในฟังก์ชัน
// 
// ตัวระบุการเข้าถึง : access modifier / access specifier
//       - public : เข้าถึงได้จากที่ใด ๆ 
//       - private : เข้าถึงได้จากภายในคลาสตัวเองเท่านั้น
//   ** member function ส่วนใหญ่จะเป็น public
//   ** data member ควรเป็น private
// 
// constructor : คล้าย function
//   ถูกเรียกตอนสร้าง object
//
// Naming convention : รูปแบบการตั้งชื่อ 
//   - class : CamelCase, MyRectangle, CreditCard
//       - data member : snake_case_, width_, length_
//       - member function : CamelCase, ChangeSize
//   - local variable : snake_case
//
// (ตาม Google: https://google.github.io/styleguide/cppguide.html)
//
class Rectangle { // user-defined type
public:
	// constructor
	Rectangle(int w, int l) {
		width_ = w;
		length_ = l;
	}

	// accessor function : not modify data in object
	int Area() const {
		return width_ * length_;
	}

	// accessor function : not modify data in object
	int Perimeter() const {
		return 2 * (width_ + length_);
	}

	// mutator function : modify data in object
	void ChangeSize(int d) {
		width_ += d;
		length_ += d;
	}

	int GetWidth() const {
		return width_;
	}

	int GetLength() const {
		return length_;
	}

	void SetWidth(int w) {
		width_ = w;
	}

	void SetLength(int l) {
		length_ = l;
	}

	// accessor function
	void Print() const {
		cout << width_ << ", " << length_ << endl;
	}
private:
	int width_;  // int is a primitive type
	int length_;
};

int main() {

	int width, length;
	cout << "Enter width: ";
	cin >> width;

	cout << "Enter length: ";
	cin >> length;

	// r is an object of class Rectangle
	// r is an instance of class Rectangle
	// "object" is a "class"
	//
	// we create an object r of class Rectangle
	// we instantiate an object r of class Rectangle
	Rectangle r(width, length);

	cout << "Area: " << r.Area() << endl;
	cout << "Perimeter: " << r.Perimeter() << endl;

	// r is an implicit parameter
	// size is an explicit parameter
	r.ChangeSize(1);
	r.Print();
}















