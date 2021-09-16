#include <bits/stdc++.h>

using namespace std;

void bubbleSortRec(vector <int>& v, int i, int j) {
    if (i > v.size() - 1) {
        return;
    }
    if (j >= v.size() - 1 - i) {
        bubbleSortRec(v, i + 1, 0);
        return;
    }
    if (v[j] > v[j + 1]) {
        int temp = v[j + 1];
        v[j + 1] = v[j];
        v[j] = temp;        
    }
    bubbleSortRec(v, i, j + 1);
}

void bubbSort(vector <int> &v) {
    bubbleSortRec(v, 0, 0);
}

int main() {
    vector <int> v = {5, 4};
    bubbSort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}