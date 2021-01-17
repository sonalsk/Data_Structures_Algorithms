#include <iostream>
#include <climits>

using namespace std;

void swap (int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {

        int minIndex = i;
        
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr, i, minIndex);
    }
}

int main() {
    int n = 5;
    int arr[n] = {8, 2, 4, 1, 3};

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}