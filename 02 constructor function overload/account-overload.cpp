#include <iostream>
using namespace std;

//ให้เขียนโปรแกรมเกี่ยวกับบัญชีธนาคาร
// ให้สามารถ
//   - ฝากเงินได้
//   - ถอนเงินได้  
//   - ดูยอดเงินคงเหลือในบัญชีได้
//   - ให้ดอกเบี้ยได้
// และให้สร้างอ๊อบเจกต์ บัญชีธนาคารมา 2 บัญชี 
// ลองฝาก/ถอน/ดูยอด จากบัญชีทั้งสอง

class BankAccount {
private:
	string name;
    double balance;
public:
    //--------------------------------
    // constructor overload
    //--------------------------------
    // - เราสามารถมี construcor หลายแบบในของคลาสเดียวได้ 
    //   โดยแต่ละแบบจะมีพารามิเตอร์ที่ต่างกัน
    //     - มีจำนวนพารามิเตอร์ที่ต่างกัน
    //     - ถ้ามีจำนวนพารามิเตอร์เท่ากัน ต้องมีชนิดข้อมูลต่างกัน
    //       อย่างน้อย 1 พารามิเตอร์
    //    (ถ้ามีจำนวนพารามิเตอร์เท่ากัน และชนิดข้อมูล
    //     เหมือนกันทุกพารามิเตอร์ ถึงแม้ว่า จะมีชื่อพารามิเตอร์ต่างกัน
    //     จะไม่ถือว่าเป็น constructor overload)
    //--------------------------------
    BankAccount(string n) {
        name = n;
        balance = 0;
    }
    BankAccount(string n, double b) {
        name = n;
        balance = b;
    }
    //--------------------------------
    // default constructor:
    //--------------------------------
    //    - constructor ที่ไม่รับพารามิเตอร์ใด
    //    - ช่วยกำหนดค่าเริ่มต้นของ data member
    //      ให้มีค่าเป็น default value
    //    - จะมีก็ต่อเมื่อดาต้าเมมเบอร์ทุกค่ามี
    //      default value 
    //    - C++ จะสร้าง default constructor ให้
    //      โดยอัตโนมัติ ถ้าเราไม่ได้ประกาศ constructor ใดๆ
    //--------------------------------
    Bankaccount() {
        name = "Default";
        balance = 0;
    }
    void Deposit(double amount) {
        balance = balance + amount;
    }
    void Withdraw(double amount) {
        if (amount > balance) {
            cout << "error: amount can't be more than balance" << endl;
        } else {
            balance = balance - amount;
        }
    }
    //--------------------------------
    // function overload
    //--------------------------------
    // - ในคลาสเดียวกัน มีฟังก์ชันชื่อเดียวกันได้หลายฟังก์ชัน
    //   โดยแต่ละอันจะมีพารามิเตอร์ที่ต่างกัน
    //--------------------------------
    void AddInterest() {
        double interest = 0.02;
        balance = balance + (balance * interest);
    }
    void AddInterest(double interest) {
        balance = balance + (balance * interest);
    }
    double GetBalance() const {
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

    // สร้าง object ได้สองแบบ ตามสูปแบบของ constructor
    BankAccount kwan("Kwan", 1000);
    BankAccount kate("Kate");

    cout << kwan.ToString() << endl;
    cout << kate.ToString() << endl;

    kate.Deposit(500);

    // เรียก member function ได้สองแบบ 
    // ตามรูปแบบของ member function
    kwan.AddInterest();
    kate.AddInterest(10);

    cout << kwan.ToString() << endl;
    cout << kate.ToString() << endl;
}