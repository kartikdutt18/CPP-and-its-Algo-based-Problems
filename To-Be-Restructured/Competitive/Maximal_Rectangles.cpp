//https://leetcode.com/problems/maximal-rectangle/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void filldp_array(vector<vector<char>> matrix, vector<vector<int>> &dp){
    for(int i=0;i<matrix[0].size();i++) dp[0][i]=matrix[0][i]-'0';
    for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if (matrix[i][j] != '0')
                dp[i][j] = dp[i - 1][j] + 1;
            else
                dp[i][j] = matrix[i][j] - '0';
        }
    }
}
int largestRectangleArea(vector<int> &heights)
{
    stack<long long int> s;
    long long int max_area = 0;
    long long int cur_area = 0;
    long long int cnt = 0;

    while (cnt < heights.size())
    {
        if (s.empty() || heights[s.top()] <= heights[cnt])
        {
            s.push(cnt++);
        }
        else
        {
            long long int top_ind = s.top();
            s.pop();
            long long int w = s.empty() ? cnt : cnt - s.top() - 1;
            cur_area = heights[top_ind] * w;
            max_area = max(cur_area, max_area);
        }
    }
    while (!s.empty())
    {
        long long int tp = s.top();
        s.pop();
        long long int w = s.empty() ? cnt : cnt - s.top() - 1;
        cur_area = heights[tp] * w;
        max_area = max(max_area, cur_area);
    }
    return max_area;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if(matrix.size()==0) return 0;
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
    filldp_array(matrix,dp);
    int cur_ans=0,max_area=0;
    for(auto j :dp){
        cur_ans = largestRectangleArea(j);
        max_area=max(cur_ans,max_area);
    }
    return max_area;
}