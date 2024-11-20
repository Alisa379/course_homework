
#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class console_LogCommand : LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class file_LogCommand : LogCommand {
public:
    void print(const std::string& message) override {
        std::ofstream file("D:\\file.txt");
        file << message << std::endl;
    }
};

void print(const std::string& message) {
    console_LogCommand log1;
    file_LogCommand log2;
    log1.print(message);
    log2.print(message);
}

int main()
{
    print("Hello, World!");
}


