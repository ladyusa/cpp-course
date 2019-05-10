#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
	int start_x, start_y;
	int end_x, end_y;

public:
	Vector() {
		start_x = 0;
		start_y = 0;
		end_x = 0;
		end_y = 0;
	}
	Vector(int sx, int sy, int ex, int ey) {
		start_x = sx;
		start_y = sy;
		end_x = ex;
		end_y = ey;
	}
	void Offset(int dx, int dy) {
		start_x += dx;
		start_y += dy;
		end_x += dx;
		end_y += dy;
	}
	Vector Add(Vector v2) const {  // v2 is a parameter
		Vector v3;  // v3 is local variable
		v3.start_x = start_x + v2.start_x;
		v3.start_y = start_y + v2.start_y;
		v3.end_x = end_x + v2.end_x;
		v3.end_y = end_y + v2.end_y;
		return v3;
	}
	double Length() const {
		double x_2 = pow((end_x - start_x), 2);
		double y_2 = pow((end_y - start_y), 2);
		double length = sqrt(x_2 + y_2);
		return length;
	}
	string ToString() const {
		// (sx,sy) ---> (ex,ey)
		string s = 
		    "(" + to_string(start_x) + "," + to_string(start_y) + ")"
		         + " ---> " +
		    "(" + to_string(end_x) + "," + to_string(end_y) + ")";
		return s;
	}

};

int main() {

	Vector v(1,1,3,4), v1(2,2,3,3);

	// ------ handle of object v ------
	//  1. object name: v
	//  2. object reference: vRef
	//  3. object pointer: vPtr
	// -------------------------------
	Vector &vRef = v;   // vRef is a reference to object v.
	Vector *vPtr = &v;  // vPtr is a pointer to object v.
	Vector v2 = v;      // copy object v into v2

	cout << "----- Before -----" << endl;
	cout << v.ToString() << endl;
	cout << vPtr->ToString() << endl;
	cout << vRef.ToString() << endl;
	cout << v2.ToString() << endl;

	vPtr->Offset(10,10);

	cout << "----- After v.Offset(10,10) -----" << endl;
	cout << v.ToString() << endl;
	cout << vPtr->ToString() << endl;
	cout << vRef.ToString() << endl;
	cout << v2.ToString() << endl;

	//---------------------------------------------------
	//  หากต้องการใช้ pointer ของ object เราสามารถเขียนได้ 2 แบบ
	//---------------------------------------------------
	cout << "----- Dynamic memory management -----" << endl;
	//---------------------------------------------------
	//  1. ประกาศออปเจ็คตามปกติ แล้วค่อยประกาศ pointer
	//---------------------------------------------------
	Vector v3(1,1,5,5);
	Vector *v3Ptr = &v3;
	cout << v3Ptr->ToString() << endl;

	//---------------------------------------------------
	//           2. Dynamic Memory Management
	//
	//     ให้ C++ จองพื้นที่หน่วยความจำใน Heap สำหรับเก็บออปเจ็ค
	//     โดยใช้คำสั่ง new
	//  *** เมื่อใช้เสร็จ จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
	//---------------------------------------------------

	Vector *myV = new Vector(5,5,6,6);
	cout << myV->ToString() << endl;

	delete myV;
}



