#include <vector>
using namespace std;

void merge(vector<int> &array, int start, int end)
{
  vector<int> sortedArray(end - start + 1, 0);
  int mid = (start + end) / 2;
  int k = 0, i = start, j = mid + 1;
  while (i <= mid && j <= end)
  {
    if (array[i] < array[j])
      sortedArray[k++] = array[i++];
    else
      sortedArray[k++] = array[j++];
  }
  while (i <= mid)
    sortedArray[k++] = array[i++];
  while (j <= end)
    sortedArray[k++] = array[j++];

  for (int i = start; i <= end; i++)
  {
    array[i] = sortedArray[i - start];
  }
}

void mergeSortHelper(vector<int> &array, int start, int end)
{
  if (start >= end)
    return;
  int mid = (start + end) / 2;
  mergeSortHelper(array, start, mid);
  mergeSortHelper(array, mid + 1, end);
  merge(array, start, end);
  return;
}

vector<int> mergeSort(vector<int> array)
{
  mergeSortHelper(array, 0, array.size() - 1);
  return array;
}
