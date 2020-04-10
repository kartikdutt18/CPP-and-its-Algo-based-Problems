#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Second Best Solution : O(NLogN + MlogM) / O(1)
int binarySearch(vector<int> arrayTwo, int target)
{
  int low = 0, high = arrayTwo.size() - 1;
  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (arrayTwo[mid] == target)
      return target;
    if (arrayTwo[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  // Return the minimum of three rather returning mid.
  return arrayTwo[mid];
}
vector<int> smallestDifference2(vector<int> arrayOne, vector<int> arrayTwo)
{
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  vector<int> minPair;
  int minDiff = INT_MAX;
  for (int i = 0; i < arrayOne.size(); i++)
  {
    int target = binarySearch(arrayTwo, arrayOne[i]);
    int curMinDiff = abs(target - arrayOne[i]);
    cout << arrayOne[i] << " " << target << endl;
    if (curMinDiff < minDiff)
    {
      minDiff = curMinDiff;
      minPair = {arrayOne[i], target};
    }
  }
  return minPair;
}

// Best Solution : O(NLogN + MlogM) / O(1)
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());
  int i = 0, j = 0;
  vector<int> minPair;
  int minDiff = INT_MAX;
  while (i < arrayOne.size() && j < arrayTwo.size())
  {
    if (abs(arrayOne[i] - arrayTwo[j]) < minDiff)
    {
      minPair = {arrayOne[i], arrayTwo[j]};
      minDiff = abs(arrayOne[i] - arrayTwo[j]);
    }
    if (arrayOne[i] < arrayTwo[j])
      i++;
    else
      j++;
  }
  return minPair;
}

int main() {

return 0;
}