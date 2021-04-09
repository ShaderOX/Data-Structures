#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
    size_t maxSize;         // Keeps track of the maximum number of T that be stored.
    size_t initialSize;     // Keeps track of the inital size when the Constructor was called.
    size_t currentSize;     // Keeps track of where the current index is.
    T *array;
public:
    Vector() { Vector(10); }
    Vector(const int &size) {
        array = (T *)malloc(sizeof(T) * size);
        if (array == NULL) { std::cout << "Error occurred while allocating memory" << std::endl; }
        maxSize = size;
        initialSize = size;
    }

    void append(const T &value) {
        if (currentSize >= maxSize) {
            maxSize *= 2;
            array = (T *)realloc(array, sizeof(T) * maxSize);
            if (array == NULL) { std::cout << "Error occurred while allocating memory" << std::endl; }
        }
        array[currentSize++] = value;
    }

    void reserve(const int &valueCount) {
        maxSize += valueCount;
        array = (T *)realloc(array, sizeof(T) * maxSize);
    }

    size_t getSize() { return maxSize; }

    bool contains(const T &value) {
        return indexOf(value) != -1;
    }

    int indexOf(const T &value) {
        for (int i = 0; i < maxSize; i++) {
            if (array[i] == value) {
                return i;
            }
        }
        return -1;
    }

    T &operator[](const size_t &idx) {
        if (idx >= 0 && idx < maxSize) {
            return array[idx];
        }
        return array[0];
    }

    ~Vector() {
        free(array);
    }

    template <typename A>
    friend std::ostream &operator<<(std::ostream &stream, const Vector<A> &vector) {
        stream << '[';
        for (int i = 0; i < vector.currentSize; i++) {
            stream << vector.array[i] << ", ";
        }
        stream << ']' << std::endl;
        return stream;
    }
};
