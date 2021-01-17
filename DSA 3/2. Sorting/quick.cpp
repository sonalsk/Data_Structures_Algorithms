#include <iostream>

using namespace std;

void swap(int arr[], int boundary, int i) {
    int temp = arr[boundary];
    arr[boundary] = arr[i];
    arr[i] = temp;
}

int partition (int arr[], int n, int start, int end) {
    int pivot = arr[end];
    int boundary = start - 1;

    for (int i = start; i <= end; i++) {
        if (arr[i] <= pivot) {
            boundary++;
            swap(arr, boundary, i);
        }
    }

    return boundary;
}

void quickSort(int arr[], int n, int start, int end) {

    if (start >= end) {
        return;
    }

    int boundary = partition (arr, n, start, end);
    quickSort(arr, n, start, boundary - 1);
    quickSort(arr, n, boundary + 1, end);
    
}

void quickSort(int arr[], int n) {
    quickSort(arr, n, 0, n - 1);
}


int main() {
    int n = 6;
    int arr[n] = {7, 3, 1, 5, 1, 2};
    quickSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}