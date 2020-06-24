#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

string largestNumber(const vector<int> &A)
{
  vector<int> B;
  for (int num : A)
    B.push_back(num);
  sort(B.begin(), B.end(), [](int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
  });
  string ans = "";
  for (int num : B)
    ans += to_string(num);
  if (ans.length() > 0 && ans[0] == '0')
    return "0";
  return ans;
}

int main() {

return 0;
}