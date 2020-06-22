#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  bool isSorted = false;
	while(!isSorted)
	{
		int swaps = 0;
		for (int i = 0; i < array.size() - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
				swaps++;
			}
		}
		isSorted = (swaps == 0);
	}
  return array;
}

