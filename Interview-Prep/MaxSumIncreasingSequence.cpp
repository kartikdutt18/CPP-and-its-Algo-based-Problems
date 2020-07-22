#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array)
{
  if (!array.size())
    return {{0}, {}};

  vector<int> dp(array.size(), INT_MIN);
  vector<int> sequence(array.size(), -1);
  int ansIdx = 0;
  dp[0] = array[0];
  for (int i = 1; i < array.size(); i++)
  {
    dp[i] = array[i];
    for (int j = i - 1; j >= 0; j--)
    {
      if (array[j] < array[i] && (dp[j] + array[i] > dp[i]))
      {
        dp[i] = dp[j] + array[i];
        sequence[i] = j;
      }
    }

    if (dp[ansIdx] < dp[i])
      ansIdx = i;
  }

  vector<int> maxSequence;
  int maxSum = dp[ansIdx];
  do
  {
    maxSequence.push_back(array[ansIdx]);
    ansIdx = sequence[ansIdx];
  } while (ansIdx >= 0);

  reverse(maxSequence.begin(), maxSequence.end());
  return {
      {maxSum},     // Sum of sequence.
      {maxSequence} // Elements of the sequence.
  };
}
