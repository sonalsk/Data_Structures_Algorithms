#include <iostream>

using namespace std;

void pairs(int array[], int n) {
    //quadratic time
    // O(n^2)
    for (int i = 0; i < n; i++) { //O(n)
        for (int j = 0; j < n; j++) { //O(n)
            cout << i << " " << j << endl;
        }
    }
}

void pairs_linear(int array[], int n) {
    //quadratic time
    // O(n + n^2)
    // We ignore the smaller terms
    // O(n^2)
    for (int j = 0; j < n; j++) { //O(n)
        cout << j << endl;
    }

    for (int i = 0; i < n; i++) { //O(n)
        for (int j = 0; j < n; j++) { //O(n)
            cout << i << " " << j << endl;
        }
    }
}

void triples(int array[], int n) {
    //quadratic time
    // O(n^3)
    for (int i = 0; i < n; i++) { //O(n)
        for (int j = 0; j < n; j++) { //O(n)
            for (int k = 0; k < n; k++) { //O(n)
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
}