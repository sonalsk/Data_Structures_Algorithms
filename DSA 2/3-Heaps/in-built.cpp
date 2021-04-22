#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    vector<int> vi = { 4, 6, 7, 9, 11, 4 }; 
    make_heap(vi.begin(), vi.end());

    return 0;
}