#include <bits/stdc++.h>

using namespace std;

int jumpSearch(vector <int> arr, int target) {
    int n = arr.size();
    int blockSize = sqrt(n);

    int start = 0;
    int end = (start + blockSize) > n ? n : (start + blockSize);

    while (start < n && arr[end - 1] < target) {
        start = end;
        end = (start + blockSize);
        end = end > n ? n : end;        
    }

    for (int i = end; i >= start; i--) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector <int> arr = {3, 5};
    int target = 5;
    
    int index = jumpSearch(arr, target);
    cout << index << endl;

    return 0;
}