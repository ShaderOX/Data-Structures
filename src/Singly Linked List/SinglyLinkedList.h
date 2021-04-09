#pragma once
#include <iostream>

template <typename T>
class LinkedList {
private:
    // Will be a LinkedList Node
    struct Node {
        T m_value;
        Node *m_next;
        Node(T value, Node *next)
            : m_value(value), m_next(next) {}
    };

    Node *head = nullptr;   // Holds the pointer to the head of linked list
    size_t size = 0;      // Holds the length of Nodes in the LinkedList
public:
    /**
     * @brief Adds the a Node to the end of the LinkedList.
     *
     * @param value
     */
    void add(const T &value) {
        // If its the first Node to be added then it'll be the head.
        if (head == nullptr) {
            head = new Node(value, nullptr);
        }
        else {
            // Iterates over each Node, and till it finds a nullptr and then adds a new Node.
            for (Node *tmp = head;; tmp = tmp->m_next) {
                if (tmp->m_next == nullptr) {
                    tmp->m_next = new Node(value, nullptr);
                    break;
                }
            }
        }
        // Updates the length of the LinkedList
        size++;
    }

    void addAt(const T &value, const size_t &idx) {
        // Making sure the given index is in bounds.
        if (idx >= getSize()) {
            std::cout << "Index provided is out of bounds" << std::endl;
            return;
        }
        size_t counter = 0;
        for (Node *tmp = head;;) {
            // The index to be inserted at
            if (counter == (idx - 1)) {
                // Previous next pointer
                Node *tmpPrev = tmp->m_next;
                // Setting next pointer to the newly created Node.
                tmp->m_next = new Node(value, nullptr);
                // Setting the next's next pointer to the previous next pointer of the current Node.
                tmp->m_next->m_next = tmpPrev;

                break;
            }
            tmp = tmp->m_next;
        }
        size++;

    }

    /**
     * @brief Gets the size of the LinkedList
     *
     * @return size_t
     */
    size_t getSize() { return size; }

    /**
     * @brief Removes a certain Node with the given value from the LinkedList
     *
     * @param value
     */
    void remove(const T &value) {
        Node *tmp = head;
        // If the item being removed is the head of the list 
        if (head->m_value == value) {
            tmp = head->m_next;
            delete head;
            head = tmp;
        }
        // If the item being removed is anywhere other than the head of the list
        else {
            Node *tmpPrev = head;
            tmp = head->m_next;
            for (;;tmpPrev = tmp, tmp = tmp->m_next) {
                // In case if the Node with the given value is non-existant
                if (tmp == nullptr) { return; }

                // If it finds the node, then adjust the next pointer of the previous Node and frees the memory.
                if (tmp->m_value == value) {
                    tmpPrev->m_next = tmp->m_next;
                    delete tmp;
                    break;
                }
            }
        }

        // Updates the size
        size--;
    }

    /**
     * @brief Returns whether a Node with the given value exists in the LinkedList
     *
     * @param value
     * @return true
     * @return false
     */
    bool contains(const T &value) {
        return indexOf(value) != -1;
    }

    /**
     * @brief Returns the index of the Node with the given value in case it exists or -1 it case it doesn't
     *
     * @param value
     * @return int
     */
    int indexOf(const T &value) {
        Node *tmp = head;
        int counter = 0;
        for (;;) {
            // Incase we reach the end and the value is not found
            if (tmp == nullptr) { return -1; }

            // Incase we find the value, return the index
            if (tmp->m_value == value) { return counter; }

            // Move to the next value in the List
            tmp = tmp->m_next;
            counter++;
        }
    }

    /**
     * @brief Destroy the LinkedList object and frees all the allocated memory
     *
     */
    ~LinkedList() {
        LinkedList<T>::Node *tmp = head;
        LinkedList<T>::Node *tmpNext = head->m_next;
        // Iterates over if the entire LinkedList and frees the memory
        for (;;tmp = tmpNext, tmpNext = tmpNext->m_next) {
            if (tmpNext == nullptr) { break; }
            delete tmp;
        }
    }

    /**
     * @brief Returns a string printable form of the LinkedList object
     *
     * @tparam A
     * @param stream
     * @param ll
     * @return std::ostream&
     */
    template <typename A>
    friend std::ostream &operator<<(std::ostream &stream, const LinkedList<A> &ll) {
        Node *tmp = ll.head;
        size_t counter = 0;
        for (;;) {
            if (tmp == nullptr) { stream << std::endl; break; }
            stream << tmp->m_value;
            if (counter < (ll.size - 1)) { stream << " -> "; }
            tmp = tmp->m_next;
            counter++;
        }
        return stream;
    }
};
