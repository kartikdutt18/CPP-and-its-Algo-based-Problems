#include <bits/stdc++.h>
using namespace std;

class OrgChart
{
public:
  char name;
  vector<OrgChart *> directReports;

  OrgChart(char name)
  {
    this->name = name;
    this->directReports = {};
  }

  void addDirectReports(vector<OrgChart *> directReports);
};

OrgChart *ans = NULL;
int LCA(OrgChart *root, OrgChart *node1, OrgChart *node2)
{
  if (!root)
    return 0;
  int matches = 0;
  for (OrgChart *child : root->directReports)
  {
    matches += LCA(child, node1, node2);
  }
  if (root == node1 || root == node2)
    matches++;
  if (matches == 2 && ans == NULL)
    ans = root;

  return matches;
}

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne,
                                 OrgChart *reportTwo)
{
  ans = NULL;
  LCA(topManager, reportOne, reportTwo);
  return ans ? ans : topManager;
}
