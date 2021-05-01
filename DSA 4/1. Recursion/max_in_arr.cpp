#include <bits/stdc++.h>

using namespace std;

int getMax(vector <int> arr, int i) {
    if (i == arr.size() - 1) {
        return arr[i];
    }
    return max(arr[i], getMax(arr, i + 1));
}

int getMax(vector <int> arr) {
    if (arr.size() == 0) {
        return 0;
    }
    return getMax(arr, 0);
}

int main() {
    vector <int> arr = {-3};
    int max_in_arr = getMax(arr);
    cout << max_in_arr << endl;
}