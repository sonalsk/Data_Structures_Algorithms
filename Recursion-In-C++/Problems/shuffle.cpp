#include <bits/stdc++.h>

using namespace std;

void shuffleRec(int * a, int n, int i, int j) {
    if (j >= n || i >= n) {
        return;
    }
    int store = a[j], k = j;
    for (k = j; k > (i + 1); k--) {
        a[k] = a[k - 1];
    }
    a[k] = store;

    shuffleRec(a, n, i + 2, j + 1);
}

void shuffler(int a[], int n){
    shuffleRec(a, n, 0, n / 2);
}

int main() {
    int n = 8;
    int a[n] = {1, 2, 3, 4, 1, 2, 3, 4};
    shuffler(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}