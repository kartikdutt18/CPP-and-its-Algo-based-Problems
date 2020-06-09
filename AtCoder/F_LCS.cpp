#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(string& s1, string& s2)
{
  vector<vector<int>> dp(s1.length() + 1,
      vector<int>(s2.length() + 1, 0));
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  for (size_t i = 1; i <= s1.length(); i++)
  {
    for (size_t j = 1; j <= s2.length(); j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // Print the vector.
  size_t i = s1.length(), j = s2.length();
  string longestSubSeq = "";
  while(i > 0 && j > 0)
  {
    if (s1[i - 1] == s2[j - 1])
    {
      longestSubSeq += s1[i - 1];
      i--;
      j--;
    }
    else if (dp[i][j - 1] <= dp[i - 1][j])
      i--;
    else
      j--;
  }
  
  cout << longestSubSeq << endl;
}

void GetString(string& s)
{
  while (s.length() == 0)
    getline(cin, s);
  return;
}

int main()
{
  string s1, s2;
  GetString(s1);
  GetString(s2);
  solve(s1, s2);
  return 0;
}