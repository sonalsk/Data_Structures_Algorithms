#include <bits/stdc++.h>

using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int getPivot(int *arr, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int part = getPivot(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

int main() {
    int n = 5;
    int arr[n] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}
