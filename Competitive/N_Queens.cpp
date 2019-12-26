//https://leetcode.com/problems/n-queens/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bitset<30> d1;
bitset<30> d2;
bitset<30> c;
vector<pair<int,int>> cood;
vector<vector<string>> board;
void fill_board(vector<pair<int,int>> coods,int n){
    vector<string> board2(n, string(n, '.'));
    for (auto i : coods)
    {
        board2[i.first][i.second] = 'Q';
    }
    board.push_back(board2);
}
bool Queenhelper(int i, int n)
{
    if (i == n)
    {
        fill_board(cood,n);
        
        return false;
    }
    for (int j = 0; j < n; j++)
    {
        if (c[j] == 0 && d2[i + j] == 0 && d1[i - j + n - 1] == 0)
        {
            c[j] = 1;
            d2[i + j] = 1;
            d1[i - j - 1 + n] = 1;
            cood.push_back(pair(i, j));
            bool CanSolve = Queenhelper(i + 1, n);
            if (CanSolve)
                return true;
            else
            {
                c[j] = 0;
                d2[i + j] = 0;
                d1[i - j - 1 + n] = 0;
                cood.pop_back();
            }
        }
    }
    return false;
}

vector<vector<string>> solveNQueens(int n)
{
    
    Queenhelper(0, n);
   
    return board;
}