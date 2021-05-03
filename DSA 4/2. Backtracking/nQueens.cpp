#include <bits/stdc++.h>

using namespace std;

void print(vector <vector <int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(vector <vector<int>> board, int r, int c) {
    // vertical
    for (int i = 0; i < r; i++) {
        if (board[i][c] == 1) {
            return false;
        }
    }

    // left diagonal
    int left = min(r, c);
    for (int i = 1; i <= left; i++) {
        if (board[r - i][c - i] == 1) {
            return false;
        }
    }

    // right diagonal
    int t = board.size() - c - 1;
    int right = min(r, t);
    for (int i = 1; i <= right; i++) {
        if (board[r - i][c + i] == 1) {
            return false;
        }
    }
    
    return true;
}

void placeQueens(vector <vector<int>> board, int r) {
    if (r == board.size()) {
        print(board);
        cout << endl;
        return;
    }

    for (int c = 0; c < board[0].size(); c++) {
        if (canPlace(board, r, c)) {
            board[r][c] = 1;
            placeQueens(board, r + 1);
            board[r][c] = 0;
        }
    }
}

void nQueens(vector <vector <int>> board) {
    placeQueens(board, 0);
}


int main() {
    int n = 4;
    vector <vector <int>> board(n, vector<int> (n, 0));
    nQueens(board);

    return 0;
}