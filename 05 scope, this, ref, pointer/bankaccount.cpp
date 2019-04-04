#include <iostream>
using namespace std;

class BankAccount {
public:
    // constructor overload
    BankAccount(int i, double b) 
        : id_(i), balance_(b) {    // member-initializer list
    }
    BankAccount(int i) 
        : id_(i), balance_(0) {     // member-initializer list  
    }
    // getter/accessor functions
    int GetId() const { return id_; }
    double GetBalance() const { return balance_; }

    // scope ของตัวแปร : ขอบเขตการคงอยู่/ใช้งานของตัวแปร
    //    - ตัวแปรถูกประกาศไว้ใน block {} ไหน ก็จะใช้ได้แค่ใน block นั้น ๆ

    // ตัวแปรมีหลายประเภท
    //   1. data member
    //   2. parameter
    //   3. local variable

    // ถ้าเราประกาศชื่อตัวแปร parameter/local variable ซ้ำกับชื่อ data member
    // C++ จะไม่เห็นตัวแปร data member (เพราะ C++ จะเห็นชื่อนั้นเป็น
    // parameter/local variable)
    //
    // this pointer เป็น pointer ที่ชี้ไปที่ object ปัจจุบัน
    void Deposit(double balance_) {
        this->balance_ += balance_;
    }
    void Withdraw(double amount) {
        balance_ -= amount;
    }

    // member function overload
    void AddInterest(double interest) {
        // my_interest is a local variable
        double my_interest = balance_ * interest;
        balance_ += my_interest;
    }
    void AddInterest() {
        balance_ += balance_ * 0.02;
    }    
private:
    int id_;
    double balance_;
};

int main() {
    BankAccount a1(1, 100);
    a1.Deposit(200);

    BankAccount &a1Ref = a1; // reference ของ a1
    BankAccount *a1Ptr = &a1; // pointer ของ a1
    BankAccount a1Copy = a1; // copy ของ a1

    // new คล้ายกับ malloc ใน C
    BankAccount *myAct = new BankAccount(2,2000);
    cout << myAct->GetBalance() << endl;
    // delete คล้ายกับ free ใน C
    delete myAct;

    cout << "-------------" << endl;
    cout << a1.GetBalance() << endl;
    cout << a1Ref.GetBalance() << endl;
    cout << a1Ptr->GetBalance() << endl;
    cout << a1Copy.GetBalance() << endl;

    a1.Deposit(50);
    cout << "-------------" << endl;
    cout << a1.GetBalance() << endl;
    cout << a1Ref.GetBalance() << endl;
    cout << a1Ptr->GetBalance() << endl;
    cout << a1Copy.GetBalance() << endl;

}
