#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> largestRange(vector<int> array)
{
  unordered_map<int, bool> ht;
  for (int num : array)
  {
    ht[num] = false;
  }
  vector<int> posAns;
  for (int num : array)
  {
    if (ht[num])
      continue;
    int j = num - 1;

    while (ht.count(j))
    {
      ht[j] = true;
      j--;
    }
    j++;
    int k = num + 1;
    while (ht.count(k))
    {
      ht[k] = true;
      k++;
    }
    k--;
    if (posAns.empty() || k - j > posAns[1] - posAns[0])
      posAns = {j, k};
    cout << num << " : " << j << " " << k << endl;
  }

  return posAns;
}
