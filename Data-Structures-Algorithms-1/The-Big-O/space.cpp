#include <iostream>

using namespace std;

void string_display(string names[], int n) {
    // O(1) Space because only one i is there 
    for (int i = 0; i < n; i++) {
        cout << "Hi " << names[i] << endl; 
    }
}

void string_store(string names[], int n) {
    // O(n) Space because we are copying
    string copy_string[n]; 
    for (int i = 0; i < n; i++) {
        cout << "Hi " << names[i] << endl; 
    }
}