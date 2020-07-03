#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> prettyPrint(int A)
{
  vector<vector<int>> ans(2 * A - 1, vector<int>(2 * A - 1, 0));
  int startCol = 0, startRow = 0, endCol = 2 * A - 2, endRow = 2 * A - 2;
  while (startCol <= endCol && startRow <= endRow && A > 0)
  {
    for (int i = startCol; i <= endCol; i++)
      ans[startRow][i] = A;
    for (int i = startRow + 1; i <= endRow; i++)
      ans[i][endCol] = A;
    for (int i = endCol - 1; i >= startCol && (startRow != endRow); i--)
      ans[endRow][i] = A;
    for (int i = endRow - 1; i >= startRow && (startCol != endCol); i--)
      ans[i][startCol] = A;
    startCol++;
    startRow++;
    endCol--;
    endRow--;
    A--;
  }
  return ans;
}

int main()
{
  return 0;
}