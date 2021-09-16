#include <bits/stdc++.h>

using namespace std;

int modulo(int divs, int divid) {
    if (divid == 0) {
        return 0;
    }
    if (divs < divid) {
        return divs;
    }
    return modulo(divs - divid, divid);
}

int main() {
    int divisor = 27, dividend = 3;
    cout << modulo(divisor, dividend) << endl;
    return 0;
}