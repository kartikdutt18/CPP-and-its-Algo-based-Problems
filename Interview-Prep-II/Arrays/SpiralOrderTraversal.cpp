#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> generateMatrix(int A)
{
  vector<vector<int>> matrix(A, vector<int>(A, 0));
  int curEl = 1;
  int startCol = 0, startRow = 0, endCol = matrix.size() - 1;
  int endRow = matrix[0].size() - 1;
  while (startCol <= endCol && startRow <= endRow)
  {
    for (int i = startCol; i <= endCol; i++)
      matrix[startRow][i] = curEl++;

    for (int i = startRow + 1; i <= endRow; i++)
      matrix[i][endCol] = curEl++;
    for (int i = endCol - 1; i >= startCol && (startRow != endRow); i--)
      matrix[endRow][i] = curEl++;
    for (int i = endRow - 1; i > startRow && (startCol != endCol); i--)
      matrix[i][startCol] = curEl++;
    startCol++;
    endCol--;
    startRow++;
    endRow--;
  }
  return matrix;
}

int main()
{
  return 0;
}