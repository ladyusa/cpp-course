#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int w, int l) {
        width = w;
        length = l;
    }

    int Area() const {
        return length * width;
    }

    int Perimeter() const {
        return 2 * (length + width);
    }

    int GetWidth() const {
		return width;
	}

	int GetLength() const {
		return length;
	}

	void SetWidth(int w) {
		if (w > 0) {
			width = w;
		}
	}

	void SetLength(int l) {
		if (l > 0) {
			length = l;
		}
	}
    string ToString() const {
		string s = to_string(width) + ", " 
				 + to_string(length);
		return s;
	}
};

int main() {

    // -------------------------------------
    //    'new' keyword ในการสร้างอ๊อบเจ็กต์
    //     และ pointer ชี้ไปที่อ๊อบเจ็กต์
    // -------------------------------------
    //  - ประกาศตัวแปร pointer ชี้ไปที่อ๊อบเจ็กต์ของคลาส Rectangle
    //  - สร้าง object ด้วยคีย์เวิร์ด new
    //  - Dynamic Memory Management
    //      - ให้ C++ จองพื้นที่หน่วยความจำสำหรับเก็บออปเจ็ค
    //      - โดยใช้คำสั่ง new
    //  *** เมื่อใช้เสร็จ จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
    //---------------------------------------------------

    Rectangle *rPtr = new Rectangle(5,5);
    cout << "------ 'new' keyword -----" << endl;
    cout << "rPtr: " << rPtr->ToString() << endl;

    // สามารถเปลี่ยนให้ pointer ชี้ไปที่อ๊อบเจ็กต์ใหม่ได้
    rPtr = new Rectangle(10,10);
    cout << "rPtr: " << rPtr->ToString() << endl;

    Rectangle r1(1,1), r2(2,2);

    // สามารถให้ pointer ชี้ไปที่อ๊อบเจ็กต์ที่มีอยู่แล้วได้
    rPtr = &r1;
    Rectangle *rPtr2 = &r2;
    cout << "------ pointer to object -----" << endl;
    cout << "rPtr: " << rPtr->ToString() << endl;
    cout << "rPtr2: " << rPtr2->ToString() << endl;

    // ดังนั้น ตอนนี้ r1 กับ rPtr ใช้อ๊อบเจ็กต์ร่วมกันอยู่
    // ถ้าเปลี่ยนค่าในอันใดอันหนึ่ง อีกอันจะเปลี่ยนตามไปด้วย
    r1.SetWidth(10);
    cout << "r1: " << r1.ToString() << endl;
    cout << "rPtr: " << rPtr->ToString() << endl;

    // -------------------------------------
    //    Reference to object
    // -------------------------------------
    // สร้าง reference ของอ๊อบเจ็กต์ r2
    // rRef เป็นเหมือนชื่ออีกชื่อหนึ่งของอ๊อบเจ็กต์ r2 
    // ดังนั้น rRef และ r2 เป็นชื่อของอ๊อบเจ็กต์เดียวกัน
    // ถ้าเปลี่ยนค่าในอันใดอันหนึ่ง อีกอันจะเปลี่ยนตามไปด้วย
    // โดย rRef ไม่ใช่ pointer
    // -------------------------------------
    Rectangle &rRef = r2;
    r2.SetWidth(10);
    cout << "------ reference to object -----" << endl;
    cout << "r2: " << r2.ToString() << endl;
    cout << "rRef: " << rRef.ToString() << endl;

    // -------------------------------------
    //    Copy to object
    // -------------------------------------
    // หากเรากำหนดค่า ดังโค้ดด้านล่าง จะเป็นการก๊อบปี้
    // อ๊อบเจ็กต์ r2 มาใส่ r3
    // ดังนั้น r2 กับ r3 เป็นคนละอ๊อบเจ็กต์กัน
    // ถ้าเปลี่ยนค่าในอันใดอันหนึ่ง อีกอันจะไม่เปลี่ยนตามไปด้วย
    // -------------------------------------
    Rectangle r3 = r2;
    r2.SetWidth(80);
    cout << "------ copy of object -----" << endl;
    cout << "r2: " << r2.ToString() << endl;
    cout << "r3: " << r3.ToString() << endl;

    // ------------------------------------
    //   delete object สำหรับ pointer
    // ------------------------------------
    // *** เมื่อใช้ object เสร็จ 
    //      จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
    // ------------------------------------
    Rectangle *morePtr = new Rectangle(5,5);
    delete morePtr;

}