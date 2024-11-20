#include <iostream>
#include <thread>

using namespace std::chrono_literals;

std::atomic<int> x = 0;

void client(std::atomic<int>& x) {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(1000ms);
        x.store(x.load() + 1);
        std::cout << x.load() << " ";
    }
}

void oper(std::atomic<int>& x) {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(2000ms);
        x.store(x.load() - 1);
        std::cout << x.load() << " ";
    }
}

int main()
{
    std::thread t1(client, std::ref(x));
    std::thread t2(oper, std::ref(x));
    t1.join();
    t2.join();
}