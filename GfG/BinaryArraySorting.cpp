#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> SortBinaryArray(vector<int> binArray)
{
  int i = 0;
  int j = binArray.size() - 1;
  while (i < j)
  {
    if (binArray[i] == 1 && binArray[j] == 0)
    {
      swap(binArray[i], binArray[j]);
      j--;
    }
    else if (binArray[i] == 1 && binArray[j] == 1)
    {
      j--;
      continue;
    }
    i++;
  }
  return binArray;
}

int main()
{
  return 0;
}