#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Buckets
{
  bool used = false;
  int maxVal = INT_MIN;
  int minVal = INT_MAX;
};

class Solution
{
public:
  int maximumGap(vector<int> &A)
  {
    if (A.size() < 2)
      return 0;

    int maxElement = *max_element(A.begin(), A.end());
    int minElement = *min_element(A.begin(), A.end());
    int gap = max(1, (maxElement - minElement) / ((int)A.size() - 1));
    int numberOfBuckets = ((maxElement - minElement) / gap) + 1;
    vector<Buckets> buckets(numberOfBuckets);
    for (int num : A)
    {
      int bucketIdx = (num - minElement) / gap;
      buckets[bucketIdx].used = true;
      buckets[bucketIdx].minVal = min(buckets[bucketIdx].minVal, num);
      buckets[bucketIdx].maxVal = max(buckets[bucketIdx].maxVal, num);
    }

    int prevMaxElement = minElement;
    int maxGap = 0;
    for (Buckets &bucket : buckets)
    {
      if (!bucket.used)
        continue;
      maxGap = max(bucket.minVal - prevMaxElement, maxGap);
      prevMaxElement = bucket.maxVal;
    }
    return maxGap;
  }
};

int main()
{  
  return 0;
}