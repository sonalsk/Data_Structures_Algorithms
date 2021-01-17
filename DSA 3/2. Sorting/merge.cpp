#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int> left, vector <int> right, vector <int> &result) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result[k++] = left.at(i++);
        }
        else {
            result[k++] = right.at(j++);
        }
    }

    while (i < left.size()) {
        result[k++] = left[i++];
    }

    while (j < right.size()) {
        result[k++] = right[j++];
    }
}

void mergeSort(vector <int> &arr) {

    if (arr.size() < 2) {
        return;
    }

    int mid = arr.size() / 2;

    vector <int> left;
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    vector <int> right;
    for (int i = mid; i < arr.size(); i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left);
    mergeSort(right);

    merge(left, right, arr);

}

int main() {
    
    vector <int> arr;
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(3);
    
    mergeSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}