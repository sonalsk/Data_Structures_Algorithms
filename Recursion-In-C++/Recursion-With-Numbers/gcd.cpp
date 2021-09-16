#include <bits/stdc++.h>

using namespace std;

int getGCD(int num1, int num2, int k) {
    if (k == 1) {
        return k;
    }
    if (num1 % k == 0 && num2 % k == 0) {
        return k;
    }
    return getGCD(num1, num2, k - 1);
}
int gcd(int num1, int num2) {
    int k = num1 < num2 ? num1 : num2;
    return getGCD(num1, num2, k);
}

int gcdSoln(int num1, int num2) {
    if (num1 == num2) {
        return num1;
    }
    else if (num1 > num2) {
        return gcdSoln(num1 - num2, num2);
    }
    else {
        return gcdSoln(num1, num2 - num1);
    }
}

int main() {
    int n = 56, m = 42;
    cout << gcdSoln(n, m) << endl;
    return 0;
}