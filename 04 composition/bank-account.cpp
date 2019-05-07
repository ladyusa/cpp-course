#include <iostream>
using namespace std;

class BankAccount {
private:
  string name;
  double balance;

public:
  BankAccount(string n) {
    name = n;
    balance = 0;
  }
  BankAccount(string n, double b) {
    name = n;
    balance = b;
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
  void SetName(string n) {
        name = n;
    }
};

class Bank {
private:
    string name;
    BankAccount **accounts;
    int act_size;
public:
    Bank(string name) {
        this->name = name;
        accounts = new BankAccount*[3];
        act_size = 0;
    }
    void addAccount(BankAccount *act) {
        if (act_size < 3)
            accounts[act_size++] = act; 
    }
    void transfer(int from, int to, double amount) {
        accounts[from]->Withdraw(amount);
        accounts[to]->Deposit(amount);
    }
    BankAccount get(int i) {
        return *accounts[i];
    }
    BankAccount *getPtr(int i) {
        return accounts[i];
    }
};

int main() {
    BankAccount *kwan = new BankAccount("Kwan", 500);
    Bank *myBank = new Bank("My Bank");
    myBank->addAccount(kwan);

    BankAccount *ploy = new BankAccount("Ploy", 1000);
    myBank->addAccount(ploy);
    myBank->transfer(0,1,100);
    
    cout << "Kwan: " << kwan->GetBalance() << endl;
    cout << "Ploy: " << ploy->GetBalance() << endl;
}