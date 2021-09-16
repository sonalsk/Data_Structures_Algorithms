#include <bits/stdc++.h>

using namespace std;

int nthFibo(int n) {
    if (n <= 1) {
        return n;
    }
    return nthFibo(n - 1) + nthFibo(n - 2);
}

int main() {
    int n = 8;
    for (int i = 0; i <= n; i++) {
        cout << nthFibo(i) << " ";
    }
    cout << endl;
    return 0;
}