#include <iostream>

using namespace std;

void traverse(int array[], int n) {
    // Linear time taken
    // O(2 + n), we ignore the constants
    // Therefore, O(n)
    cout << 1 << endl; //O(1)
    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; //O(n)
    }
    cout << 1 << endl; //O(n)
}

void traverse_twice(int array[], int n) {
    // Linear time taken
    // O(n + n) = O(2n), we ignore the constants
    // Therefore, O(n)
    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; //O(n)
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; //O(n)
    }
}

void traverse_different(int array[], int n, string strings[], int m) {
    // Linear time taken
    // O(n + m), we consider linear
    // Therefore, O(n)
    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; //O(n)
    }

    for (int i = 0; i < m; i++) {
        cout << strings[i] << " "; //O(m)
    }
}