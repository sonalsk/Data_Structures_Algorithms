#include <bits/stdc++.h>

using namespace std;

void print(vector <int> perm) {
    for (int i: perm) {
        cout << i << " ";
    }
    cout << endl;
}

void getPermu(vector <int> arr, vector <int> perm, vector <bool> used) {
    if (perm.size() == arr.size()) {
        print(perm);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (!used[i]) {
            perm.push_back(arr[i]);
            used[i] = true;        
            
            getPermu(arr, perm, used);
            
            perm.pop_back();
            used[i] = false;
        }
    }
}

void getPermu(vector <int> arr, vector <int> perm) {
    if (arr.empty()) {
        print(perm);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        perm.push_back(arr[i]);
        
        vector <int> mini;
        for (int j = 0; j < arr.size(); j++) {
            if (j != i) {
                mini.push_back(arr[j]);
            }
        }
        
        getPermu(mini, perm);
        perm.pop_back();
    }
}

void getPermu(vector <int> arr) {
    vector <int> perm;
    vector <bool> used(arr.size(), false);
    getPermu(arr, perm, used);
}

int main() {
    vector <int> arr = {1, 2, 3};
    getPermu(arr);
    return 0;
}