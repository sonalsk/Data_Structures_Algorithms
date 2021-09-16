#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n, int i) {
    if (n < 2) {
        return false;
    }
    if (i == 1) {
      return true;
    }
    if (n % i == 0) {
        return false;
    }
    else {
        return isPrime(n, i - 1);
    }
    return 0;
}

int testPrime(int num) {
    // all the factors of a number are less than or equal to half of that number
    int prime = isPrime(num, num / 2);
    return prime;
}

int main() {
    int n = 2;
    cout << testPrime(n) << endl;
    return 0;
}