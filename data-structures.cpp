#include <iostream>
#include <cmath>
#include <SinglyLinkedList.h>
#include <Vector.h>

int main() {
    Vector<int> vector(5);
    for (int i = 0; i < 25; i++) {
        vector.append(pow(i, 2));
    }

    std::cout << vector << std::endl;
    std::cout << vector.getSize() << std::endl;
    std::cout << vector[24] << std::endl;
}
