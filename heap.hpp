//
// Created by Daniel Shin on 2018-11-28.
//
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP

template<class T, class V>
class heap {
private:
    vector<T> my_heap;

    /*
     * heap constructor which accepts any STL sequence
     * of elements and copies them to the heap.
     */
    explicit heap(V stl_sequence) {
        copy(stl_sequence.begin(),
             stl_sequence.end(),
             back_inserter(my_heap));
        heapify();
    }

    /*
     * a function which ensures the elements in the heap
     * are in the heap form.
     */
    void heapify() {
        bool done = true;
        while (done) {
            done = false;
            for (int i = static_cast<int>(my_heap.size() - 1); i > 0; --i) {
                if (my_heap[i / 2] < my_heap[i]) {
                    swap(my_heap[i], my_heap[i / 2]);
                    done = true;
                }
            }
        }
    }

public:
    /*
     * a function which returns the static instance of the
     * heap class to implement the singleton design pattern.
     */
    static heap &get_instance(V stl_sequence) {
        static heap instance(stl_sequence);
        return instance;
    }

    /*
     * heap destructor to clear all the contents of the heap.
     */
    ~heap() {
        my_heap.clear();
    }

    /*
     * a function which accepts an element and pushes it into
     * the heap.
     */
    void push(T data) {
        my_heap.push_back(data);
        heapify();
    }

    /*
     * a function which removes and returns the root (max)
     * element from the heap.
     */
    T pop() {
        T head = my_heap[0];
        my_heap.erase(my_heap.begin());
        heapify();
        return head;
    }

    /*
     * a function which returns the number of elements in the heap.
     */
    int size() {
        return static_cast<int>(my_heap.size());
    }

    /*
     * a function which returns true if the heap is empty, false
     * otherwise.
     */
    bool is_empty() {
        return my_heap.size() == 0;
    }

    /*
     * an overloaded insertion operator to allow printing of the
     * heap contents to the standard output.
     */
    friend ostream &operator<<(ostream &os, const heap &h) {
        os << "Heap Contents: ";
        copy(h.my_heap.begin(),
             h.my_heap.end(),
             ostream_iterator<T>(os, " "));
        return os;
    }

    void clear_heap() {
        my_heap.clear();
    }

    /*
     * copy constructor of the heap.
     */
    heap(heap const &) = default;

    /*
     * an overloaded assignment operator of the heap.
     */
    void operator=(heap const &) = delete;
};

#endif //HEAP_HEAP_HPP
