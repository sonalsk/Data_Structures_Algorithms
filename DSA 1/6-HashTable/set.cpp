#include <iostream>
#include <set>

using namespace std;

int main() {
    set <int> unique_nums;
    set <int>::iterator itr;
    int arr[5] = {1, 2, 2, 3, 4};

    for (int i: arr) {
        unique_nums.insert(i);
    }

    for (itr = unique_nums.begin(); itr != unique_nums.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;


    return 0;
}