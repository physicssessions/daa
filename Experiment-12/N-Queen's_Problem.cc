#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col, int N) {
    if (col >= N) return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1, N)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ() {
    int n;
    cout << "Enter size of board (n): ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solveNQUtil(board, 0, n)) {
        cout << "Solution does not exist\n";
        return false;
    }
    printSolution(board, n);
    return true;
}

int main() {
    solveNQ();
    return 0;
}

/*
Sample Output:
Enter size of board (n): 4
. Q . . 
. . . Q 
Q . . . 
. . Q . 
*/
