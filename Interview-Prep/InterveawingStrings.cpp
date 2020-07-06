#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Recursive brute force.
bool helper(string one, int i, string two, int j, string three, int k, string curString)
{
  if (i + j == k && k == three.length())
    return i + j == k && curString == three;
  if (three[k] != one[i] && three[k] != two[j])
    return false;
  if (one[i] == two[j])
    return helper(one, i + 1, two, j, three, k + 1, curString + one[i]) ||
           helper(one, i, two, j + 1, three, k + 1, curString + one[i]);
  if (three[k] == one[i])
    return helper(one, i + 1, two, j, three, k + 1, curString + one[i]);
  return helper(one, i, two, j + 1, three, k + 1, curString + two[j]);
}

// DP.
bool interweavingStrings(string s1, string s2, string s3)
{
  if (s3.length() != s1.length() + s2.length())
    return false;
  vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));

  for (int i = 0; i <= s1.length(); i++)
  {
    for (int j = 0; j <= s2.length(); j++)
    {
      if (i == 0 && j == 0)
        dp[i][j] = 1;
      else if (i == 0)
      {
        if (s2[j - 1] == s3[i + j - 1])
          dp[i][j] = dp[i][j - 1];
      }
      else if (j == 0)
      {
        if (s1[i - 1] == s3[i + j - 1])
          dp[i][j] = dp[i - 1][j];
      }
      else
      {
        if (s3[i + j - 1] == s1[i - 1])
          dp[i][j] = dp[i][j] || dp[i - 1][j];
        if (s3[i + j - 1] == s2[j - 1])
          dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }
  }

  return dp[s1.length()][s2.length()];
}

int main()
{
  return 0;
}