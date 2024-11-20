
#include <iostream>
#include <vector>
#include <algorithm>


class functor {
public:
    int sum = 0, count = 0;
    int get_sum() {
        return sum;
    }
    int get_count() {
        return count;
    }
    void operator()(int value) {
        sum += value;
        count++;
    }
};

int main()
{
    std::vector<int> vector = { 4, 1, 3, 6, 25, 54 };
    functor f;

    f = std::for_each(vector.begin(), vector.end(), f);

    std::cout << "[OUT] : get_sum() = " << f.get_sum() << std::endl;
    std::cout << "[OUT] : get_count() = " << f.get_count() << std::endl;
}