#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> GetMax(vector<int> &nums, bool reverse = false)
{
  stack<int> st;
  vector<int> ans(nums.size(), 0);
  int incrementer = reverse ? -1 : 1;
  int i = (reverse ? nums.size() - 1 : 0);
  auto isValid = [&](int k) {
    if (reverse)
      return k >= 0;
    return k < nums.size();
  };

  while (isValid(i))
  {
    cout << i << endl;
    int num = nums[i + incrementer];
    while (!st.empty() && nums[st.top() - 1] <= num)
      st.pop();
    if (st.empty())
      ans[i + incrementer] = 0;
    else
      ans[i + incrementer] = st.top();
    st.push(i + 1);
    i = i + incrementer;
  }
  return ans;
}

int maxSpecialProduct(vector<int> &A)
{
  vector<int> maxLeft = GetMax(A);
  vector<int> maxRight = GetMax(A, true);
  int maxAns = 0;
  for (int i = 0; i < maxLeft.size(); i++)
  {
    maxAns = max(maxAns, ((maxLeft[i] % 1000000007) * (maxRight[i] %
      1000000007)) % 1000000007);
  }
  return maxAns;
}

int main()
{
  return 0;
}