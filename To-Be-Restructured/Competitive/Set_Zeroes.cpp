//CTCI 1.8
//https://leetcode.com/problems/set-matrix-zeroes/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    set<int> rows;
    set<int> columns;        
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                rows.emplace(i);
                columns.emplace(j);
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(rows.count(i) || columns.count(j)) matrix[i][j]=0;
        }
    }
return ;}