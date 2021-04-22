#include <bits/stdc++.h>

using namespace std;

class Heap {
    private:
        void swapNodes(int, int);
    public:
        vector <int> heap;
        int size = 0;

        int parentIndex(int);
        int leftChildIndex(int);
        int rightChildIndex(int);

        void display();

        int getSize();
        int getLeftChild(int);
        int getRightChild(int);

        void bubbleUp();
        void insert(int);

        bool isValidParent(int);
        void bubbleDown();
        int remove();        
};

void Heap::swapNodes(int i, int parent) {
    int temp = heap[i];
    heap[i] = heap[parent];
    heap[parent] = temp;
}

int Heap::parentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}
int Heap::leftChildIndex(int parentIndex) {
    return (parentIndex * 2) + 1;
}
int Heap::rightChildIndex(int parentIndex) {
    return (parentIndex * 2) + 2;
}

void Heap::display() {
    for (int i = 0; i < heap.size(); i++) {
        cout << i << " " << heap.at(i) << endl;
    }
}

int Heap::getSize() {
    return size;
}
int Heap::getLeftChild(int index) {
    return heap[leftChildIndex(index)];
}
int Heap::getRightChild(int index) {
    return heap[rightChildIndex(index)];
}

void Heap::bubbleUp() {
    int childIndex = size;    
    while (childIndex > 0 && heap[childIndex] > heap[parentIndex(childIndex)]) {
        swapNodes(childIndex, parentIndex(childIndex));
        childIndex = parentIndex(childIndex);
    }
    size++;
}
void Heap::insert(int value) {
    heap.push_back(value);
    bubbleUp();
}

bool Heap::isValidParent(int parentIndex) {
    if (leftChildIndex(parentIndex) > size) {
        return true;
    }
    if (rightChildIndex(parentIndex) > size) {
        return heap[parentIndex] >= getLeftChild(parentIndex);
    }
    return heap[parentIndex] >= getLeftChild(parentIndex) && heap[parentIndex] >= getRightChild(parentIndex);
}

void Heap::bubbleDown() {

    if (size == 0) {
        return;
    }

    int parentIndex = 0;

    while (parentIndex <= size && !isValidParent(parentIndex)) {
        int largerChildIndex;
        if (leftChildIndex(parentIndex) > size) {
            largerChildIndex = parentIndex;
        }
        else if (rightChildIndex(parentIndex) > size) {
            largerChildIndex = leftChildIndex(parentIndex);
        }
        else {
            largerChildIndex = getLeftChild(parentIndex) > getRightChild(parentIndex) ? leftChildIndex(parentIndex) : rightChildIndex(parentIndex);
        }
        swapNodes(parentIndex, largerChildIndex);         
    }
}

int Heap::remove() {
    int root = heap[0];
    heap[0] = heap[size - 1];
    heap.pop_back();
    size--;
    bubbleDown();
    return root;
}

int main() {
    Heap * heap = new Heap();
    heap->insert(4);
    heap->insert(5);
    heap->insert(10);
    heap->insert(15);
    heap->insert(20);

    heap->display();

    cout << heap->remove();
    cout << endl;
    heap->display();

    cout << endl;
    return 0;
}