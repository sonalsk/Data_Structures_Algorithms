#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {

        int currIndex = i;
        int curr = arr[i];
        while (currIndex > 0 && curr < arr[currIndex - 1]) {
            arr[currIndex] = arr[currIndex - 1];
            currIndex--;
        }

        arr[currIndex] = curr;
    }
}

int main() {
    int n = 5;
    int arr[n] = {8, 2, 4, 3, 1};

    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}