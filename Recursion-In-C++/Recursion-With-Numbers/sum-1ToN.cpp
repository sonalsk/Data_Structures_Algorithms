#include <bits/stdc++.h>

using namespace std;

int sumUptoN(int n) {
    if (n == 0) {
        return n;
    }
    return n + sumUptoN(n - 1);
}

int main() {
    int n = 6;
    cout << sumUptoN(n) << endl;
    return 0;
}