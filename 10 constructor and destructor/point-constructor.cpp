#include <iostream>
using namespace std;

class Time {
public:
    // -------------------------------
    // 1. normal constructor 
    //    - assigning data members in body
    //    - good when need to check parameters' values
    Time(int h, int m, int s) {
        if ((0 <= h && h <= 23) &&
            (0 <= m && m <= 59) &&
            (0 <= s && s <= 59)) {
             hour = h;
             minute = m;
             second = s;
        }
    }
    // -------------------------------
    // 2. member-initializer list ใน constructor
    //    - more efficient than normal constructor
    //      when you don't need to check parameters' values
    Time(int h, int m, int s) 
        : hour(h), minute(m), second(s) {}

    // // constructor overload
    // Time(int h) : hour(h), minute(0), second(0) {}
    // Time(int h, int m) : hour(h), minute(m), second(0) {}
    // Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // -------------------------------
    // 3. constructor with default arguments
    //     - ทำให้สามารถเรียก constructor ได้หลายแบบ โดยใช้
    //       โค้ด constructor อันเดียวกัน เช่น
    //            Time t1;
    //            Time t2(5);
    //            Time t3(5, 30);
    //            Time t4(5, 30, 10);

    Time(int h = 0, int m = 0, int s = 0) 
        : hour(h), minute(m), second(s) {}

    // -------------------------------
    // 4. delegating constructor 
    //      - ส่งการทำงานให้ constructor อื่นช่วยทำ
    //      - delegate งาน ให้ constructor อื่น
    //      *** ต้องใช้ standard C++11
    // -------------------------------
    Time() : Time(0,0,0) {}
    Time(int h) : Time(h,0,0) {}
    Time(int h, int m) : Time(h,m,0) {}
    Time(int h, int m, int s) {
        if ((0 <= h && h <= 23) &&
            (0 <= m && m <= 59) &&
            (0 <= s && s <= 59)) {
             hour = h;
             minute = m;
             second = s;
        }
        cout << "constructor " << ToString() << endl;
    }
    //-------------------------------
    // การสร้าง copy constructor ของเราเอง 
    // ทำได้ โดยการรับ object ของคลาสเราเป็น parameter
    //    - ถูกเรียกเมื่อมีการ copy / assign object
    Time(Time &t) {
        hour = t.hour;
        minute = t.minute;
        second = 0;
        cout << "--- In our copy constructor ---" << endl;
    }

    // ----------------------------
    //  Destructor
    //    - ถูกเรียกเมื่อโปรแกรมออกจาก scope
    //      ของการประกาศ/สร้าง object นี้
    //    - ใช้เพื่อ clean up เกี่ยวกับ object นี้่ เช่น
    //        - ปิดfile / network ที่เราได้เปิดไว้ในคลาสนี้
    //        - delete object ที่เราได้สร้าง (new) ในคลาสนี้
    //    - ถูกเรียกในลำดับที่กลับกันกับ constructor
    //      destructor is called in reverse order of
    //      constructor
    // ----------------------------
    ~Time() {
        cout << "   DESTRUCTOR " << ToString() << endl;
    }

    string ToString() const {
        string s = to_string(hour) + ":" 
                 + to_string(minute) + ":"
                 + to_string(second);
        return s;
    }
private:
    int hour;
    int minute;
    int second;
};

int main() {
    Time t1;
    Time t2(5);
    Time t3(5, 30);
    Time t4(5, 30, 10);

    cout << t1.ToString() << endl;
    cout << t2.ToString() << endl;
    cout << t3.ToString() << endl;
    cout << t4.ToString() << endl;

    Time t5 = t4;   // การ assign ค่าแบบนี้ จะเกิดการ copy
                    // โดย C++ จะสร้าง object ใหม่ชื่อ t5
                    // แล้ว copy ค่า data member ทั้งหมด
                    // ของ t4 ใส่ใน t5
                    //
                    // ซึ่งกระบวนการนี้ทำได้ เนื่องจาก C++
                    // ใช้ default "copy constructor"
                    //
                    // ถ้าเราต้องการให้ปรับเปลี่ยนการทำงาน
                    // ในการ copy เราสามารถสร้าง
                    // copy constructor ของเราเองได้
    cout << t5.ToString() << endl;
}