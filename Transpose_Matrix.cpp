//https://leetcode.com/problems/transpose-matrix/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r=A.size();
        if(r==0) return A;
        int c=A[0].size();
        //Inplace only if square matrix
        //Hence Created a new matrix
        vector<vector<int>> ans(c,vector<int>(r,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                //To transpose a matrix rows and columns are interchanged
                ans[j][i]=A[i][j];
            }
        }
return ans;}