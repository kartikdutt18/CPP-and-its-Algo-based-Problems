#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
  public:
  // Method 1 : Insert in position.
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
  {
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
      ans.insert(ans.begin() + index[i], nums[i]);
    }
    return ans;
  }
  // Method 2 : NLogN Approach.
  vector<int> createTargetArrayFast(vector<int> nums, vector<int> index)
  {
    
  }
};
int main() {

return 0;
}