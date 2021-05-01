#include <bits/stdc++.h>

using namespace std;

int sumDigits(int n) {
    if (n <= 0) {
        return n;
    }
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n = 123456;
    cout << sumDigits(n) << endl;
    return 0;
}