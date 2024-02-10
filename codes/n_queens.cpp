#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> strvecc;
vector<vector<string>> solveNQueens(int n)
{
    vector<string> one(n, string(n, '.'));
    backtrack(one, 0);
    return strvecc;
}
bool attack(vector<string> &one, int row, int col)
{
    int n = one.size();
    for (int i = 0; i < n; i++)
    {
        if (one[i][col] == 'Q')
            return true;
        if (row - i >= 0 && col - i >= 0 && one[row - i][col - i] == 'Q')
            return true;
        if (row - i >= 0 && col + i < n && one[row - i][col + i] == 'Q')
            return true;
        if (row + i < n && col - i >= 0 && one[row + i][col - i] == 'Q')
            return true;
        if (row + i < n && col + i < n && one[row + i][col + i] == 'Q')
            return true;
    }
    return false;
}
void backtrack(vector<string> &one, int row)
{
    if (row == one.size())
    {
        strvecc.push_back(one);
        return;
    }
    for (int col = 0; col < one.size(); col++)
    {
        if (!(attack(one, row, col)))
        {
            one[row][col] = 'Q';
            backtrack(one, row + 1);
            one[row][col] = '.';
        }
    }
}