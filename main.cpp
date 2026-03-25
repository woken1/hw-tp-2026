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

template< class T >
struct default_compare {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template< class T, class Compare = default_compare<T> >
T* merge(const T* a, size_t sa,
         const T* b, size_t sb,
         T* c, size_t sc,
         Compare comp = Compare())
{
    if (!a && sa != 0) {
        throw invalid_argument("merge: null pointer a with non-zero size");
    }
    if (!b && sb != 0) {
        throw invalid_argument("merge: null pointer b with non-zero size");
    }
    if (!c) {
        throw invalid_argument("merge: null output pointer c");
    }
    
    if (sc < sa + sb) {
        throw length_error("merge: output buffer too small");
    }
    
    return c;
}

int main() {
    return 0;
}
