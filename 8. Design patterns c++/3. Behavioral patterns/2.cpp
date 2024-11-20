
#include <iostream>
#include <vector>
#include <fstream>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};


class warning_Observer : Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class error_Observer : Observer {
public:
    void onError(const std::string& message) override {
        std::ofstream file("D:\\file.txt");
        file << message << std::endl;
    }
};

class fatal_Observer : Observer {
public:
    void onFatalError(const std::string& message) override {
        std::cout << message << std::endl;
        std::ofstream file("D:\\file.txt");
        file << message << std::endl;
    }
};

class Observed {
public:
    void AddObserver(warning_Observer* observer) {
        observers1.push_back(observer);
    }
    void AddObserver(error_Observer* observer) {
        observers2.push_back(observer);
    }
    void AddObserver(fatal_Observer* observer) {
        observers3.push_back(observer);
    }
    void RemoveObserver(warning_Observer* observer) {
        auto it = std::remove(observers1.begin(), observers1.end(), observer);
        observers1.erase(it, observers1.end());
    }
    void RemoveObserver(error_Observer* observer) {
        auto it = std::remove(observers2.begin(), observers2.end(), observer);
        observers2.erase(it, observers2.end());
    }
    void RemoveObserver(fatal_Observer* observer) {
        auto it = std::remove(observers3.begin(), observers3.end(), observer);
        observers3.erase(it, observers3.end());
    }
    void warning(const std::string& message) const {
        for (auto observer : observers1) {
            observer->onWarning(message);
        }
    }
    void error(const std::string& message) const {
        for (auto observer : observers2) {
            observer->onError(message);
        }
    }
    void fatalError(const std::string& message) const {
        for (auto observer : observers3) {
            observer->onFatalError(message);
        }
    }
private:
    std::vector<warning_Observer*> observers1;
    std::vector<error_Observer*> observers2;
    std::vector<fatal_Observer*> observers3;
};

int main()
{
    warning_Observer* wOb1 = new warning_Observer();
    error_Observer* wOb2 = new error_Observer();
    fatal_Observer* wOb3 = new fatal_Observer();
    Observed obd;
    obd.AddObserver(wOb1);
    obd.AddObserver(wOb2);
    obd.AddObserver(wOb3);
    obd.warning("Warning!");
    obd.error("Error!");
    obd.fatalError("Fatal error!");
}

