#include <vector>
using namespace std;
void quickSortHelper(vector<int>& array, int start, int end)
{
	if (start >= end)
		return;
	int pivot = start, left = start + 1, right = end;
	while (left <= right)
	{
		if (array[left] > array[pivot] && array[right] < array[pivot])
		{
			swap(array[left], array[right]);
		}
		if (array[left] <= array[pivot])
			left++;
		if (array[right] >= array[pivot])
			right--;
	}
	swap(array[right], array[pivot]);
	quickSortHelper(array, right + 1, end);
	quickSortHelper(array, start, right - 1);
}
vector<int> quickSort(vector<int> array) {
  quickSortHelper(array, 0, array.size() - 1);
  return array;
}

