#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int item) {
    if (high < low) {
        return -1;
    }

    int mid = (low + high) / 2;
    
    if (item == arr[mid]) {
        return mid;
    }

    if (item < arr[mid]) {
        return binarySearch(arr, low, mid - 1, item);
    }

    return binarySearch(arr, mid + 1, high, item);
}

int binarySearchRec(int arr[], int n, int item) {
    return binarySearch(arr, 0, n - 1, item);
}

int binarySearch(int arr[], int n, int item) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // int mid = (left + right) / 2;
        int mid = left + (right - left) / 2;

        if (item == arr[mid]) {
            return mid;
        }
        else if (item < arr[mid]) {
            right = mid - 1;
        }
        else if (item > arr[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n = 5;
    int arr[n] = {1, 3, 4, 5, 6, 7};

    int index = binarySearchRec(arr, n, 6);
    cout << index << endl;
}