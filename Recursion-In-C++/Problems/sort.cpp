#include<iostream>
using namespace std;

//Recursive function to sort the array
void SortArray(int * numbers, int i, int n) {

    if (i == n - 1) {
        return;
    }
    
    for (int j = 0; j < n - 1 - i; j++) {
        if (numbers[j] > numbers[j + 1]) {
            swap(numbers[j], numbers[j + 1]);
        }
    } 
    
    SortArray(numbers, i + 1, n);
}

void printSortArray(int *numbers, int size)
{
  //call SortArray
    SortArray(numbers, 0, size);
    for (int i=0;i<size;i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[1] = {1};
    printSortArray(arr, 1);
    return 0;
}