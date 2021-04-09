#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
    size_t maxSize;         // Keeps track of the maximum number of T that be stored.
    size_t initialSize;     // Keeps track of the inital size when the Constructor was called.
    size_t currentSize;     // Keeps track of where the current index is.
    T *array;               // The array itself.
public:
    Vector() { Vector(10); }
    /**
     * @brief Construct a new Vector object and gives it a default size of 10, if none is provided
     *
     * @param size
     */
    Vector(const int &size) {
        // Allocates memory on the heap. 
        array = (T *)malloc(sizeof(T) * size);

        // If a nullptr is returned, then prints an Error Message and returns
        if (array == nullptr) { std::cout << "Error occurred while allocating memory" << std::endl; return; }

        maxSize = size;
        initialSize = size;
    }

    /**
     * @brief Adds a Node to end of the array
     *
     * @param value
     */
    void append(const T &value) {
        // If the array has no room left, then reallocates 2x times the memory
        if (currentSize >= maxSize) {
            maxSize *= 2;
            array = (T *)realloc(array, sizeof(T) * maxSize);
            // Checks for nullptr
            if (array == nullptr) { std::cout << "Error occurred while allocating memory" << std::endl; return; }
        }
        // Sets the value at the last empty index and increments the index tracker variable, i.e. currentSize
        array[currentSize++] = value;
    }

    /**
     * @brief Reseves (getSize() + valueCount), in case for future to avoid reallocating memory in the future.
     *
     * @param valueCount
     */
    void reserve(const int &valueCount) {
        // Updates the size
        maxSize += valueCount;

        // Reallocates memory and copies the previous data over.
        array = (T *)realloc(array, sizeof(T) * maxSize);
    }

    /**
     * @brief Returns the current maximun supported size
     *
     * @return size_t
     */
    size_t getSize() { return maxSize; }

    /**
     * @brief Returns whether value in contained within the Vector.
     *
     * @param value
     * @return true
     * @return false
     */
    bool contains(const T &value) {
        return indexOf(value) != -1;
    }

    /**
     * @brief Returns the index of the Array Node that holds the value. In case it's not found
     *
     * @param value
     * @return int
     */
    int indexOf(const T &value) {
        for (int i = 0; i < maxSize; i++) {
            if (array[i] == value) {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief Allows the user to use the [] syntax with this Vector, like arrays.
     *
     * @param idx
     * @return T&
     */
    T &operator[](const size_t &idx) {
        if (idx >= 0 && idx < maxSize) {
            return array[idx];
        }
        return array[0];
    }

    /**
     * @brief Destroy the Vector object and frees the memory
     *
     */
    ~Vector() {
        free(array);
    }

    /**
     * @brief Returns a printable form of the array.
     *
     * @tparam A
     * @param stream
     * @param vector
     * @return std::ostream&
     */
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
