#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is a list
// or an integer.
int productSum(vector<any> array, int depth = 1)
{
  int ans = 0;
  for (auto element : array)
  {
    if (element.type() == typeid(vector<any>))
    {
      ans += productSum(any_cast<vector<any>>(element), depth + 1);
    }
    else
    {
      ans += any_cast<int>(element);
    }
  }
  return depth * ans;
}
