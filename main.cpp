#include <iostream>
#include "heap.hpp"

using namespace std;

/*
 * Used the Singleton Design Pattern
 */
int main() {
    vector<int> temp{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    heap<int, vector<int>> singleton_heap = heap<int, vector<int>>::get_instance(temp);

    cout << singleton_heap << endl;
    cout << "================================================" << endl;

    cout << "HEAP SIZE: " << singleton_heap.size() << endl;
    cout << "================================================" << endl;

    singleton_heap.push(20);
    cout << singleton_heap << endl;
    cout << "================================================" << endl;

    int head = singleton_heap.pop();
    cout << "POPPED: " << head << endl;
    cout << singleton_heap << endl;
    cout << "================================================" << endl;

    if (singleton_heap.is_empty()) {
        cout << "HEAP IS EMPTY" << endl;
    } else {
        cout << "HEAP IS NOT EMPTY" << endl;
    }
    cout << "================================================" << endl;

    singleton_heap.clear_heap();
    if (singleton_heap.is_empty()) {
        cout << "HEAP IS EMPTY" << endl;
    } else {
        cout << "HEAP IS NOT EMPTY" << endl;
    }

    return 0;
}