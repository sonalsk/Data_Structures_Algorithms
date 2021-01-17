#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    int index = linearSearch(arr, n, 4);
    cout << index << endl;
}