#include <iostream>

class my_exception {
private:
    const char* message;
public:
    my_exception(const char* msg) : message(msg) {}
    const char* what() const {
        return message;
    }
};

class invalid_argument : public my_exception {
public:
    invalid_argument(const char* msg) : my_exception(msg) {}
};

class length_error : public my_exception {
public:
    length_error(const char* msg) : my_exception(msg) {}
};

int main() {
    return 0;
}
