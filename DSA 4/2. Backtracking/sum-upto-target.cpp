#include <bits/stdc++.h>

using namespace std;

void print(vector <int> arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

void getSumUpto(vector <int> nums, int target, int start, vector <int> seq) {
    if (target < 0) {
        return;
    }
    if (target == 0) {
        print(seq);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        seq.push_back(nums[i]);
        getSumUpto(nums, target - nums[i], i + 1, seq);
        seq.pop_back();
    }
}

void getSumUpto(vector <int> nums, int target) {
    vector <int> seq;
    unordered_set <int> visited;
    sort(nums.begin(), nums.end());
    getSumUpto(nums, target, 0, seq);
}

int main() {
    vector <int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    getSumUpto(nums, target);
    return 0;
}