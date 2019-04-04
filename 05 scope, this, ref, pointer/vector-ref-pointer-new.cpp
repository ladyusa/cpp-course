#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
	//   constructor using member-initializer list
	//     
	Vector() 
		: start_x_(0), start_y_(0), end_x_(0), end_y_(0) {
	}
	Vector(int sx, int sy, int ex, int ey) 
		: start_x_(sx), start_y_(sy), end_x_(ex), end_y_(ey) {	
	}
	void Offset(int dx, int dy) {
		start_x_ += dx;
		start_y_ += dy;
		end_x_ += dx;
		end_y_ += dy;
	}
	Vector Add(Vector v2) const {  // v2 is a parameter
		Vector v3;  // v3 is local variable
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
	void Print() const {
		// (sx,sy) ---> (ex,ey)
		cout << "(" << start_x_ << "," << start_y_<< ")";
		cout << " ---> ";
		cout << "(" << end_x_ << "," << end_y_<< ")" << endl;;
	}

private:
	int start_x_, start_y_;
	int end_x_, end_y_;
};

int main() {

	Vector v(1,1,3,4), v1(2,2,3,3);

	// ------ handle of object v ------
	//  1. object name: v
	//  2. object referenct: vRef
	//  3. object pointer: vPtr
	// -------------------------------
	Vector &vRef = v;   // vRef is a reference to object v.
	Vector *vPtr = &v;  // vPtr is a pointer to object v.
	Vector v2 = v;      // copy object v into v2

	cout << "----- Before -----" << endl;
	v.Print();
	vPtr->Print();
	vRef.Print();
	v2.Print();

	vPtr->Offset(10,10);

	cout << "----- After v.Offset(10,10) -----" << endl;
	v.Print();
	vPtr->Print();
	vRef.Print();
	v2.Print();

	//---------------------------------------------------
	//  หากต้องการใช้ pointer ของ object เราสามารถเขียนได้ 2 แบบ
	//---------------------------------------------------
	cout << "----- Dynamic memory management -----" << endl;
	//---------------------------------------------------
	//  1. ประกาศออปเจ็คตามปกติ แล้วค่อยประกาศ pointer
	//---------------------------------------------------
	Vector v3(1,1,5,5);
	Vector *v3Ptr = &v3;
	v3Ptr->Print();

	//---------------------------------------------------
	//           2. Dynamic Memory Management
	//
	//     ให้ C++ จองพื้นที่หน่วยความจำใน Heap สำหรับเก็บออปเจ็ค
	//     โดยใช้คำสั่ง new
	//  *** เมื่อใช้เสร็จ จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
	//---------------------------------------------------

	Vector *myV = new Vector(5,5,6,6);
	myV->Print();

	delete myV;
}



