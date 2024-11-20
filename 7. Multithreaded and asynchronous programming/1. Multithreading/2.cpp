
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

void sum(std::vector<int> v1, std::vector<int> v2, std::vector<int> v3, int ths, int th) {
    int l = 0;
    for (auto el : v1) {
        l++;
    }
    int i = (l / ths) * th;
    if (ths - 1 != th) {
        int stop = (l / ths) * (th + 1);
        for (i; i < stop; i++) {
            v3.push_back(v1.at(i));
            v3.push_back(v2.at(i));
        }
    }
    else {
        for (i; i < l; i++) {
            v3.push_back(v1.at(i));
            v3.push_back(v2.at(i));
        }
    }
}



int main()
{
    std::cout << "Number of hardware cores: " << std::thread::hardware_concurrency() << std::endl << std::endl;;
    std::cout << "        " << "\t" << "1000" << "\t" << "\t" << "10000" << "\t" << "\t"  << "100000" << "\t" << "\t" << "1000000" << std::endl;
    for (int i = 1; i < 17; i *= 2) {
        std::cout << i << " threads";
        for (int j = 1000; j <= 1000000; j *= 10) {
            auto start = std::chrono::steady_clock::now();
            std::vector<std::thread> v;
            std::vector<int> v1(j);
            std::vector<int> v2(j);
            std::vector<int> v3(j * 2);
            for (int g = 0; g < i; g++) {
                v.push_back(std::thread(sum, v1, v2, v3, i, g));
            }
            for (auto& el : v) {
                el.join();
            }
            auto end = std::chrono::steady_clock::now();
            auto diff = std::chrono::duration<double>(end - start);
            std::cout << "\t" << diff;
        }
        std::cout << std::endl;
    }
}