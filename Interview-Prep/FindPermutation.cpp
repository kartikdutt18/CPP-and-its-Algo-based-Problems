#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> findPerm(const string A, int B)
{

  vector<int> result;

  int current_smallest = 1;
  int current_largest = B;

  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] == 'I')
    {
      result.push_back(current_smallest);
      current_smallest++;
    }
    else
    {
      result.push_back(current_largest);
      current_largest--;
    }
  }
  result.push_back(current_smallest);
  return result;
}

int main()
{
  return 0;
}