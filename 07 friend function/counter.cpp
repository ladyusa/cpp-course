#include <iostream>
using namespace std;

class Counter {
    // ประกาศให้ GroupCounter เป็น friend function เพื่อให้
    // GroupCounter สามารถเข้าถึง data member/member function ที่เป็น
    // private ได้ (ประกาศในคลาส แต่ implement นอกคลาส)
    friend void GroupCounter(Counter &c, int n);
public:
    Counter() : count_(0) {}
    void Increment() { count_++; }
    int GetCount() { return count_; }
private:
    int count_;
};
// friend function implementation
void GroupCounter(Counter &c, int n) {
    c.count_ += n;
}

int main() {
    Counter c;
    cout << c.GetCount() << endl;
    c.Increment();
    cout << c.GetCount() << endl;
    GroupCounter(c, 20);
    cout << c.GetCount() << endl; 
}
