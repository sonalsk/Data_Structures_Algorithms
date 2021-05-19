#include <bits/stdc++.h>

using namespace std;

// recursion - o(3^(max(a, b)))
int editDist(string a, string b, int i, int j) {
    if (i == -1) {
        return j + 1;
    }
    if (j == -1) {
        return i + 1;
    }

    if (a[i] == b[j]) {
        return editDist(a, b, i - 1, j - 1);
    }
    else {
        int addA = editDist(a, b, i, j - 1);
        int replaceA = editDist(a, b, i - 1, j - 1);
        int removeA = editDist(a, b, i - 1, j);

        return 1 + min(min(addA, replaceA), removeA);
    }
}

// top down
int editDistTD(string a, string b, int i, int j, vector <vector <int>> dp) {
    if (i == -1) {
        return j + 1;
    }
    if (j == -1) {
        return i + 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    if (a[i] == b[j]) {
        dp[i][j] = editDistTD(a, b, i - 1, j - 1, dp);
        return dp[i][j];
    }
    else {
        int addA = editDistTD(a, b, i, j - 1, dp);
        int replaceA = editDistTD(a, b, i - 1, j - 1, dp);
        int removeA = editDistTD(a, b, i - 1, j, dp);

        dp[i][j] = 1 + min(min(addA, replaceA), removeA);
        return dp[i][j];
    }
}

// bottom up - O(a * b)
int editDistBU(string a, string b) {
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, -1));
    
    for (int i = 0; i < a.length() + 1; i++) {
        for (int j = 0; j < b.length() + 1; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int add = dp[i][j - 1];
                    int replace = dp[i - 1][j - 1];
                    int remove = dp[i - 1][j];
                    dp[i][j] = 1 + min(min(add, replace), remove);
                }
            }
        }
    }
    return dp[a.length()][b.length()];
}

void editDistance(string a, string b) {
    cout << editDist(a, b, a.length() - 1, b.length() - 1) << endl;
    vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1));
    cout << editDistTD(a, b, a.length() - 1, b.length() - 1, dp) << endl;
    cout << editDistBU(a, b) << endl;
}

int main() {
    string a = "horse";
    string b = "ros";
    editDistance(a, b);
    return 0;
}