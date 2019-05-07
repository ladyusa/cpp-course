#include <iostream>
using namespace std;

//------------------------------------
//   "class" เป็น user-defined type
//------------------------------------
// ต้องสามารถสร้าง object หรือวัตถุออกมาได้หลาย ๆ วัตถุ
//   - instance มีความหมายเดียวกับ object ในการโปรแกรมเชิงวัตถุ
//
//------------------------------------
// class ประกอบด้วย (** encapsulate/encapsulation **)
//------------------------------------
//       (1) data เรียกว่า data member (ชื่ออื่น: attribute, property, member, 
//                                          instance variable)
//       (2) function เรียกว่า member function
//                           (ชื่ออื่น: method, operationม behavior)
//              - ใช้ประมวลผล data member 
// 
// function is one type of ** abstraction ** การกำหนดสาระสำคัญ
//   - behavioral abstraction
//   - ให้เห็นแค่สิ่งที่สำคัญ (รู้ว่าทำอะไรได้ โดยไม่จำเป็นต้องรู้ว่าภายในทำงานอย่างไร)
//   - สามารถใช้งาน function ได้ โดยไม่ต้องเข้าใจการเขียนโค้ดข้างในฟังก์ชัน
// class is another type of ** abstraction ** การกำหนดสาระสำคัญ
//   - data abstraction
// 
//------------------------------------
// access specifier / access modifier : ตัวระบุการเข้าถึง
//------------------------------------
//       - public : เข้าถึงได้จากที่ใด ๆ 
//       - private : เข้าถึงได้จากภายในคลาสตัวเองเท่านั้น
//   ** member function ส่วนใหญ่จะเป็น public
//   ** data member ควรเป็น private
// 
//------------------------------------
// constructor : 
//------------------------------------
//    - คล้ายฟังก์ชัน แต่ถูกเรียกครั้งเดียวเท่านั้น ตอนสร้าง object
//        - มีหรือไม่มี พารามิเตอร์ก็ได้
//    - ต้องมีชื่อเดียวกับชื่อคลาสเท่านั้น ใช้ชื่ออื่นไม่ได้
//    - ไม่มีประเภทข้อมูลผลลัพธ์ (ไม่มี return type)
//    - ใช้กำหนดค่าเริ่มต้นให้กับ data member
//
//------------------------------------
// member function : แบ่งได้เป็น 2 ประเภท
//------------------------------------
//    (1) accessor : อ่านค่าดาต้าเมมเบอร์ โดยไม่เปลี่ยน
//                   แปลงค่า
//    (2) mutator : มีการเปลี่ยนแปลงค่าดาต้าเมมเบอร์
//                  อาจจะอ่านหรือไม่อ่านดาต้าเมมเบอร์ก็ได้
//
//     *** หากฟังก์ชันเป็นแบบ accessor เราจะเติมคีย์เวิร์ด const
//         ต่อท้ายการประกาศฟังก์ชัน
//      
// --------------------------
//     Naming Convention
// --------------------------
//   (1) ชื่อคลาส : ใช้แบบหลังอูฐ (camel case)
//         - คำภาษาอังกฤษต่อกัน โดยไม่มี _ และตัวอักษรแรกของทุกคำ
//           จะเป็นตัวใหญ่ ตัวอื่น ๆ จะเป็นตัวเล็ก
//         - เช่น CamelCase, MyRectangle, CreditCard
//   (2) ชื่อตัวแปรต่าง ๆ : ใช้แบบงูเลื้อย (snake case)
//         - ตัวแปร เช่น ดาต้าเมมเบอร์ พารามิเตอร์ ชื่ออ๊อบเจ็กต์ ตัวแปรโลคอล
//         - คำภาษาอังกฤษต่อกัน โดยมี _ เชื่อมแต่ละคำ
//           และตัวอักษรทุกตัวเป็นตัวเล็ก เข่น account_name
//   (3) ชื่อฟังก์ชัน : ใช้แบบหลังอูฐ (camel case) 
//         - เหมือนชื่อคลาส ในบางครั้งอาจให้ตัวอักษรแรกสุดเป็นตัวเล็ก 
//           แต่ให้เลือกอย่างใดอย่างหนึ่ง เช่น
//           changeSize, ChangeSize
// (ดู Google: https://google.github.io/styleguide/cppguide.html)
// --------------------------
//
class Rectangle { // user-defined type
private:
	int width;  // int is a primitive type
	int length;

public:
	// constructor
	Rectangle(int w, int l) {
		width = w;
		length = l;
	}

	// accessor function : not modify data in object
	int Area() const {
		return width * length;
	}

	// accessor function : not modify data in object
	int Perimeter() const {
		return 2 * (width + length);
	}

	// mutator function : modify data in object
	void ChangeSize(int d) {
		width += d;
		length += d;
	}

	//-------------------------------------
	//  getter / setter
	//-------------------------------------
	//   - getter เป็นฟังก์ชันพื้นฐาน ใช้ในการคืนค่า data member
	//   - setter เป็นฟังก์ชันพื้นฐาน ใช้ในการ กำหนดค่า data member
	//-------------------------------------
	// accessor
	int GetWidth() const {
		return width;
	}

	// accessor
	int GetLength() const {
		return length;
	}

	// mutator
	void SetWidth(int w) {
		if (w > 0) {
			width = w;
		}
	}

	// mutator
	void SetLength(int l) {
		if (l > 0) {
			length = l;
		}
	}

	//--------------------------------------------
	//    ToString() function
	//--------------------------------------------
	// เราไม่ควรมี cin และ cout ในคลาสที่เราสร้างขึ้นมา
	// หากต้องการพิมพ์ข้อมูล data member ให้สร้าง member function
	// เช่น ToString() เพื่อคืนค่าเป็น string
	// แล้วค่อยใช้ cout ใน main()
	string ToString() const {
		string s = to_string(width) + ", " 
				 + to_string(length);
		return s;
	}
};

int main() {

	//--------------------------------------------
	//  Object
	//--------------------------------------------
	//     เป็นข้อมูลที่ถูกผลิตจาก class
	//        - coke is an object of class Product
	//                 coke   เป็น    Product
	//
	//        - เฌอปราง is an object of class Singer
	//                 เฌอปราง   เป็น    Singer
	//
	//               "object name" เป็น "class name"
	//-------------------------------------------- 
	// ในโค้ดนี้ เราสร้างอ๊อบเจ็กต์ของคลาส Rectangle 
	// มาสองอัน คือ r1 และ r2
	//    - r1 is an object of class Rectangle
	//    - r1 is an instance of class Rectangle
	// "object" is a "class"
	//
	// we create an object r1 of class Rectangle
	// we instantiate an object r1 of class Rectangle
	Rectangle r1(2, 2), r2(5,8);

	cout << "-- r1: " << r1.ToString() << endl;
	cout << "Area1: " << r1.Area() << endl;
	cout << "Perimeter1: " << r1.Perimeter() << endl;

	cout << "-- r2: " << r2.ToString() << endl;
	cout << "Area2: " << r2.Area() << endl;
	cout << "Perimeter2: " << r2.Perimeter() << endl;

	// r1 is an implicit parameter
	// size is an explicit parameter
	r1.ChangeSize(1);
	cout << "r1: " << r1.ToString() << endl;

	r1.SetLength(-9);
	cout << "r1: " << r1.ToString() << endl;	
}















