#include <string>
// ----- ไม่ควรใช้ "using namespace" ในไฟล์ .h

//   ------------------
//    interface of class Vector
//      - define class's interface with member function prototypes
//      - separate implementation from interface
//   ------------------

class Vector {
public:
	Vector();
	Vector(int ex, int ey);
	Vector(int sx, int sy, int ex, int ey);

	void Offset(int d);
	void Offset(int dx, int dy);
	void Offset(Vector v);
	Vector Add(Vector v2) const;
	double Length() const;
	std::string ToString() const;

private:
	int start_x_, start_y_;
	int end_x_, end_y_;
};
