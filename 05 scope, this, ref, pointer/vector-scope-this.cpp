#include <iostream>
#include <cmath>
using namespace std;

// -------------------------------------------
//  scope: ขอบเขตการใช้งาน การคงอยู่
//     - class scope ขอบเขตภายในคลาส
//     - block scope ขอบเขตภายใน block {}
//
//  variable คงอยู่ได้ตาม scope ที่เราประกาศตัวแปรนั้น ๆ ไว้
//     - class-scope variable เช่น data member
//         - can be accessed throughout class
//         - เข้าถึงได้จากทุกที่ในคลาส
//     - block-scope variable เช่น local variable, parameter
//         - ใช้ได้แค่ใน block ที่ประกาศเท่านั้น
// -------------------------------------------

class Vector {
public:
	Vector() {  
		start_x_ = 0;
		start_y_ = 0;
		end_x_ = 0;
		end_y_ = 0;
	}
	// -------------------------------------------
	//  เวลาประกาศ parameter หรือ local variable ให้เป็นชื่อ
	//  เดียวกับ data member จะทำให้ constructor หรือ function
	//  ไม่เห็น data member (จะเห็นเป็น parameter หรือ local variable)
	//
	//     - หากต้องการให้ local variable หรือ parameter ชื่อเดียวกับ
	//   data member ควรใช้ "this" pointer ในการระบุ data member
	// -------------------------------------------
	//  "this" pointer
	//   - pointer ที่ชี้มาที่ object ปัจจุบัน
	//   - เราสามารถใช้ this ในการเข้าถึง attribute
	//     ทำให้ระบุได้ชัดเจนว่า ตัวแปรนี้เป็น attribute
	//   - เราสามารถใช้ "this" แยกระหว่าง attribute กับ
	//     local variable หรือ parameter
	// -------------------------------------------

	Vector(int start_x_, int start_y_, int end_x_, int end_y_) {
		this->start_x_ = start_x_;
		this->start_y_ = start_y_;
		this->end_x_ = end_x_;
		this->end_y_ = end_y_;
	}
	void Offset(int dx, int dy) {
		start_x_ += dx;
		start_y_ += dy;
		end_x_ += dx;
		end_y_ += dy;
	}

	Vector Add(Vector v2) const {  
		Vector v3;
		v3.start_x_ = start_x_ + v2.start_x_;
		v3.start_y_ = start_y_ + v2.start_y_;
		v3.end_x_ = end_x_ + v2.end_x_;
		v3.end_y_ = end_y_ + v2.end_y_;
		return v3;
	}

	double Length() const {
		double x_2 = pow((end_x_ - start_x_), 2);
		double y_2 = pow((end_y_ - start_y_), 2);
		double length = sqrt(x_2 + y_2);
		return length;
	}
	string ToString() const {
		// (sx,sy) ---> (ex,ey)
		string s = "(" + to_string(start_x_) + "," + to_string(start_y_) + ")"
				 + " ---> "
				 + "(" + to_string(end_x_) + "," + to_string(end_y_) + ")";
		return s;
	}

private:
	int start_x_, start_y_;
	int end_x_, end_y_;
};

int main() {

	// v0    = (0,0) ---> (0,0)
	// v1    = (0,0) ---> (3,4)
	// v2    = (1,1) ---> (2,2)
	// v1+v2 = (1,1) ---> (5,6)

	Vector v0;
	Vector v1(0,0,3,4), v2(1,1,2,2);

	Vector v3 = v1.Add(v2);

	cout << "v1: " << v1.ToString() << endl;
	cout << "v2: " << v2.ToString() << endl;
	cout << "v2: " << v3.ToString() << endl;

	cout << "v1 length: " << v1.Length() << endl;
	cout << "v2 length: " << v2.Length() << endl;

	v2.Offset(10, 100);
	cout << "v2.Offset(10, 100): ";
	cout << v2.ToString() << endl;
}



