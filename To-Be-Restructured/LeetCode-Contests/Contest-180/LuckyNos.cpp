#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Method 1 : O(m*(m+n)) / O(1)
vector<int> luckyNumbers (vector<vector<int>>& matrix)
{
  vector<int> ans;
  for(int i=0;i<matrix.size();i++)
  {
    int minCol = min_element(matrix[i].begin(),matrix[i].end()) - matrix[i].begin();
    int maxRow=0;
    int curMax = INT_MIN;
    for(int j = 0;j<matrix.size();j++)
    {
      if(matrix[j][minCol] < curMax)
      {
        curMax = matrix[j][minCol];
        maxRow = j;
      }
    }
    if (maxRow==i)
    {
      ans.push_back(matrix[maxRow][minCol]);
    }
  }
  return ans;
}

// Method 2: O(m*n) / O(m)
vector<int> luckyNumbers (vector<vector<int>>& matrix)
{
  vector<int> minRows,ans;
  for(int i=0;i<matrix.size();i++)
  {
    minRows.emplace_back(min_element(matrix[i].begin(), matrix[i].end())-
        matrix[i].begin());
  }
  for(int j=0;j<matrix[0].size();j++)
  {
    int curMax=INT_MIN;
    int maxRow=0;
    for(int i=0;i<matrix.size();i++)
    {
      if(curMax<matrix[i][j])
      {
        maxRow=i;
        curMax=matrix[i][j];
      }
    }
    if(j==minRows[maxRow])
      ans.push_back(matrix[maxRow][j]);
  }
  return ans;
}

int main()
{

return 0;
}