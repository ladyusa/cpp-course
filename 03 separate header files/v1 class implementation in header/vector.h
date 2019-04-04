#include <iostream>
#include <cmath>

class Vector {
public:
	Vector() {   
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
	std::string ToString() const {
		// (sx,sy) ---> (ex,ey)
		std::string s = "(" + std::to_string(start_x_) + "," + std::to_string(start_y_) + ")"
				 + " ---> "
				 + "(" + std::to_string(end_x_) + "," + std::to_string(end_y_) + ")";
		return s;
	}

private:
	int start_x_, start_y_;
	int end_x_, end_y_;
};
