

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void un(T &V) {
    sort(V.begin(), V.end());
    auto new_end = unique(V.begin(), V.end());
    V.erase(new_end, V.end());
    std::for_each(V.begin(), V.end(), [](auto el) { std::cout << el << " "; });
}

int main()
{
    std::vector<int> V = { 1, 1, 2, 5, 6, 1, 2, 4 };
    un(V);
}

