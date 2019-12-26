//https://leetcode.com/problems/sliding-window-maximum/solution/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    map<int, int> ht;
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (dq.size() == k)
        {
            if (ht.count(dq.front()))
            {
                ht[dq.front()]--;
                if (ht[dq.front()] == 0)
                    ht.erase(dq.front());
            }
            dq.pop_front();
        }
        dq.push_back(nums[i]);
        ht[nums[i]]++;
        auto t = ht.rbegin();
        if (dq.size() == k)
            ans.push_back(t->first);
    }
    return ans;
}
/*
    O(N) Solution

    class Solution:
    def maxSlidingWindow(self, nums: 'List[int]', k: 'int') -> 'List[int]':
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums
        
        left = [0] * n
        left[0] = nums[0]
        right = [0] * n
        right[n - 1] = nums[n - 1]
        for i in range(1, n):
            # from left to right
            if i % k == 0:
                # block start
                left[i] = nums[i]
            else:
                left[i] = max(left[i - 1], nums[i])
            # from right to left
            j = n - i - 1
            if (j + 1) % k == 0:
                # block end
                right[j] = nums[j]
            else:
                right[j] = max(right[j + 1], nums[j])
        
        output = []
        for i in range(n - k + 1):
            output.append(max(left[i + k - 1], right[i]))
            
        return output
*/
