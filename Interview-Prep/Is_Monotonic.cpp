#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> array)
{
  bool increasing = true;
  bool decreasing = true;
  for (int i = 1; i < array.size(); i++)
  {
    increasing = increasing & (array[i] >= array[i - 1]);
    decreasing = decreasing & (array[i] <= array[i - 1]);
  }
  return increasing || decreasing;
}
