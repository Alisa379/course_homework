#include <iostream>
#include <future>
#include <vector>
#include <random>


int k = 0;

void find_min(std::vector<int> &vec, int i, std::promise<int> prom) {
    int min = 10001;     
    for (i ; i < 100; i++) {
        if (vec[i] < min) {
            min = vec[i];
            k = i;
        }
    }
    prom.set_value(min);
}

int main() {
    std::vector<int> V(100);
    for (auto it = V.begin(); it < V.end(); it++) {
        *it = std::rand() % 1000;
    }
    for (int i = 0; i < 100; i++) {
        std::promise<int> prom;
        std::future<int> ft_res = prom.get_future();
        auto ft = std::async(find_min, ref(V), i, std::move(prom));
        int temp = V[i];
        V[i] = ft_res.get();
        V[k] = temp;
    }
    for (auto it : V) {
        std::cout << it << " ";
    }
}