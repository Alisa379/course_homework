
#include <iostream>
#include <fstream>

class LogMessage {
public:
    enum type {
        warning,
        error,
        fatal_error,
        unknown
    };

    void message(type t, const std::string m) const {
        try {
            if (t == type::fatal_error) {
                throw m;
            }
            else {
                e_message(t, m);
            }
        }
        catch(const std::string m) {
            std::cout << m << std::endl;
        }
    }

private:
    void e_message(type t, const std::string m) const {
        if (t == type::error) {
            std::ofstream file("D:\\file.txt");
            file << m << std::endl;
        }
        else {
            w_message(t, m);
        }
    }

    void w_message(type t, const std::string m) const {
        if (t == type::warning) {
            std::cout << m << std::endl;
        }
        else {
            u_message(t, m);
        }
    }

    void u_message(type t, const std::string m) const {
        try {
            throw m;
        }
        catch (const std::string m) {
            std::cout << m << std::endl;
        }
    }
};

int main()
{
    LogMessage l;
    l.message(l.error, "error");
    l.message(l.fatal_error, "fatal error");
    l.message(l.warning, "warning");
    l.message(l.unknown, "unknown");
}


