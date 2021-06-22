#include <bits/stdc++.h>

using namespace std;

void getPass(int i, int pass) {
    if (i == 0) {
        cout << pass << " ";
        return;
    }

    for (int j = 1; j <= 9; j++) {
        pass = pass * 10 + j;
        getPass(i - 1, pass);
        pass = pass / 10;
    }
    
    return;
}

void getPass(int l) {
    getPass(l, 0);
    cout << endl;
}

int main() {
    int l = 2;
    getPass(l);
    return 0;
}