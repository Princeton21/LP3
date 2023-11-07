#include <bits/stdc++.h>
using namespace std;

// N queens problem
// TC - O(n!*n)
// SC - O(n)

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperDiag, vector<int> &lowerDiag, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0)
        {

            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;

            solve(col + 1, board, ans, leftrow, upperDiag, lowerDiag, n); // backtracking

            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    vector<int> leftrow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiag, lowerDiag, n);
    return ans;
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    cout << "Total possible arrangements : " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        break;
        cout << endl;
    }
}

int main()
{
    solve();
}