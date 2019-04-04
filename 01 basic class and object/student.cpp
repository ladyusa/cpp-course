#include <iostream>
using namespace std;

class Student {
public:
	int GetId() const {
		return id_;
	}
	string GetName() const {
		return name_;
	}
	void SetName(string n) {
		name_ = n;
	}
private:
	int id_;
	string name_;
}














