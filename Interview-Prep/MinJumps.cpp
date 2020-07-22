#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array)
{
  if (array.size() == 1)
    return 0;
  int minJumps = 0;
  int maxReach = array[0];
  int steps = array[0];
  for (int i = 1; i < array.size() - 1; i++)
  {
    maxReach = max(maxReach, array[i] + i);
    steps--;
    if (steps == 0)
    {
      minJumps += 1;
      steps = maxReach - i;
    }
  }
  return minJumps + 1;
}
