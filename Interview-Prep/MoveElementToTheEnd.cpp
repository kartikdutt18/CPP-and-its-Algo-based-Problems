#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove)
{
  if (array.size() == 1 || array.size() == 0)
    return array;
  int i = 0, j = 0;
  while (i < array.size() && j < array.size())
  {
    if (array[i] == toMove && array[j] != toMove)
    {
      swap(array[j], array[i]);
      i++;
      j++;
    }
    else if (array[i] == toMove && array[j] == toMove)
    {
      j++;
    }
    else
    {
      i++;
      j = max(j, i);
    }
  }
  return array;
}
