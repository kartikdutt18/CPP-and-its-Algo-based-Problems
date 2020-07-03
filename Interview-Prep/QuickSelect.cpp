#include <vector>
using namespace std;

int QuickSortHelper(vector<int> &array, int start, int end, int targetIndex)
{
  if (start > end)
  {
    std::cout << "Hmm, Error!" << std::endl;
    return -1;
  }

  int pivot = start;
  int left = start + 1;
  int right = end;
  while (left <= right)
  {
    if (array[left] > array[pivot] && array[right] < array[pivot])
      swap(array[left], array[right]);
    if (array[left] <= array[pivot])
      left++;
    if (array[pivot] <= array[right])
      right--;
  }
  swap(array[pivot], array[right]);
  if (right == targetIndex)
    return array[right];
  else if (right > targetIndex)
    return QuickSortHelper(array, start, right - 1, targetIndex);
  return QuickSortHelper(array, right + 1, end, targetIndex);
}
int quickselect(vector<int> array, int k)
{
  return QuickSortHelper(array, 0, array.size() - 1, k - 1);
}
