#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
  vector<long long> minCoins(n + 1, INT_MAX);
  minCoins[0] = 0;
  for (int i = 0; i <= n; i++)
  {
    for (int coin : denoms)
      if (i - coin >= 0)
        minCoins[i] = min(minCoins[i], minCoins[i - coin] + 1);
  }
  return minCoins[n] == INT_MAX ? -1 : minCoins[n];
}
