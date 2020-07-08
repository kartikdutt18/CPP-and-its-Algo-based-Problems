#include <bits/stdc++.h>
using namespace std;

struct ElementDetails
{
  int elementIdx;
  int arrayIdx;
  int val;
  static bool compareElements(ElementDetails &e1, ElementDetails &e2)
  {
    // pq will be sorted in asc order.
    return e1.val >= e2.val;
  }
};

vector<int> mergeSortedArrays(vector<vector<int>> arrays)
{
  priority_queue<ElementDetails, vector<ElementDetails>,
                 decltype(&ElementDetails::compareElements)>
      pq(ElementDetails::compareElements);

  vector<int> ans;
  for (int i = 0; i < arrays.size(); i++)
  {
    pq.push(ElementDetails{0, i, arrays[i][0]});
  }

  while (!pq.empty())
  {
    ElementDetails curElement = pq.top();
    pq.pop();
    ans.push_back(curElement.val);
    if (curElement.elementIdx + 1 < arrays[curElement.arrayIdx].size())
    {
      pq.push(ElementDetails{curElement.elementIdx + 1,
                             curElement.arrayIdx,
                             arrays[curElement.arrayIdx][curElement.elementIdx + 1]});
    }
  }

  return ans;
}
