

#include <iostream>
#include <vector>
#include <future>


template<typename It, typename Func, size_t size = 25>
void for_each_(It begin, It end, Func f) {
    size_t  curr_size = std::distance(begin, end);
    if (curr_size <= size) {
        std::for_each(begin, end, f);
    }
    else {
        It const mid = begin + curr_size / 2;
        auto ft_res = std::async(for_each_<It, Func>, begin, mid, f);
        for_each_(mid, end, f);
        ft_res.get();
    }
}


int main()
{
    std::vector<int> V(100, 2);
    auto print = [](const int& n) { std::cout << n << " "; };
    for_each_(V.begin(), V.end(), print);
}

