#include <bits/stdc++.h>
using namespace std;

class Heap {
    private:
        vector<int> heap;

        int getParentIndex(int);
        int getLeftChildIndex(int);
        int getRightChildIndex(int);
        int getParent(int);
        int getLeftChild(int);
        int getRightChild(int);
        void swap(int, int);
        void bubbleUp();
        bool isValidParent(int);
        void bubbleDown();

    public :
        void insert(int);
        void remove();
};

int Heap :: getParentIndex(int child) {
    return (child - 1) / 2;
}

int Heap :: getLeftChildIndex(int parent) {
    return (parent * 2) + 1;
}

int Heap :: getRightChildIndex(int parent) {
    return (parent * 2) + 2;
}

int Heap :: getParent(int child) {
    return heap[getParentIndex(child)];
}

int Heap :: getLeftChild(int parent) {
    return heap[getLeftChildIndex(parent)];
}

int Heap :: getRightChild(int parent) {
    return heap[getRightChildIndex(parent)];
}

void Heap :: swap (int idx1, int idx2) {
    int temp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = temp;
}

void Heap :: bubbleUp() {
    int index = heap.size() - 1;
    while (index > 0 && heap[index] > getParent(index)) {
        swap(index, getParentIndex(index));
        index = getParentIndex(index);
    }
}

bool Heap :: isValidParent(int index) {
    if (getLeftChildIndex(index) >= heap.size()) {
        return true;
    }
    if (getRightChildIndex(index) >= heap.size()) {
        return (heap[index] >= getLeftChild(index)); 
    }
    return heap[index] >= getLeftChild(index) && heap[index] >= getRightChild(index);
}

void Heap :: bubbleDown() {
    if (heap.size() == 0) {
        return;
    }

    int index = 0;

    while (index <= heap.size() && !isValidParent(index)) {
        int largerIndex;
        if (getLeftChildIndex(index) >= heap.size()) {
            largerIndex = index;
        }
        else if (getRightChildIndex(index) >= heap.size()) {
            largerIndex = (getLeftChild(index) > heap[index]) ? getLeftChildIndex(index) : index;
        }
        else {
            largerIndex = (getLeftChild(index) > getRightChild(index)) ? getLeftChildIndex(index) : getRightChildIndex(index);
        }
        swap(index, largerIndex);
        index = largerIndex;
    }
}

void Heap :: insert(int data) {
    heap.push_back(data);
    bubbleUp();
}

void Heap :: remove() {
    if (heap.size() == 0) {
        return;
    }

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    bubbleDown();
}

int main() {
    return 0;
}