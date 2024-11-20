
#include <iostream>
#include <string>
#include <map>
#include <vector>

void Bubble(std::vector<std::pair<char, int>> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j].second < vec[j + 1].second) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main()
{
    std::string string;
    std::map<char, int> data;
    std::getline(std::cin, string);

    for (const auto& i : string) {
        if (data.find(i) == data.end()) {
            data[i] = 1;
        }
        else {
            const std::map<char, int>::iterator& t = data.find(i);
            t->second += 1;
        } 
    }

    std::vector<std::pair<char, int>> vec;

    for (const auto &i : data) {
        vec.push_back(i);
    }

    Bubble(vec);

    for (const auto& i : vec) {
        std::cout << i.first << ": " << i.second << std::endl;
    }
}

