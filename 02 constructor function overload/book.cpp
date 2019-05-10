#include <iostream>
using namespace std;

class Book {

private:
    string title;
    string author;
    string publisher;
    int quantity;

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
    Book(string t, string a, string p, int q) {
        title = t;
        author = a;
        publisher = p;
        quantity = q;
    }
    Book(string t, string a, string p) {
        title = t;
        author = a;
        publisher = p;
        quantity = 1;        
    }

    //--------------------------------
    // function overload
    //--------------------------------
    // - ในคลาสเดียวกัน มีฟังก์ชันชื่อเดียวกันได้หลายฟังก์ชัน
    //   โดยแต่ละอันจะมีพารามิเตอร์ที่ต่างกัน
    //--------------------------------
    void borrow() {
        int quant_to_borrow = 1;
        if (quantity > 0) {
            quantity = quantity - quant_to_borrow;
        } else {
            cout << "No more book" << endl;
        }
    }
    void borrow(int quant_to_borrow) {
        if (quantity > 0) {
            quantity = quantity - quant_to_borrow;
        } else {
            cout << "No more book" << endl;
        }
    }
    void returnBook() {
        int quant_to_return = 1;
        quantity = quantity + quant_to_return;
    }
    void returnBook(int quant_to_return) {
        quantity = quantity + quant_to_return;
    }    
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    string getPublisher() {
        return publisher;
    }
    int getQuantity() {
        return quantity;
    }
    void setTitle(string new_title) {
        title = new_title;
    }
    void setAuthor(string new_author) {
        author = new_author;
    }
    void setPublish(string new_publisher) {
        publisher = new_publisher;
    }
    void setQuantity(int new_quantity) {
        if (new_quantity > 0) {
            quantity = new_quantity;
        }
    }
};

int main() {
    Book c_book("C Programming",
                "Dennis Richie",
                "McGrow", 3);
    Book stat_book("Intro to Stat",
                   "John Smith",
                   "MIT");
    Book pooh("Winnie the Pooh",
              "Christopher",
              "Children Book");

    c_book.borrow(2);
    c_book.returnBook(1);
    cout << c_book.getTitle() << " has " 
         << c_book.getQuantity() << endl;
}