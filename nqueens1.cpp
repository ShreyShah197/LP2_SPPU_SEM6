#include <bits/stdc++.h>
using namespace std;


bool isSafe(int row, int col, vector<bool> rows, vector<bool> ld, vector<bool> rd,int n)
{
    if (rows[row] == true || ld[row + col] == true || rd[col - row + n - 1] == true)
    {
        return false;
    }
    return true;
}

void print(vector<vector<char>> &board, int n)
{
    cout << "Solution : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void solve(vector<vector<char>> &board, int cols, vector<bool> rows, vector<bool> ld, vector<bool> rd, int n)
{
    if (cols >= n)
    {
        print(board,n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, cols, rows, ld, rd,n))
        {
            rows[i] = true;
            ld[i + cols] = true;
            rd[cols - i + n - 1] = true;
            board[i][cols] = 'Q';
            // now go to next column
            solve(board, cols + 1, rows, ld, rd,n);
            // backtrack
            rows[i] = false;
            ld[i + cols] = false;
            rd[cols - i + n - 1] = false;
            board[i][cols] = '-';
        }
    }
}



int main()
{
    cout << "Enter N : " << endl;
    int n;
    cin >> n;
    if (n == 2 || n == 3)
    {
        cout << "No Solution" << endl;
        return 0;
    }
   
    vector<vector<char>> board(n, vector<char>(n, '-'));
    vector<bool> rows(n, false);
    vector<bool> ld(2 * n - 1, false);
    vector<bool> rd(2 * n - 1, false);
    solve(board, 0, rows, ld, rd, n);
    return 0;
}