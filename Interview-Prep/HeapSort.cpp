#include <vector>
#include <queue>
using namespace std;

vector<int> heapSort(vector<int> array)
{
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = array.size() - 1; i >= 0; i--)
  {
    pq.push(array[i]);
    array.pop_back();
  }
  while (!pq.empty())
  {
    array.push_back(pq.top());
    pq.pop();
  }
  return array;
}
