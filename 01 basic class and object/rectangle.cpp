#include <iostream>
using namespace std;

class Rectangle { // user-defined type
public:
	int width;  // int is a primitive type
	int length;

	int area() {
		return width * length;
	}

	int perimeter() {
		return 2 * (width + length);
	}

	void change_size(int d) {
		width += d;
		length += d;
	}
};

int main() {

	Rectangle r;
	cout << "Enter width: ";
	cin >> r.width;

	cout << "Enter length: ";
	cin >> r.length;

	cout << "Area: " << r.area() << endl;
	cout << "Perimeter: " << r.perimeter() << endl;

	r.change_size(1);
	cout << r.width << ", " << r.length << endl;
}















