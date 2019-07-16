//https://leetcode.com/problems/n-queens/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bitset<30> d1;
 bitset<30> d2;
 bitset<30> c;
vector<pair<int,int>> cood;
bool Queenhelper(int i, int n)
{
    if(i==n){
        return true;
    }
    for(int j=0;j<n;j++){
        if(c[j]==0 && d2[i+j]==0 && d1[i+j-1+n]==0) {
            c[j] = 1;  
            d2[i + j] = 1;
            d1[i + j - 1 + n ] = 1;
            cood.push_back(pair(i,j));
            bool CanSolve=Queenhelper(i + 1, n);
            if(CanSolve) return true;
            else{
            c[j] = 0;
            d2[i + j] = 0;
            d1[i + j - 1 + n] = 0;
            cood.pop_back();
            }
        }

    }
}

    vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> board(n,vector<string>(n,"."));
    Queenhelper(0,n);
    for(auto i:cood){
        board[i.first][i.second]="Q";
    }
    return board;
}