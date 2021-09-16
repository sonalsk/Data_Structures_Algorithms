#include <bits/stdc++.h>

using namespace std;

bool BSearch(int *arr, int ele, int start, int end) {
    
    if (start > end) {
        return false;
    }
    
    int mid = (start + end) / 2;
    if(arr[mid] == ele) {
        return true;
    }
    else if (arr[mid] > ele) {
        return BSearch(arr, ele, start, mid - 1);
    }
    else {
        return BSearch(arr, ele, mid + 1, end);
    }
    return false;
}

bool binarySearch(int *arr, int ele, int n) {
    return BSearch(arr, ele, 0, n);
}

int main() {
    int n = 6;
    int arr[n] = {1, 2, 3, 4, 5, 6};
    int ele = 6;

    if (binarySearch(arr, ele, n)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}