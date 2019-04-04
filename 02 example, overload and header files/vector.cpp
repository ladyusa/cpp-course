#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
	// ------------------------------------
	// constructor overload
	//   - multiple constructors that have 
	//     different parameters
	//       - โดยอาจมี type ต่างกัน
	//       - หรือจำนวน parameters ที่ต่างกัน
	// ------------------------------------
	Vector() {   // default constructor - constructor with no arguments
		start_x_ = 0;
		start_y_ = 0;
		end_x_ = 0;
		end_y_ = 0;
	}
	Vector(int ex, int ey) {
		start_x_ = 0;
		start_y_ = 0;
		end_x_ = ex;
		end_y_ = ey;
	}
	Vector(int sx, int sy, int ex, int ey) {
		start_x_ = sx;
		start_y_ = sy;
		end_x_ = ex;
		end_y_ = ey;
	}
	// ------------------------------------
	// function overload
	//   - multiple functions with the same name
	//     but have different parameters
	//       - โดยอาจมี type ต่างกัน
	//       - หรือจำนวน parameters ที่ต่างกัน
	// ------------------------------------
	void Offset(int d) {
		start_x_ += d;
		start_y_ += d;
		end_x_ += d;
		end_y_ += d;
	}
	void Offset(int dx, int dy) {
		start_x_ += dx;
		start_y_ += dy;
		end_x_ += dx;
		end_y_ += dy;
	}
	void Offset(Vector v) {
		start_x_ += v.start_x_;
		start_y_ += v.start_y_;
		end_x_ += v.end_x_;
		end_y_ += v.end_y_;
	}

	Vector Add(Vector v2) const {  // ฟังก์ชันคืนค่าเป็น object ได้
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

	v1.Offset(10);
	cout << "v1.Offset(10): ";
	cout << v1.ToString() << endl;

	v2.Offset(10, 100);
	cout << "v2.Offset(10, 100): ";
	cout << v2.ToString() << endl;
}



