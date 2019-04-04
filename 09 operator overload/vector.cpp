#include <iostream>
#include <cmath>
#include "point.h"
using namespace std;

// refactor : การปรับโค้ด โดยที่การทำงานยังคงเดิม
//            แต่โครงสร้างของโค้ดเปลี่ยนไป ซึ่งควรจะเป็นโครงสร้างที่ดีขึ้น

class Vector {
public:
	Vector() { 
	}
	Vector(Point &s, Point &e) : start_(s), end_(e) {
	}

	Vector &operator+(Vector &v2) const {
		Vector *v3 = new Vector();
		v3->start_ = start_ + v2.start_;  // delegation ส่งมอบงานให้ 
		v3->end_ = end_ + v2.end_;        // คลาส Point ทำให้
		return *v3;
	}
	void Offset(int dx, int dy) {
		start_.Offset(dx, dy);
		end_.Offset(dx, dy);
	}

	string ToString() const {
		// (x1,y1) ---> (x2,y2)
		string s = start_.ToString() + " ---> " + end_.ToString();
		return s; 
	}

private:
	// vector ประกอบด้วย (มี) จุด 2 จุด
	Point start_; // int start_x_, start_y_;
	Point end_;   // int end_x_, end_y_;
};

int main() {
	Point p1(1,1), p2(2,2);
	Vector v1(p1, p2);

	Point p3(3,3), p4(4,4);
	Vector v2(p3, p4);

	cout << "v1: " << v1.ToString() << endl;
	cout << "v2: " << v2.ToString() << endl;

	// v1.Offset(10,10);
	// cout << "after offset v1: " << v1.ToString() << endl;

	Vector v3 = v1 + v2;
	cout << "v3: " << v3.ToString() << endl;
}

