#include <vector>
#include <string>
using namespace std;

int levenshteinDistance(string str1, string str2)
{
  if (str1.length() > str2.length())
    return levenshteinDistance(str2, str1);

  vector<vector<int>> dp(2, vector<int>(str1.length() + 1));
  for (int i = 1; i <= str1.length(); i++)
    dp[0][i] = i;

  for (int i = 1; i <= str2.length(); i++)
  {
    dp[1][0] = i;
    for (int j = 1; j <= str1.length(); j++)
    {
      if (str2[i - 1] == str1[j - 1])
        dp[1][j] = dp[0][j - 1];
      else
        dp[1][j] = min({dp[0][j - 1], dp[1][j - 1], dp[0][j]}) + 1;
    }
    dp[0] = dp[1];
  }
  return dp[0][str1.length()];
}
