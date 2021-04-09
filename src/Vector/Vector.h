#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
    size_t length;
public:
    Vector(const int &size = 10) {}

    void add(const T &value) {}

    size_t getSize() {}

    bool contains(const T &value) {}

    int indexOf(const T &value) {}

    ~Vector() {}

    template <typename A>
    friend std::ostream &operator<<(std::ostream &stream, const Vector<A> &vector) {}
};
