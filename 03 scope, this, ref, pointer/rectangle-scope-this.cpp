#include <iostream>
using namespace std;
// --------------------------------------------------------
//   scope : ขอบเขตการใช้งาน การคงอยู่ของตัวแปร
// --------------------------------------------------------
//     - global scope: เหมือนในภาษา C
//     - class scope: ขอบเขตแค่ภายในคลาสนั้น ๆ
//     - block/function scope: ขอบเขตแค่ภายในบล็อค {} 
//                             หรือฟังก์ชันนั้น
//
//   โดย variable จะคงอยู่ได้ภายในขอบเขตที่ประกาศตัวแปรนั้นไว้เท่านั้น
//     - class-scope variable :
//          - ตัวแปร data member ที่ประกาศภายใน class block
//          - จะใช้ได้ทั่วทั้งคลาส
//     - block/function scope :
//         - ตัวแปร parameter หรือตัวแปร local ที่ประกาศใน
//           function block 
//         - ใช้ได้แค่ภายในบล็อค {} หรือฟังก์ชันนั้นเท่านั้น
// --------------------------------------------------------

class Rectangle { 

private:
	int width;  
	int length;

public:
	// ------------------------------------------------
	//  เวลาประกาศ parameter หรือ local variable ให้เป็นชื่อ
	//  เดียวกับ data member จะทำให้ constructor หรือ function
	//  ไม่เห็น data member (จะเห็นเป็น parameter หรือ local variable)
	//
	//     - หากต้องการให้ local variable หรือ parameter ชื่อเดียวกับ
	//   data member ควรใช้ "this" pointer ในการระบุ data member
	//
	// -----------------------------------------------
	// "this" pointer พิเศษ
	// -----------------------------------------------
	//    - เป็น pointer ที่ชี้มาที่ object ปัจจุบัน
	//      ที่กำลังทำงานอยู่
	//    - ใช้ "this" ในการเข้าถึง data member / 
	//      member function ของอ๊อบเจ็กต์นี้ได้
	//      ทำให้ระบุได้ชัดเจนว่า ตัวแปรนี้เป็น data member
	//    - ช่วยแยกแยะระหว่าง data member กับ
	//      parameter / local variable (ถ้าชื่อตรงกัน)
	// -----------------------------------------------
	Rectangle(int width, int length) {
		this->width = width;
		this->length = length;
	}
    
	int Area() const {
        // area เป็น local variable
        int area = width * length;
        this->area; // เรียก local var จาก this ไม่ได้
		return area; 
	}

	int Perimeter() const {
		return 2 * (width + length);
	}

	void ChangeSize(int d) {
		width += d;
		length += d;
	}

  void ChangeSize(int dw, int dl) {
		width += dw;
		length += dl;
  }

	int GetWidth() const {
		return width;
	}

	int GetLength() const {
		return length;
	}

	void SetWidth(int width) {
		if (width > 0) {
			this->width = width;
		}
	}

	void SetLength(int length) {
		if (length > 0) {
			this->length = length;
		}
	}
	string ToString() const {
		string s = to_string(width) + ", " 
				 + to_string(length);
		return s;
	}
};

int main() {
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

	r2.ChangeSize(10, 100);
	cout << "r2: " << r2.ToString() << endl;

	r1.SetLength(-9);
	cout << "r1: " << r1.ToString() << endl;	

}
