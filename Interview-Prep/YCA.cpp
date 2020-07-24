#include <vector>
using namespace std;

class AncestralTree
{
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name)
  {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

int GetDepth(AncestralTree *root, AncestralTree *node)
{
  int depth = 0;
  while (node != root)
  {
    node = node->ancestor;
    depth++;
  }
  return depth;
}

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo)
{
  int depthOf1 = GetDepth(topAncestor, descendantOne);
  int depthOf2 = GetDepth(topAncestor, descendantTwo);
  if (depthOf2 > depthOf1)
  {
    swap(descendantOne, descendantTwo);
    swap(depthOf1, depthOf2);
  }

  while (depthOf1 > depthOf2)
  {
    descendantOne = descendantOne->ancestor;
    depthOf1--;
  }
  while (descendantOne != descendantTwo)
  {
    descendantOne = descendantOne->ancestor;
    descendantTwo = descendantTwo->ancestor;
  }

  return descendantOne;
}
