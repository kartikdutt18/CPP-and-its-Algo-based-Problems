#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

/**
 * Method 1: Push, Pop, Insert: O(1), O(1), O(k)
 * For q queries : O(k * q)
 */ 
class CustomStack
{
  deque<int> v;
  int index;
  int maxSize;

public:
  CustomStack(int maxSize)
  {
    index = -1;
    this->maxSize = maxSize;
    v = deque<int>(maxSize, 0);
  }

  void push(int x)
  {
    if (index < maxSize - 1)
    {
      index++;
      v[index] = x;
    }
    return;
  }

  int pop()
  {
    if (index == -1)
    {
      return -1;
    }
    int val = v[index];
    index--;
    return val;
  }

  void increment(int k, int val)
  {
    for (int i = 0; i <= min(index, k - 1); i++)
    {
      v[i] += val;
    }
    return;
  }
};
/**
 * Method 2: Lazy increment.
 * O(1), O(1), O(1)
 * inc[i] ==> increment each element between o and i by inc[i].
 */
class CustomStack
{
  vector<int> inc;
  vector<int> stack;
  int maxSize;
 public:
  CustomStack(int maxSize) : maxSize(maxSize){}

  void push(int x)
  {
    if(stack.size()<maxSize)
    {
      stack.push_back(x);
      inc.push_back(0);
    }
  }

  int pop()
  {
    int i = stack.size()-1;
    if(i<0) return -1;
    if(i>0)inc[i-1]+=inc[i];
    int ans = stack[i]+inc[i];
    stack.pop_back();
    inc.pop_back();
    return ans;
  }

  void increment(int k, int val)
  {
    int i = min(k,int(stack.size()))-1;
    if (i>=0) inc[i]+=val;
  }
};

int main() {

return 0;
}