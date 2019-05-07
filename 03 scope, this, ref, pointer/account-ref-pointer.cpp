#include <iostream>
using namespace std;

class BankAccount {
private:
	string name;
    int balance;
public:
    BankAccount(string n) {
        name = n;
        balance = 0;
    }
    BankAccount(string n, int b) {
        name = n;
        balance = b;
    }
    void Deposit(int amount) {
        balance = balance + amount;
    }
    void Withdraw(int amount) {
        if (amount > balance) {
            cout << "error: amount can't be more than balance" << endl;
        } else {
            balance = balance - amount;
        }
    }
    int GetBalance() const {
        return balance;
    }
    string GetName() const {
        return name;
    }
    void SetName(string n) {
        name = n;
    }
    string ToString() const {
        string s = name + " has " +
                   to_string(balance);
        return s;
    }
};

int main() {

    // fah เป็น pointer ชี้ไปที่อ๊อบเจ็กต์ของคลาส BankAccount
    BankAccount *fah = new BankAccount("Fah");
    fah->Deposit(800);

    cout << fah->ToString() << endl;

	// ------ handle of object v ------
	//  1. object name: act1
	//  2. object pointer: myPtr
	//  3. object referenct: myRef
	// -------------------------------
    BankAccount act1("Kwan"), act2("Kittiya", 500);
    act1.Deposit(1000);
    act2.Deposit(5000);

    BankAccount *myPt = &act1; // myPt is a pointer to object
    BankAccount &myRef = act1; // myRef is a reference to object
    BankAccount myCopy = act1; // myCopy is a copy of object

    cout << "----- Before Withdraw -----" << endl;
    cout << "act1: " << act1.ToString() << endl;
    cout << "myPt: " << myPt->ToString() << endl;
    cout << "myRef: " << myRef.ToString() << endl;
    cout << "myCopy: " << myCopy.ToString() << endl;

    myPt->Withdraw(100);

    cout << "----- After Withdraw -----" << endl;
    cout << "act1: " << act1.ToString() << endl;
    cout << "myPt: " << myPt->ToString() << endl;
    cout << "myRef: " << myRef.ToString() << endl;
    cout << "myCopy: " << myCopy.ToString() << endl;

	//---------------------------------------------------
	//  หากต้องการใช้ pointer ของ object เราสามารถเขียนได้ 2 แบบ
	//---------------------------------------------------
	cout << "----- Dynamic memory management -----" << endl;
	//---------------------------------------------------
	//  1. ประกาศออปเจ็คตามปกติ แล้วค่อยประกาศ pointer
	//---------------------------------------------------
	BankAccount act3("Kwan", 50);
	BankAccount *act3Ptr = &act3;
	cout << act3Ptr->ToString() << endl;

	//---------------------------------------------------
	//           2. Dynamic Memory Management
	//
	//     ให้ C++ จองพื้นที่หน่วยความจำสำหรับเก็บออปเจ็ค
	//     โดยใช้คำสั่ง new
	//  *** เมื่อใช้เสร็จ จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
	//---------------------------------------------------

	BankAccount *act4Ptr = new BankAccount("Jenny", 200);
	cout << act4Ptr->ToString() << endl;

	delete act4Ptr;

}