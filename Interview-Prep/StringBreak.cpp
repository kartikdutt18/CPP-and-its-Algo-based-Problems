#include <vector>
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> numSet;
unordered_map<int, int> cache;

int getMinSpaces(string pi, int i)
{
  if (i == pi.length())
    return -1;
  if (cache.count(i))
    return cache[i];
  int minSpaces = INT_MAX;
  // O(n^2 * k')
  for (int j = i; j < pi.length(); j++)
  {
    string prefix = pi.substr(i, j - i + 1);
    if (numSet.count(prefix))
    {
      int minSpacesInSuffix = getMinSpaces(pi, j + 1);
      if (minSpacesInSuffix == INT_MAX)
        minSpaces = min(minSpaces, minSpacesInSuffix);
      else
        minSpaces = min(minSpaces, minSpacesInSuffix + 1);
    }
  }
  cache.insert({i, minSpaces});
  return cache[i];
}
int numbersInPi(string pi, vector<string> numbers)
{
  numSet.clear();
  cache.clear();
  for (string num : numbers)
    numSet.insert(num);
  // O(n * k)
  for (int i = pi.length() - 1; i >= 0; i--)
    getMinSpaces(pi, i);

  return cache[0] == INT_MAX ? -1 : cache[0];
}
