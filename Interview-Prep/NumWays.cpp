#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
  vector<int> numWays(n + 1, 0);
  numWays[0] = 1;
  for (int coin : denoms)
  {
    for (int i = 0; i <= n; i++)
      if (i - coin >= 0)
        numWays[i] += numWays[i - coin];
  }
  return numWays[n];
}
