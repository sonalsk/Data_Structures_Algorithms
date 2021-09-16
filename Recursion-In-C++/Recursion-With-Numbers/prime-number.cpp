#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n, int k) {
    if (n == 2) {
        return true;
    }
    if (k*k <= n) {
        return isPrime(n, k + 1);
    }
    if (n % k == 0) {
        return false;
    }
    return true;
}

int main() {
    int n = 12;
    if (isPrime(n, 3)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}