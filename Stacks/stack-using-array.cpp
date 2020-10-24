#include <iostream>
#include <cassert>

using namespace std;

class myStack {
    private:
        int capacity;
        int numElements;
        int * stackArr;
    
    public:
        myStack(int);
        bool isEmpty();
        int getTop();
        bool push(int);
        int pop();
        int getSize();
        void showStack();
};

myStack::myStack(int size) {
    capacity = size;
    stackArr = new int[size];
    assert(stackArr != NULL);
    numElements = 0;
}

bool myStack::isEmpty() {
    return (numElements == 0);
}

int myStack::getTop() {
    return (numElements == 0 ? -1 : stackArr[numElements - 1]);
}

bool myStack::push(int value) {
    if (numElements < capacity) {
            stackArr[numElements] = value;
            numElements++;
            return true;
        } else {
            cout << "Stack Full." << endl;
            return false;
    }
}

int myStack::pop() {
    if (numElements == 0) {
        cout << "Stack Empty" << endl;
        return -1;
    } else {
        numElements--;
        return stackArr[numElements];
    }
}

int myStack::getSize() {
    return numElements;
}

void myStack::showStack() {
    int i = 0;
    while (i < numElements) {
        cout << stackArr[numElements - 1 - i] << endl;
        i++;
    }
    cout << "END\n";
}

int main() {
    myStack stack(5);
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    stack.showStack();
}