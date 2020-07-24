#include <vector>
#include <string>
using namespace std;

int palindromePartitioningMinCuts(string string)
{
  vector<vector<bool>> isPalindrome(string.length(), vector<bool>(string.length(), false));
  for (int i = 0; i < string.length(); i++)
    isPalindrome[i][i] = true;

  for (int length = 2; length <= string.length(); length++)
  {
    for (int i = 0; i < string.length() - length + 1; i++)
    {
      int j = i + length - 1;
      if (length == 2)
        isPalindrome[i][j] = (string[i] == string[j]);
      else
        isPalindrome[i][j] = (string[i] == string[j] && isPalindrome[i + 1][j - 1]);
    }
  }

  vector<int> minCuts(string.length(), INT_MAX);
  for (int i = 0; i < string.length(); i++)
  {
    if (isPalindrome[0][i])
      minCuts[i] = 0;
    else
    {
      minCuts[i] = minCuts[i - 1] + 1;
      for (int j = 1; j < i; j++)
        if (isPalindrome[j][i])
          minCuts[i] = min(minCuts[j - 1] + 1, minCuts[i]);
    }
  }
  return minCuts.back();
}
