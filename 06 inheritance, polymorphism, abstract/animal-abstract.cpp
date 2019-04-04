#include <iostream>
using namespace std;

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
    // pure virtual
    //   -  ไม่ต้องมี implementation เมื่อประกาศให้เป็น pure virtual function
    //   - class ที่มี pure virtual member function จะเรียกว่า
    //     abstract class
    //   - เราจะไม่สามารถสร้าง object ของ abstract class ได้
    //       abstract class คลาสที่จับต้องไม่ได้ (จึงสร้าง object ไม่ได้) 
    //          ตรงข้ามกับ
    //       concrete class คลาสที่จับต้องได้ (จึงสร้าง object ได้) 
	virtual void MakeNoise() = 0;

protected:
	string emotion_;
private:
	string name_;
	int happiness_;
};

class Dog : public Animal {
public:
	Dog(string n)
		: Animal(n) {}

	// redefine
	void play(int h) {
		Animal::play(h);  // reuse โค้ดของ base class
		cout << " ---- wagging its tail !!" << endl;
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

void MeetOwner(Animal &animal) {
	animal.play(1);
	animal.MakeNoise();
}
int main() {
	Dog doggie("Doggie");
	Cat kittie("Kittie");
	//Animal ani("Ani");  // เราไม่สามารถสร้าง object ของคลาส Animal ได้
	                    // เนื่องจาก Animal มี pure virtual function อยู่
						//   - เราเรียกคลาสที่มี pure virtual function อยู่ข้างใน
						//     ว่า​ "abstract class"
						// abstract class ตรงข้ามกับ concrete class
						// 
						// abstract class 
						//   - ไม่สามารถสร้าง object ของ abstract class ได้
						//   - มี pure virtual function อยู่ข้างใน
						// concrete class
						//   - สามารถสร้าง object ของ concrete class ได้
						//   - ต้องไม่มี pure virtual function อยู่ข้างใน
						//   - ถ้า base class มี pure virtual function แล้ว
						//     derived class จะเป็น concrete class ได้ก็ต่อเมื่อ
						//     derived class ได้ implement โค้ดของ
						//     pure virtual function ให้ครบถ้วน

	// ถึงแม้ว่า เราจะสร้าง object ของ abstract class ไม่ได้
	// แต่เราสามารถประกาศให้ pointer มีชนิดเป็น abstract class ได้
	Animal *aniPtr = new Dog("Kaidao");
	aniPtr->MakeNoise();

	aniPtr = &doggie;
	aniPtr->MakeNoise();

	aniPtr = &kittie;
	aniPtr->MakeNoise();
	//
	// ------------------ Polymorphism -----------------------
	// บรรทัด aniPtr->MakeNoise(); มีการเขียนโค้ดที่เหมือนกัน 
	// แต่ทำงานไม่เหมือนกัน
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
	// aniPtr = &doggie;
	// Animal *ani1 = new Dog("Toob");
	//Dog *dog1 = new Animal("ani ani"); ผิด เพราะ "superclass" is not a "subclass"

	Dog **dogs = new Dog*[3];
	Animal **animals = new Animal*[3];

	animals[0] = new Dog("Kraprow");
	animals[1] = new Dog("Kaidao");
	animals[2] = new Cat("Kittie");

	for (int i = 0; i < 3; i++) {
		animals[i]->MakeNoise();  // polymorphism (virtual func)
		animals[i]->play(1);      // no polymorphism (non-virtual func)
	}
}








