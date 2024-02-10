#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>> &board, char c, int i, int j)
{
    bool ret = true;
    for (int k = 0; k < board.size(); k++)
    {
        if ((board[i][k] == c) && (k != j) && (c != '.'))
        {
            ret = false;
        }
    }
    for (int k = 0; k < board.size(); k++)
    {
        if ((board[k][j] == c) && (k != i) && (c != '.'))
        {
            ret = false;
        }
    }
    int ii = i;
    int jj = j;
    i = i / 3;
    i *= 3;
    j = j / 3;
    j *= 3;
    // cout << i << " " << j << endl;
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if ((board[k + i][l + j] == c) && (k + i != ii) && (l + j != jj) && (c != '.'))
            {
                ret = false;
            }
        }
    }
    return ret;
}

bool solution(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (int k = 1; k <= 9; k++)
                {
                    string temp = to_string(k);
                    if (check(board, temp[0], i, j))
                    {
                        board[i][j] = temp[0];
                        if (solution(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solution(board);
}
