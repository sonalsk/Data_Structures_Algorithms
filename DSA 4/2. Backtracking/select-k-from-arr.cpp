#include <bits/stdc++.h>

using namespace std;

void print(vector <int> arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

// accept and reject integers
void getCombinations(vector <int> arr, int k, unordered_set <int> comb, int curr) {
    if (comb.size() == k) {
        for (auto itr: comb) {
            cout << itr << " ";
        }
        cout << endl;
        return;
    }
    
    if (curr == arr.size()) {
        return;
    }

    comb.insert(arr[curr]);
    getCombinations(arr, k, comb, curr + 1);
    comb.erase(arr[curr]);
    getCombinations(arr, k, comb, curr + 1);
}

// elements after start
void getCombination(vector <int> arr, int k, unordered_set <int> used, int start) {
    if (used.size() == k) {
        for (auto itr: used) {
            cout << itr << " ";
        }
        cout << endl;
        return;
    }

    if (start == arr.size()) {
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        used.insert(arr[i]);
        getCombination(arr, k, used, i + 1);
        used.erase(arr[i]);
    }
}

// dont take used
void getCombinations(vector <int> arr, int k, vector <int> comb, vector <bool> used) {
    if (comb.size() == k) {
        print(comb);
        return;
    }

    int i = 0;
    while (i < arr.size()) {
        if (!used[i]) {
            comb.push_back(arr[i]);
            used[i] = true;
           
            getCombinations(arr, k, comb, used);
           
            comb.pop_back();
        }
        i++;
    }
    used[i] = false;
}

void getCombinations(vector <int> arr, int k) {
    vector <int> comb;
    unordered_set <int> use;
    vector <bool> used(arr.size(), false);
    getCombinations(arr, k, use, 0);
}

int main() {
    vector <int> arr = {3, 2, 5, 8};
    int k = 3;
    getCombinations(arr, k);
    return 0;
}