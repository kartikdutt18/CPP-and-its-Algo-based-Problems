#include<bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
  int i = 0;
  int j = 0;
  while (i < array.size() && j < sequence.size())
  {
    if (array[i] == sequence[j])
      j++;
    i++;
  }
  return j == sequence.size();
}
