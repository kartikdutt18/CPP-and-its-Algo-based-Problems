//https://leetcode.com/problems/pascals-triangle-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> getRow(int row)
{
    if(row==1) return {1};
    vector<int> rows={1,1};
    for(int i=3;i<row;i++){
        vector<int> temp(i,1);
        for(int j=0;j<rows.size()-1;j++){
            temp[j+1]=rows[j]+rows[j+1];
        }
        rows=temp;
    }
    return rows;
}