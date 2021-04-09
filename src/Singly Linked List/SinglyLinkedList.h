#pragma once
#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T m_value;
        Node *m_next;
        Node(T value, Node *next) {
            m_value = value;
            m_next = next;
        }
    };

    Node *head = nullptr;
    size_t length = 0;

public:
    void add(const T &value) {
        if (head == nullptr) { head = new Node(value, nullptr); }
        else {
            for (Node *tmp = head;; tmp = tmp->m_next) {
                if (tmp->m_next == nullptr) {
                    tmp->m_next = new Node(value, nullptr);
                    break;
                }
            }
        }
        length++;
    }


    size_t getSize() {
        return length;
    }

    void remove(const T &value) {
        Node *tmp = head;
        // If the item being removed is the head of the list 
        if (head->m_value == value) {
            tmp = head->m_next;
            delete head;
            head = tmp;
            return;
        }
        Node *tmpPrev = head;
        tmp = head->m_next;
        for (;;) {
            // If the item being removed is anywhere other than the head of the list
            if (tmp == nullptr) { return; }
            if (tmp->m_value == value) {
                tmpPrev->m_next = tmp->m_next;
                delete tmp;
                length--;
                return;
            }
            tmpPrev = tmp;
            tmp = tmp->m_next;
        }

    }

    bool contains(const T &value) {
        return indexOf(value) != -1;
    }

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

    ~LinkedList() {
        LinkedList<T>::Node *tmp = head;
        LinkedList<T>::Node *tmpNext = head->m_next;
        for (;;) {
            if (tmpNext == nullptr) { break; }
            delete tmp;
            tmp = tmpNext;
            tmpNext = tmpNext->m_next;
        }
    }

    template <typename A>
    friend std::ostream &operator<<(std::ostream &stream, const LinkedList<A> &ll) {
        Node *tmp = ll.head;
        size_t counter = 0;
        for (;;) {
            if (tmp == nullptr) { stream << std::endl; break; }
            stream << tmp->m_value;
            if (counter < (ll.length - 1)) { stream << " -> "; }
            tmp = tmp->m_next;
            counter++;
        }
        return stream;
    }
};
