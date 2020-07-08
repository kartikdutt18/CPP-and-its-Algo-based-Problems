#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler
{
public:
  double median;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  void insert(int number)
  {
    if (maxHeap.size() == 0 || maxHeap.top() > number)
      maxHeap.push(number);
    else
      minHeap.push(number);
    rebalanceHeaps();
    updateMedian();
  }

  double getMedian() { return median; }

  void rebalanceHeaps()
  {
    if (minHeap.size() - maxHeap.size() == 2)
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
    else if (maxHeap.size() - minHeap.size() == 2)
    {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
  }

  void updateMedian()
  {
    if (minHeap.size() != maxHeap.size())
      median = minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    else
      median = 1.0 * (minHeap.top() + maxHeap.top()) / 2.0;
  }
};

int main()
{
  return 0;
}