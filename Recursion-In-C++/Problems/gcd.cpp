#include <bits/stdc++.h>

using namespace std;

int gcd(int num1, int num2) {
    if (num1 == num2) {
        return num1;
    }
    if (num1 > num2) {
        return gcd(num1 - num2, num2);
    }
    return gcd(num1, num2 - num1);
}

int main() {
    int a = 24;
    int b = 18;
    cout << gcd(24, 18) << endl;
    return 0;
}