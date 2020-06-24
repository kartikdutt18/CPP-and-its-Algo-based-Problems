#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int> &A)
{

  sort(A.begin(), A.end());
  int i = 0;
  while (i < A.size() - 1)
  {

    //cout << i << " : " << A[i] << " : " << A.size() - i -1 << std::endl;
    if (A.size() - i - 1 == A[i] && !(A[i] == A[i + 1]))
    {
      return 1;
    }
    i++;
  }
  if (A[A.size() - 1] == 0)
    return 1;
  return -1;
}


int main()
{
  return 0;
}