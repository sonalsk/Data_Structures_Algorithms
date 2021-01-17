#include <iostream>

using namespace std;

int ternarySearchRecP(int arr[], int low, int high, int item) {
    if (high < low) {
        return -1;
    }

    int partitionSize = (high - low) / 3;
    int mid1 = low + partitionSize;
    int mid2 = high - partitionSize;

    if (item == arr[mid1]) {
        return mid1;
    }

    if (item == arr[mid2]) {
        return mid2;
    }
    if (item < arr[mid1]) {
        return ternarySearchRecP(arr, low, mid1 - 1, item);
    }
    else if (item > arr[mid2]) {
        return ternarySearchRecP(arr, mid2 + 1, high, item);
    }
    return ternarySearchRecP(arr, mid1 + 1, mid2 - 1, item);
}

int ternarySearchRec(int arr[], int n, int item) {
    return ternarySearchRecP(arr, 0, n - 1, item);
}


int ternarySearch(int arr[], int n, int item) {
    
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int partitionSize = (right - left) / 3;
        int mid1 = left + partitionSize;
        int mid2 = right - partitionSize;

        if (item == arr[mid1]) {
            return mid1;
        }
        else if (item == arr[mid2]) {
            return mid2;
        }
        else if (item < arr[mid1]) {
            right = mid1 - 1;
        }
        else if (item > arr[mid2]) {
            left = mid2 + 1;
        }
        else if(item > arr[mid1] && item < arr[mid2]) {
            left = mid1 + 1;
            right = mid2 - 1;
        } 
    }
    return -1;
}

int main() {
    int n = 5;
    int arr[n] = {1, 3, 5, 6, 7};

    int index = ternarySearchRec(arr, n, 5);
    cout << index << endl;
}