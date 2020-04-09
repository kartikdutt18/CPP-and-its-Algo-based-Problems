// https: //leetcode.com/problems/triangle/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(N**2) / O(1)
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int i = 1; i < triangle.size(); i++)
        {
           
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j > 0 && j != triangle[i].size() - 1)
                {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
                else if (j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
            }
        }
        int ans = INT_MAX;
        for (auto i : triangle.back())
        {
            ans = min(ans, i);
        }
        return ans;
    }
};

// O(N**2) / O(N)
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        for(int i=1;i<triangle.size();i++)
        {
            triangle[i-1].push_back(INT_MAX);
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j>0)
                {
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                
                }
                else
                {
                    triangle[i][j]+=triangle[i-1][j];
                }
                
            }
          
        }
        int ans=INT_MAX;
        for(auto i:triangle.back())
        {
            ans=min(ans,i);
        }                
    return ans;}   
};