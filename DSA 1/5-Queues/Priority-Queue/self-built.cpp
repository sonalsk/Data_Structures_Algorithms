#include <iostream>
#include <cassert>

using namespace std;

class PriorityQueue {
    private:
        int capacity;
        int numElements;
        int front;
        int back;
        int * queueArr;
    
    public:
        PriorityQueue(int);
        bool isEmpty();
        int getFront();
        int getBack();
        void enqueue(int);
        int dequeue();
        int dequeueBack();
        int getSize();
        void showqueue();
};

PriorityQueue::PriorityQueue(int size) {
    capacity = size;
    queueArr = new int[size];
    assert(queueArr != NULL);
    numElements = 0;
    front = 0;
    back = -1;
}

bool PriorityQueue::isEmpty() {
    return (numElements == 0);
}

int PriorityQueue::getFront() {
    if (isEmpty()) {
        return -1;
    }
    else {
        return queueArr[front];
    }
}

int PriorityQueue::getBack() {
    if (isEmpty()) {
        return -1;
    }
    else {
        return queueArr[back];
    }
}

void PriorityQueue::enqueue(int value) {
    if (numElements == capacity) {
        return;
    }

    int i;
    for (i = numElements - 1; i >= 0; i--) {
        if (queueArr[i] > value) {
            queueArr[i + 1] = queueArr[i];
        }
        else {
            break;
        }
    }

    queueArr[i + 1] = value;
    numElements++;
}

int PriorityQueue::dequeue() {
    if (isEmpty()) {
        return -1;
    }
    
    int tmp = queueArr[front++];
    if (front == capacity) {
        front = 0;
    }
    numElements--;
    return tmp;
}

int PriorityQueue::dequeueBack() {
    if (isEmpty()) {
        return -1;
    }
    return queueArr[--numElements];
}

int PriorityQueue::getSize() {
    return numElements;
}

void PriorityQueue::showqueue() {
    int i = front;
    int count = 0;
    while (count != numElements) {
        cout << queueArr[i%capacity] << " ";
        i++;
        count++;
    }
    cout << endl;
}

int main() {
    PriorityQueue q(5);
    q.enqueue(50);
    q.enqueue(20);
    q.enqueue(10);
    q.enqueue(40);
    q.enqueue(30);

    q.showqueue();

    q.dequeueBack();
    q.showqueue();
}
 