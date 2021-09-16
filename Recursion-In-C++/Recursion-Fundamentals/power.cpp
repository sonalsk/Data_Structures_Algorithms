// The task is to calculate x power n
#include <bits/stdc++.h>

using namespace std;

int power(int x, int n) {
    if (n == 1) {
        return x;
    }
    return x * power(x, n - 1);
}

int main() {
    int x = 2, n = 3;
    cout << power(2, 3) << endl;
    return 0;
}