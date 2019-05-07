#include <iostream>
using namespace std;

class BankAccount {
private:
  string name;
  double balance;

public:
    // ------------------------
    //    constructors
    // ------------------------
  BankAccount(string n) {
    name = n;
    balance = 0;
    cout << "constructor ----" << name << endl;
  }
  BankAccount(string n, double b) {
    name = n;
    balance = b;
  }
    // ------------------------
    //    desstructors
    // ------------------------
    //      - จะถูกเรียกตอนอ๊อบเจ็กต์ออกจาก scope การทำงาน
    //
    //     - destructor จะถูกเรียกใน reverse order
    //       ของ constructor ใน scope นั้น
    //
    //     - ใช้เมื่อ
    //         - free memory หรือ delete อ๊อบเจ็กต์
    //         - closing files

    ~BankAccount() {
        cout << "  DESTRUCTOR ----" << name << endl;
    }

  void Deposit(double amount) {
    balance += amount;
  }
  void Withdraw(double amount) {
    balance -= amount;
  }
  double GetBalance() const {
    return balance;
  }
  string GetName() const {
    return name;
  }
};

void myFunc() {
    BankAccount c("C");
}

int main() {
    BankAccount a("A");
    BankAccount b("B");
    myFunc();
    cout << "hello" << endl;
    BankAccount d("D");
    
}
