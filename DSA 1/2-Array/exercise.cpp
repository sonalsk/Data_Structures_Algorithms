#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int findLargest(int arr[], int n) {
    if (n == 0) {
        return -1;
    }

    int largestNum = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largestNum) {
            largestNum = arr[i];
        }
    }
    
    return largestNum;
}

vector <int> getCommonItems(int arr[], int n) {
    set <int> uniqueItems;
    vector <int> commonItems;

    for (int i = 0; i < n; i++) {
        if (uniqueItems.find(arr[i]) != uniqueItems.end()) {
            commonItems.push_back(arr[i]);
        }
        uniqueItems.insert(arr[i]);
    }

    return commonItems;
}


int main() {
    int n = 7;
    int arr[n] = {1, 2, 3, 4, 5, 2, 1};

    int largestNum = findLargest(arr, n);
    cout << largestNum << endl;

    vector <int> commonItems;
    commonItems = getCommonItems(arr, n);

    for (int i = 0; i < commonItems.size(); i++) {
        cout << commonItems[i] << " ";
    }
    cout << endl;

    reverse(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}