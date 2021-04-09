#include <iostream>
#include <SinglyLinkedList.h>

int main() {
    LinkedList<int> ll;

    ll.add(10);
    ll.add(14);
    ll.add(12);
    std::cout << ll.getSize() << std::endl;
    std::cout << ll << std::endl;

    ll.add(1);
    ll.remove(10);
    ll.add(13);
    std::cout << ll.getSize() << std::endl;
    std::cout << ll << std::endl;

    std::cout << ll.contains(99) << std::endl;
    std::cout << ll.indexOf(99) << std::endl;
}
