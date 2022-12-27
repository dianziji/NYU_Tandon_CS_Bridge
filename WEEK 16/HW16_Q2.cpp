#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
    vector<T> data;
    int frontIndex = 0;
    int backIndex = 0;
public:
    Queue() : frontIndex(0), backIndex(0) { }
    T front() { return data[frontIndex]; }
    T back() { return data[backIndex]; }
    void pushBack(T newData) { data.push_back(newData); backIndex = static_cast<int>(data.size()) - 1; } //size_t conversion
    void popFront();
    void reset() { data.clear(); frontIndex = 0; backIndex = 0; }
    bool empty() const { return data.empty(); }
    int size() const { return static_cast<int>(data.size()); }  //size_t conversion
    void printQueue() { for (int i = frontIndex; i <= backIndex; i++) cout << data[i] << ' '; } // testing --- only want to print the active queue
};

void space();
// line breaks for mine own sake.

int main(){

    Queue<int> myQueue;

    cout << myQueue.size() << endl; // should be 0
    cout << myQueue.empty() << endl;   // should be 1/true

    space();
    for (int i = 100; i > 0; i-=10) {
        myQueue.pushBack(i);
        cout << myQueue.front() << '\t' << myQueue.back() << endl;
    }

    space();
    myQueue.popFront(); // remove 100
    myQueue.popFront(); // remove 90
    myQueue.printQueue(); // should print 80 70 ... 10

    space();
    Queue<int> mySecondQueue;
    for (int i = 1; i <= 5; i++) {
        mySecondQueue.pushBack(i * i);
        cout << mySecondQueue.front() << '\t' << mySecondQueue.back() << endl;
    }

    mySecondQueue.popFront();    // remove 1
    mySecondQueue.popFront();    // remove 4

    myQueue = mySecondQueue;
    myQueue.printQueue();   //should print 9 16 25
    cout << endl;
    mySecondQueue.printQueue();      //should also print 9 16 25

    return 0;
}
template <class T>
void Queue<T>::popFront() {
    if (!data.empty()) { // shouldn't pop if there's nothing to pop
        frontIndex++;
        if (frontIndex > backIndex) { // we can pop when the indices are the same (single element), but after that we need to reset
            reset();        // clear vector, reset indices 
        }
    }
}
void space() {
    cout << "\n\n";
}