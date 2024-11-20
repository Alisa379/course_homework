

#include <iostream>
#include <mutex>

class Data {
public:
    std::mutex m;
    int a;
    char b;
    Data(Data& ob) {
        this->a = ob.a;
        this->b = ob.b;
    }
    Data(int _a, char _b) : a(_a), b(_b) {}
    void operator=(Data& other) {
        int tempa = this->a;
        char tempb = this->b;
        this->a = other.a;
        this->b = other.b;
        other.a = tempa;
        other.b = tempb;
    }
};

void swap1(Data& ob1, Data& ob2) {
    std::lock(ob1.m, ob2.m);
    std::lock_guard lk1(ob1.m, std::adopt_lock);
    std::lock_guard lk2(ob2.m, std::adopt_lock);
    Data temp(ob1);
    ob1 = ob2;
    ob2 = temp;
}

void swap2(Data& ob1, Data& ob2) {
    std::scoped_lock lk(ob1.m, ob2.m);
    Data temp(ob1);
    ob1 = ob2;
    ob2 = temp;
}

void swap3(Data& ob1, Data& ob2) {
    std::unique_lock lk1{ ob1.m, std::defer_lock };
    std::unique_lock lk2{ ob2.m, std::defer_lock };
    std::lock(lk1, lk2);
    Data temp(ob1);
    ob1 = ob2;
    ob2 = temp;
}

int main()
{
    Data ob1(3, 'std');
    Data ob2(7, 'ch');
    swap1(ob1, ob2);
    swap2(ob1, ob2);
    swap3(ob1, ob2);
    std::cout << ob1.a << " " << ob2.a << std::endl;
}


