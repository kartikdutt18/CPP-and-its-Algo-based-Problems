//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Doest Work
//Priority Queue Solution Used for this problem.
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int i=0,j=0;
    while(--k){
        if(i!=matrix.size()-1 && j!=matrix.size()){
            if(matrix[i+1][j]>matrix[i][j+1]) j++;
            else i++;
        }
        else if (i == matrix.size() - 1 && j != matrix.size() - 1)
        {
            if(matrix[i-1][j]<=matrix[i][j+1]) i--;
            else j++;
        }
        else{
            if(matrix[i][j-1]<=matrix[i+1][j]) j--;
            else i++;
        }
    }
    return matrix[i][j];
}