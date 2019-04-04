#include <iostream>
using namespace std;

// --------------------------------------
//      IS-A relationship (การเป็น)
// --------------------------------------
//  1. "object" is a "class" 
//     - เช่น Kaset is a university
//  2. "derived class" is a "base class"
//     - เช่น Dog is a(n) animal

// --------------------------------------
//      HAS-A relationship (การมี)
//        เช่น การมีตัวแปรอยู่ในคลาส
// --------------------------------------
//  3. "class A" has a/many "data member"
//     - student has a name
//  4. "class A" has a/many "class B"
//     - มหาวิทยาลัย has คณะ
//
// หากเราพบว่า คลาสสองคลาสมีความสัมพันธ์แบบ IS-A ที่เป็น
//     "derived class" is a "base class"
// เราสามารถนำ inheritance มาช่วยในการเขียนโปรแกรมได้
//   - โดยจะมีประโยชน์ทำให้โค้ดไม่ซ้ำซ้อนกัน
//
// การสืบทอดจะทำให้ derived class 
//    - ได้รับ member functions และ data members ทั้งหมดจาก base class
//    - แต่จะไม่ได้รับ constructor ของ base class มาด้วย
// 
// base class (superclass, parent class)
//    - มีความทั่วไป หรือ general หรือ generalization
//
// derived class (subclass, child class, คลาสลูก)
//   - มีความเฉพาะเจาะจง (specific/specialized)
// 
// การใช้ศัพท์
//   - derived class สืบทอดมาจาก base class
//   - subclass สืบทอดมาจาก superclass
//
// derived class สามารถ
//   - ได้รับ member function และ data member จาก base class
//   - เพิ่มตัวแปรที่เฉพาะสำหรับ derived class นั้น ๆ ได้
//   - เพิ่ม member function ที่เฉพาะสำหรับ derived class นั้น ๆ ได้
//   - redefine member function ของ base class ได้ (ไม่ใช้ virtual)
//        - เพื่อให้ member function ตรงกับการทำงานของ derived class มากขึ้น
//   - override member function ของ base class ได้ (ใช้ virtual)
//
// UML class diagram
//   - เป็นแผนภาพที่ช่วยให้เราเห็น โครงสร้างของคลาส (class hierarchy) ได้ดีขึ้น
//   - เครื่องมือช่วยวาด class diagram เช่น UMLet, StarUML

class Animal {
public:
	Animal(string n)
		: name_(n), happiness_(0) {}

	string GetName() const {
		return name_;
	}
	int GetHappiness() const {
		return happiness_;
	}
	void play(int h) {
		happiness_ += h;
		cout << name_ << " is playing ^____o !" << endl;
	}
	virtual void MakeNoise() {
		cout << name_ << " is making noise !" << endl;
	}
protected:
	string emotion_;
private:
	string name_;
	int happiness_;
};

// derived class หรือ subclass ของคลาส Animal
// หรือ child class หรือ คลาสลูก
//   - derived class สืบทอดมาจาก base class
//   - subclass สืบทอดมาจาก superclass
//
// การสืบทอดจะทำให้ derived class ได้รับ member functions 
// และ data members ทั้งหมดจาก base class
// แต่จะไม่ได้รับ constructor ของ base class มาด้วย
//
class Dog : public Animal {
public:
	Dog(string n)
		: Animal(n) {}

	// redefine
	void play(int h) {
		Animal::play(h);  // reuse โค้ดของ base class
		cout << " ---- with balls !!" << endl;
	}
	// override 
	virtual void MakeNoise() {
		cout << GetName() << " is woofing !" << endl;
	}
};

class Cat : public Animal {
public:
	Cat(string n)
		: Animal(n) {}

	// redefine
	void play(int h) {
		Animal::play(h);
		cout << " ---- with mice !!" << endl;
	}
	// override
	void MakeNoise() {
		cout << GetName() << " is meowing !" << endl;
	}
	void BuildFurBall() {
		this->emotion_ = "fluffy";
		cout << GetName() << " is " << emotion_ << endl;
	}
};

void MeetOwner(Animal animal) {
	animal.play(1);
	animal.MakeNoise();
}
int main() {
	Dog doggie("Doggie");
	Cat kittie("Kittie");
	Animal ani("Ani");

	MeetOwner(ani);
	MeetOwner(doggie);
	MeetOwner(kittie);

	Animal *aniPtr = &ani;
	aniPtr->MakeNoise();

	// คำถาม คือ C++ จะเลือก MakeNoise() เวอร์ชันใดมาใช้ ระหว่าง
	//   - MakeNoise() ของ Animal ซึ่งเป็น type ของ pointer aniPtr
	//   - MakeNoise() ของ Dog/Cat ซึ่งเป็น type ของ object ที่ aniPtr ชี้อยู่
	//
	// หาก MakeNoise() ของ Animal ไม่ใช่้ virtual
	// คำตอบ คือ C++ จะเลือก MakeNoise() ของ Animal
	//   - เนื่องจาก C++ จะผูกตัวแปรกับ type ในช่วง compile ทำให้ C++ สามารถระบุได้
	//     ทันทีในช่วง compile ว่า จะเลือก member function ของคลาสใดใน class hierarchy มาใช้
	//   - เราจะเรียกการผูกตัวแปรในช่วง compile ว่า "static binding"
	//
	// หาก MakeNoise() ของ Animal ใช่้ virtual
	// คำตอบ คือ C++ จะเลือก MakeNoise() ของ Dog/Cat
	//   - เนื่องจาก C++ จะผูกตัวแปรกับ type ในช่วง execution ทำให้ C++ ไม่สามารถระบุได้
	//     ทันทีในช่วง compile ว่า จะเลือก member function ของคลาสใดใน class hierarchy มาใช้
	//   - ซึ่ง C++ จะเลือกใช้ member function จาก type ของออปเจ็คจริงที่ pointer ชี้อยู่
	//   - เราจะเรียกการผูกตัวแปรในช่วง execution ว่า "dynamic binding" หรือ "late binding"
	//
	aniPtr = &doggie;
	aniPtr->MakeNoise();

	aniPtr = &kittie;
	aniPtr->MakeNoise();
	//
	// ------------------ Polymorphism -----------------------
	// บรรทัดที่ 148, 151 มีการเขียนโค้ดที่เหมือนกัน แต่ทำงานไม่เหมือนกัน
	// เนื่องจากไปเรียก MakeNoise() คนละเวอร์ชันกัน
	//    -----> เราเรียกการทำงานในลักษณะนี้ว่า "Polymorphism"
	//           Poly = หลาย
	//           morph = รูปร่าง
	//             - โค้ดเหมือนกันแต่ทำงานต่างกัน
	//    -----> polymorphism มีประโยชน์ ช่วยให้เขียนโค้ดรอบเดียว แต่ใช้ได้กับคลาสหลายคลาส
	//           ที่อยู่ใน class hierarchy เดียวกัน


	// เราสามารถสร้าง pointer ที่มีชนิดเป็น superclass ให้ชี้ไปที่ object ของ subclass ได้
	//   superclass *var = subclassObject;
	//   "subclass" is a "superclass"
	//     - เช่น Dog is an animal
	aniPtr = &doggie;
	Animal *ani1 = new Dog("Toob");
	//Dog *dog1 = new Animal("ani ani"); ผิด เพราะ "superclass" is not a "subclass"
}








