//https://leetcode.com/problems/search-a-2d-matrix-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        if(r==0) return 0;
        int c=matrix[0].size();
        int i=0;
        int j=c-1;
        while(i<r and j>=0){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target){
                j--;
            }
            else if(matrix[i][j]<target){
                i++;
            }
        }
return false;}