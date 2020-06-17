#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array)
{
  int startRow = 0, startCol = 0;
  int endRow = array.size() - 1, endCol = array[0].size() - 1;
  vector<int> ans;
  while (startRow <= endRow && startCol <= endCol)
  {
    for (int i = startCol; i <= endCol; i++)
    {
      ans.push_back(array[startRow][i]);
    }
    for (int i = startRow + 1; i <= endRow; i++)
    {
      ans.push_back(array[i][endCol]);
    }
    for (int i = endCol - 1; i >= startCol && (startRow != endRow); i--)
    {
      ans.push_back(array[endRow][i]);
    }
    for (int i = endRow - 1; i > startRow && (startCol != endCol); i--)
    {
      ans.push_back(array[i][startCol]);
    }
    startCol++;
    startRow++;
    endRow--;
    endCol--;
  }

  return ans;
}

int main()
{
  return 0;
}