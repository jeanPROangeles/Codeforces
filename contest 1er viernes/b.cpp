#include <bits/stdc++.h>
using namespace std;

const int moves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

bool isValidConfiguration(vector<string>& board) {
    int knightCount = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == 'k') {
                knightCount++;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + moves[k][0];
                    int nj = j + moves[k][1];
                    if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && board[ni][nj] == 'k') {
                        return false; 
                    }
                }
            }
        }
    }
    return knightCount == 9; 
}

int main() {
    vector<string> board(5);
    for (int i = 0; i < 5; ++i) {
        cin >> board[i];
    }

    if (isValidConfiguration(board)) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}
