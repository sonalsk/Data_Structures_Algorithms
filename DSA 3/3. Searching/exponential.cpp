#include <bits/stdc++.h>

using namespace std;

int exponentialSearch(vector <int> arr, int target) {
    int n = arr.size();
    int bound = 1;

    while (bound < n && arr[bound] < target) {
        bound = bound * 2;
    }

    int start = bound / 2;
    int end = min(bound, n - 1);

    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }

        if (target < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector <int> arr = {3, 5, 6, 9, 11, 18, 20, 21, 24, 30};
    int target = 21;
    int index = exponentialSearch(arr, target);
    cout << index << endl;
    return 0;
}