#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> plusOne(vector<int> &A)
{
  deque<int> dq;
  int i = 0;
  while (A[i] == 0)
    i++;
  for (int j = i; j < A.size(); j++)
    dq.push_back(A[j]);
  int j = dq.size() - 1;
  int carry = 1;
  while (j >= 0 && carry)
  {
    int prev = dq[j];
    dq[j] = (dq[j] + carry) % 10;
    carry = (carry + prev) / 10;
    j--;
  }
  if (carry && j < 0)
  {
    dq.push_front(1);
  }
  vector<int> ans;
  for (int num : dq)
    ans.push_back(num);
  return ans;
}


int main() {
  return 0;
}