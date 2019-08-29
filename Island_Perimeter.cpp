//https://leetcode.com/problems/island-perimeter/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int get_perimeter(vector<vector<int>> grid,int i,int j,int r,int c){
    int cell_boundary;
    if(i-1<0 || grid[i-1][j]==0) cell_boundary++;
    if(i+1>=r || grid[i+1][j]==0) cell_boundary++;
    if(j-1<0 ||  grid[i][j-1]==0) cell_boundary++;
    if(j+1>=c || grid[i][j+1]==0) cell_boundary++;
    return cell_boundary;
}
int islandPerimeter(vector<vector<int>> &grid)
{
    if(grid.size()==0) return 0;
    int r=grid.size();
    int c=grid[0].size();
    int perimeter=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]){
                perimeter+=get_perimeter(grid,i,j,r,c);
            }
        }
    }
    return perimeter;
}