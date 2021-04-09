#include <iostream>
#include <cmath>
#include <SinglyLinkedList.h>
#include <Vector.h>

int main() {

    LinkedList<int> ll;
    ll.add(10);
    ll.add(12);
    ll.add(13);
    ll.add(15);
    std::cout << ll << std::endl;
    std::cout << ll.getSize() << std::endl;
    ll.remove(10);
    std::cout << ll << std::endl;
    std::cout << ll.getSize() << std::endl;
    ll.remove(15);
    std::cout << ll << std::endl;
    std::cout << ll.getSize() << std::endl;

    // Vector<int> vector(5);
    // for (int i = 0; i < 25; i++) {
    //     vector.append(pow(i, 2));
    // }

    // std::cout << vector << std::endl;
    // std::cout << vector.getSize() << std::endl;
    // std::cout << vector[24] << std::endl;
}
