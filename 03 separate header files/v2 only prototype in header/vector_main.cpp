#include <iostream>
#include "vector.h"
using namespace std;

// ---------------------------------
//  we must compile all .cpp file
// ---------------------------------

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



