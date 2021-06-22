#include <bits/stdc++.h>

using namespace std;

// recursive
int canPart(vector <int> &num, int i, int one, int two) {
    if (i == num.size()) {
        return abs(one - two);
    }
    int addOne = canPart(num, i + 1, one + num[i], two);
    int addTwo = canPart(num, i + 1, one, two + num[i]);

    return min(addOne, addTwo);
}

// top down
int canPartTD(vector <int> &num, int i, int one, int two, vector <vector <int>> dp) {
    if (i == num.size()) {
        return abs(one - two);
    }

    if (dp[i][one] == -1) {
        int addOne = canPartTD(num, i + 1, one + num[i], two, dp);
        int addTwo = canPartTD(num, i + 1, one, two + num[i], dp);

        dp[i][one] = min(addOne, addTwo);
    }
    
    return dp[i][one];
}

int canPartition(vector<int> &num) { 
    return canPart(num, 0, 0, 0); 
}


int main(int argc, char *argv[]) {
    vector<int> num = {1, 2, 3, 9};
    cout << canPartition(num) << endl;
    num = vector<int>{1, 2, 7, 1, 5};
    cout << canPartition(num) << endl;
    num = vector<int>{1, 3, 100, 4};
    cout << canPartition(num) << endl;
}
