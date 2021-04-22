#include <bits/stdc++.h>

using namespace std;

void swapIndex(int fst, int snd, int arr[]) {
    int temp = arr[fst];
    arr[fst] = arr[snd];
    arr[snd] = temp;
}

void heapifyElement(int i, int arr[], int n) {
    int leftChild = (i * 2) + 1;
    int rightChild = (i * 2) + 2;

    int largerIndex = i;

    if (leftChild < n && arr[i] < arr[leftChild]) {
        largerIndex = leftChild;
    }
    if (rightChild < n && arr[i] < arr[rightChild]) {
        largerIndex = rightChild;
    }

    if (i == largerIndex) {
        return;
    }

    swapIndex(i, largerIndex, arr);
    heapifyElement(largerIndex, arr, n);
}

void heapify(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        heapifyElement(i, arr, n);
    }
}

int main() {
    int n = 6;
    int arr[n] = {5, 3, 8, 9, 1, 2};
    heapify(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}