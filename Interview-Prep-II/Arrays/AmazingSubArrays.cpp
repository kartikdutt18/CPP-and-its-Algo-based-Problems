#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(string A)
{
  long long ans = 0;
  set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
  for (int i = 0; i < A.length(); i++)
  {
    if (vowels.count(A[i]))
    {
      ans = (ans + (A.length() - i) % 10003) % 10003;
    }
  }
  return ans % 10003;
}

int main()
{
  return 0;
}