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

    explicit heap(V stl_sequence) {
        copy(stl_sequence.begin(),
             stl_sequence.end(),
             back_inserter(my_heap));
        heapify();
    }

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

    static heap &get_instance(V stl_sequence) {
        static heap instance(stl_sequence);
        return instance;
    }

    ~heap() {
        my_heap.clear();
    }

    void push(T data) {
        my_heap.push_back(data);
        heapify();
    }

    T pop() {
        T head = my_heap[0];
        my_heap.erase(my_heap.begin());
        heapify();
        return head;
    }

    int size() {
        return static_cast<int>(my_heap.size());
    }

    bool is_empty() {
        return my_heap.size() == 0;
    }

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

    heap(heap const &) = default;

    void operator=(heap const &) = delete;
};

#endif //HEAP_HEAP_HPP
