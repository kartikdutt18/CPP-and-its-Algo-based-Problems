#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> ans;
void generateSubset(vector<int> &array, vector<int>& subarray, int startIdx)
{
  ans.push_back(subarray);
  if (startIdx >= array.size())
    return;
  for (int i = startIdx; i < array.size(); i++)
  {
    subarray.push_back(array[i]);
    generateSubset(array, subarray, i + 1);
    subarray.pop_back();
  }
}

vector<vector<int>> powerset(vector<int> array)
{
  vector<int> subarray;
  ans.clear();
  generateSubset(array, subarray, 0);
  return ans;
}

int main()
{
  return 0;
}