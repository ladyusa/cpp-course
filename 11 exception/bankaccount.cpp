#include <iostream>
using namespace std;

class BankAccount {
public:
	BankAccount(string n, double m = 0) 
		: name_(n), money_(m) {
	}
	void Deposit(double m) {
		money_ += m;
	}
	void Withdraw(double m) {
		if (m > 0 && m <= money_) {
			money_ -= m;
		} else {
			//---------------- Exception ------------------
			//  Exception เป็นคลาสพิเศษที่ใช้แจ้งและจัดการ error
			//  
			//  กลไกที่ช่วยในการแจ้งและจัดการ error มี 2 ขั้นตอน
			//    1. throw: การแจ้ง error ให้ผู้เกี่ยวข้องรับทราบ
			//              โดยการ throw exception
			//    2. catch: การจัดการ error โดยผู้เกี่ยวข้อง 
			//              (โค้ดที่เรียก Withdraw()) ด้วยการ
			//              catch exception
			//---------------------------------------------

			// ขั้นตอนที่ 1 เราแจ้ง error ผ่านการ throw exception
			//          โดย throw ไปให้โค้ดที่เรียกฟังก์ชัน Withdraw
			throw invalid_argument("amount should be positive and less than money");
		}
	}
	double GetMoney() const {
		return money_;
	}
	string GetName() const {
		return name_;
	}

private:
	double money_;
	string name_;
};

int main() {
	BankAccount kwanAct("Kwan", 100);

	kwanAct.Deposit(300);
	cout << "Kwan's money = " << kwanAct.GetMoney() << endl;

	// ขั้นตอนที่ 2 
	//  - เราจัดการ error โดยการ catch exception
	//    และเขียนโค้ดการจัดการที่เฉพาะและตรงกับการทำงานของเราได้
	//  - การ catch ทำให้โปรแกรมไม่หยุดทำงานหลังการเกิด exception
	
	try {
		// โค้ดที่อาจเกิด exception
		kwanAct.Withdraw(100000);
		cout << "Kwan has withdraw money." << endl;
	}
	catch (invalid_argument &ex) {
		// ขั้นตอนที่ 2 การ catch exception
		//   - ใส่โค้ดที่จะช่วยจัดการ error เช่น การแจ้ง user 
		//     ด้วยข้อความจาก exception object
		cout << "Error: " << ex.what() << endl;
 	}
	cout << "Kwan's money = " << kwanAct.GetMoney() << endl;

}



