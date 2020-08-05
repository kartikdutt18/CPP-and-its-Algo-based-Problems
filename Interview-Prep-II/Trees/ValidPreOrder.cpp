#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int solve(vector<int> &A)
{
  stack<int> st;
  int curRoot = INT_MIN;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] < curRoot)
    {
      return false;
    }
    while (!st.empty() && st.top() < A[i])
    {
      curRoot = st.top();
      st.pop();
    }

    st.push(A[i]);
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}