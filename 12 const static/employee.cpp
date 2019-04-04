#include <iostream>
#include "employee.h"
using namespace std;

int Employee::count_ = 0;

Employee::Employee(std::string n) {
    name_ = n;
    count_++;
    my_count_++;
}
Employee::~Employee() {
    count_--;
    my_count_--;

    cout << " DESTRUCTOR " << name_ << " Count = " << count_ << endl;
}
string Employee::getName() const {
    return name_;
}
int Employee::getCount() {
    cout << name_ << endl;
    return count_;
}
int main() {
    cout << "Employee::count_ = " << Employee::getCount() << endl;

    Employee e1("E1");
    cout << "e1.count_ = " << Employee::getCount() << endl;
    //cout << "e1.my_count_ = " << e1.my_count_ << endl;

    Employee e2("E2");
    cout << "e2.count_ = " << Employee::getCount() << endl;
    //cout << "e2.my_count_ = " << e2.my_count_ << endl;

    Employee e3("E3");
    cout << "e3.count_ = " << e3.getCount() << endl;
    cout << "e3.my_count_ = " << e3.my_count_ << endl;
}
